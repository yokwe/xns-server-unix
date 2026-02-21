/*******************************************************************************
 * Copyright (c) 2026, Yasuhiro Hasegawa
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

package yokwe.courier.compiler;

import java.util.Collections;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.stream.Collectors;

import yokwe.courier.compiler.Compiler.CompilerDecl;
import yokwe.courier.compiler.Compiler.CompilerPair;
import yokwe.courier.compiler.Compiler.Context;
import yokwe.courier.program.Cons;
import yokwe.courier.program.Program.NameNumberType;
import yokwe.courier.program.Program.NumberName;
import yokwe.courier.program.Type;
import yokwe.courier.program.TypeChoice;
import yokwe.courier.program.TypeEnum;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.UnexpectedException;

public class CompilerChoice extends CompilerPair {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	static boolean findType(TypeChoice type, String qName) {
		return switch(type) {
			case TypeChoice.Anon ut -> findType(ut, qName);
			case TypeChoice.Name ut -> findType(ut, qName);
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	static boolean findType(TypeChoice.Anon type, String qName) {
		var typeList = type.candidateList.stream().map(o -> o.type).toList();
		return findType(typeList, qName);
	}
	static boolean findType(TypeChoice.Name type, String qName) {
		var typeList = type.candidateList.stream().map(o -> o.type).toList();
		return findType(typeList, qName);
	}
	static boolean findType(List<Type> typeList, String qName) {
		for(var type: typeList) {
			if (type.isRecord()) {
				for(var field: type.toTypeRecord().fieldList) {
					if (field.type.isReference()) {
						var myName = field.type.toTypeReference().toReferenceType().toName();
						if (myName.equals(qName)) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	private static class CompileHeader implements CompilerDecl {
		@Override
		public void compileType(Context context, AutoIndentPrintWriter out, String name, Type type) {
			var typeChoice = type.toTypeChoice();

			// Check recursive to self
			{
				var qName = context.program.self.toQName(name);
				if (findType(typeChoice, qName)) {
					logger.warn("Skip for recursive  {}", qName);
					out.println("// Skip for recursive  %s", qName);
					return;
				}
			}

			switch(typeChoice) {
			case TypeChoice.Anon ut -> compileType(context, out, name, ut);
			case TypeChoice.Name ut -> compileType(context, out, name, ut);
			default -> throw new UnexpectedException("Unexpected");
			}
		}

		void compileType(Context context, AutoIndentPrintWriter out, String name, TypeChoice.Anon type) {
			out.println("struct %s {  // CHOICE ANON", name);

			var candidateList = type.candidateList;
			Collections.sort(candidateList);

			// output enum type
			String enumName = "Key";
			{
				TypeEnum anonEnum = new TypeEnum(candidateList.stream().map(o -> new NumberName(o.number, o.name)).toList());
				var compiler = Compiler.getCompilerPair(anonEnum);
				compiler.header.compileType(context, out, enumName, anonEnum);
			}

			// output candidate
			out.println("// output candidate");
			var nameSet = new LinkedHashSet<String>();
			nameSet.add("std::monostate");

			for(var e: candidateList) {
				if (e.type.isRecord() && e.type.toTypeRecord().fieldList.isEmpty()) {
					// std::monostate
				} else if (e.type.isReference()) {
					var myName = e.type.toTypeReference().toReferenceType().toQName(context.program.self);
					nameSet.add(myName);
				} else if (e.type.isConstructedType()) {
					out.println("// %s", e.name);
					var myName = String.format("Choice_%d", e.number);
					var myType = e.type;
					var compiler = Compiler.getCompilerPair(myType);
					compiler.header.compileType(context, out, myName, myType);
					nameSet.add(myName);
				} else {
					var myName = toTypeString(context.program.self, e.type);
					nameSet.add(myName);
				}
			}

			// output enum field
			out.println("Key key;");

			// output variant
			out.println("std::variant<%s> variant;", String.join(", ", nameSet));
			out.println();
			out.println("void read(const ByteBuffer& bb);");
			out.println("void write(ByteBuffer& bb) const;");
			out.println("std::string toString() const;");

			out.println("};");
		}
		void compileType(Context context, AutoIndentPrintWriter out, String name, TypeChoice.Name type) {
			out.println("struct %s {  // CHOICE NAME", name);

			var keyName = type.designator.toTYPE().toQName(context.program.self);
			var numberMap = type.designator.value.toTypeEnum().list.stream().collect(Collectors.toMap(o -> o.name, o -> o.number));

			var candidateList = type.candidateList.stream().map(o -> new NameNumberType(o.name, numberMap.get(o.name), o.type)).collect(Collectors.toList());
			Collections.sort(candidateList);

			// output candidate
			out.println("// output candidate");
			var nameSet = new LinkedHashSet<String>();
			nameSet.add("std::monostate");

			for(var e: candidateList) {
				if (e.type.isRecord() && e.type.toTypeRecord().fieldList.isEmpty()) {
					// std::monostate
				} else if (e.type.isReference()) {
					var myName = e.type.toTypeReference().toReferenceType().toQName(context.program.self);
					nameSet.add(myName);
				} else if (e.type.isConstructedType()) {
					out.println("//  %s", e.name);
					var myName = String.format("Choice_%d", e.number);
					var myType = e.type;
					var compiler = Compiler.getCompilerPair(myType);
					compiler.header.compileType(context, out, myName, myType);
					nameSet.add(myName);
				} else {
					var myName = toTypeString(context.program.self, e.type);
					nameSet.add(myName);
				}
			}

			// output enum field
			out.println("%s key;", keyName);

			// output variant
			out.println("std::variant<%s> variant;", String.join(", ", nameSet));
			out.println();
			out.println("void read(const ByteBuffer& bb);");
			out.println("void write(ByteBuffer& bb) const;");
			out.println("std::string toString() const;");

			out.println("};");
		}


		@Override
		public void compileCons(Context context, AutoIndentPrintWriter out, String name, Type type, Cons cons) {
			out.println("// %4d  CONS  %s  %s", context.decl.line, type.toString(), name); // FIXME
		}
	}
	private static class CompileSource implements CompilerDecl {
		@Override
		public void compileType(Context context, AutoIndentPrintWriter out, String name, Type type) {
			var typeChoice = type.toTypeChoice();

			// Check recursive to self
			{
				var qName = context.program.self.toQName(name);
				if (findType(typeChoice, qName)) {
					logger.warn("Skip for recursive  {}", qName);
					out.println("// Skip for recursive  %s", qName);
					return;
				}
			}

			switch(typeChoice) {
			case TypeChoice.Anon ut -> compileType(context, out, name, ut);
			case TypeChoice.Name ut -> compileType(context, out, name, ut);
			default -> throw new UnexpectedException("Unexpected");
			}
		}
		public void compileType(Context context, AutoIndentPrintWriter out, String name, TypeChoice.Anon type) {
		    out.println("//  CHOICE ANON  %s", name);

		    // output read
			out.println("void %s::read(const ByteBuffer& bb) {", name);
			out.println("bb.read(key); // FIXME");
			// FIXME
			out.println("}");

		    // output write
			out.println("void %s::write(ByteBuffer& bb) const {", name);
			out.println("bb.write(key); // FIXME");
			// FIXME
			out.println("}");

		    // output toString
			out.println("std::string %s::toString() const {", name);
			out.println("return \"\"; // FIXME");
			// FIXME
			out.println("}");
		}
		public void compileType(Context context, AutoIndentPrintWriter out, String name, TypeChoice.Name type) {
		    out.println("//  CHOICE NAME  %s", name);

		    // output read
			out.println("void %s::read(const ByteBuffer& bb) {", name);
			out.println("bb.read(key); // FIXME");
			// FIXME
			out.println("}");

		    // output write
			out.println("void %s::write(ByteBuffer& bb) const {", name);
			out.println("bb.write(key); // FIXME");
			// FIXME
			out.println("}");

		    // output toString
			out.println("std::string %s::toString() const {", name);
			out.println("return \"\"; // FIXME");
			// FIXME
			out.println("}");
		}


		@Override
		public void compileCons(Context context, AutoIndentPrintWriter out, String name, Type type, Cons cons) {
			// TODO Auto-generated method stub
		}
	}

	public CompilerChoice() {
		super(new CompileHeader(), new CompileSource());
	}
}