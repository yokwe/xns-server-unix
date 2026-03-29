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

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import yokwe.courier.compiler.Compiler.CompilerPair;
import yokwe.courier.compiler.Compiler.Context;
import yokwe.courier.program.Cons;
import yokwe.courier.program.Program.NameType;
import yokwe.courier.program.Program.NumberName;
import yokwe.courier.program.Type;
import yokwe.courier.program.TypeChoice;
import yokwe.courier.program.TypeEnum;
import yokwe.courier.util.Util;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.AutoIndentPrintWriter.Layout;
import yokwe.util.UnexpectedException;

public class CompilerChoice extends CompilerPair {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	@Override
	public void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final Type type) {
		var typeChoice = type.toTypeChoice();
		switch(typeChoice) {
		case TypeChoice.Anon ut -> compileType(context, out, name, ut);
		case TypeChoice.Name ut -> compileType(context, out, name, ut);
		default -> throw new UnexpectedException("Unexpected");
		}
	}

	private void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final TypeChoice.Anon type) {
		out.println("struct %s {  // CHOICE ANON  %s", name, context.decl.name);

		// output enum type
		var enumTypeName = "Key";
		{
			var list = new ArrayList<NumberName>();
			for(var e: type.candidateList) {
				list.addAll(e.designatorList);
			}

			var anonEnum = new TypeEnum(list);
			var compiler = Compiler.getCompilerPair(anonEnum);
			compiler.compileType(context, out, enumTypeName, anonEnum);
		}

		var choiceList    = toChoiceList(type.candidateList.stream().map(o -> o.type).toList());
		var candidateList = toCandidateListAnon(context, type);
		outputBody(context, out, name, enumTypeName, choiceList, candidateList);

		out.println("};");
		out.println();
	}

	private void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final TypeChoice.Name type) {
		out.println("struct %s {  // CHOICE NAME  %s", name, context.decl.name);

		var enumTypeName = type.designator.toQName(context.program.self);

		var choiceList    = toChoiceList(type.candidateNameList.stream().map(o -> o.type).toList());
		var candidateList = toCandidateListName(context, type);
		outputBody(context, out, name, enumTypeName, choiceList, candidateList);

		out.println("};");
		out.println();
	}

	private void outputBody(final Context context, final AutoIndentPrintWriter out, final String choiceName, final String enumTypeName, List<NameType> choiceList, final List<Candidate> candidateList) {
		out.prepareLayout();
		out.println("// number name, typeName");
		for(var e: candidateList) {
			out.println("// %d %s %s", e.number, e.name, e.typeName);
		}
		out.layout(Layout.LEFT, Layout.RIGHT, Layout.LEFT, Layout.LEFT);
		out.println();


		// compile constructed type in candidateList
		compileChoice(context, out, choiceList);

		// output enum field
		out.println("%s key;", enumTypeName);

		// output variables and methods
		out.println("std::variant<%s> variant;", String.join(", ", candidateList.stream().map(o -> o.typeName).toList()));
		out.println();

		// output constructor for each candidate
		out.println("// fromXXX()");
		for(int i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			var myName     = candidate.name;
			var myTypeName = candidate.typeName;

			if (myTypeName.equals("std::monostate")) {
				out.println("static %s from%s() {", choiceName, Util.capitalizeName(myName));
				out.println("%s ret;", choiceName);
				out.println("ret.key = %s::%s;", enumTypeName, Util.sanitizeSymbol(myName));
				out.println("ret.variant.emplace<%d>(std::monostate{}); // Empty record  %s", i, myName);
			} else {
				out.println("static %s from%s(%s value) {", choiceName, Util.capitalizeName(myName), myTypeName);
				out.println("%s ret;", choiceName);
				out.println("ret.key = %s::%s;", enumTypeName, Util.sanitizeSymbol(myName));
				out.println("ret.variant.emplace<%d>(value);", i, myTypeName);
			}
			out.println("return ret;");
			out.println("}");
		}
		out.println();

		// output toXXX method for each candidate
		out.println("// toXXX");
		for(int i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			var myName     = candidate.name;
			var myTypeName = candidate.typeName;

			if (myTypeName.equals("std::monostate")) {
				//
			} else {
				out.println("%s to%s() {", myTypeName, Util.capitalizeName(myName));
				out.println("return std::get<%d>(variant);", i);
				out.println("}");
			}
		}
		out.println();


		// create typeNameList and output mapping of enum and type
	    // output read
		out.println("inline void read(const ByteBuffer& bb) {");
		out.println("bb.read(key);");
		out.println("switch(key) {");
		for(int i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			var myName     = candidate.name;
			var myTypeName = candidate.typeName;

			out.println("case %s::%s:", enumTypeName, Util.sanitizeSymbol(myName));
			if (myTypeName.equals("std::monostate")) {
				out.println("variant.emplace<%d>(std::monostate{}); // Empty record  %s", i, myName);
			} else {
				out.println("variant.emplace<%d>(bb.get<%s>());", i, myTypeName);
			}
			out.println("break;");
		}
		out.println("default: ERROR()");
		out.println("}");
		out.println("}");

	    // output write
		out.println("inline void write(ByteBuffer& bb) const {");
		out.println("bb.write(key);");
		out.println("switch(key) {");
		for(int i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			var myName     = candidate.name;
			var myTypeName = candidate.typeName;

			out.println("case %s::%s:", enumTypeName, Util.sanitizeSymbol(myName));
			if (myTypeName.equals("std::monostate")) {
				out.println("// Empty record  %s", myName);
			} else {
				out.println("bb.write(std::get<%d>(variant));", i);
			}
			out.println("break;");
		}
		out.println("default: ERROR()");
		out.println("}");
		out.println("}");

	    // output toString
		out.println("inline std::string toString() const {");
		out.println("switch(key) {");
		for(int i = 0; i < candidateList.size(); i++) {
			var candidate  = candidateList.get(i);
			var myName     = candidate.name;
			var myTypeName = candidate.typeName;

			out.println("case %s::%s:", enumTypeName, Util.sanitizeSymbol(myName));
			if (myTypeName.equals("std::monostate")) {
				out.println("return \"{%s  {}}\";", myName);
			} else {
				out.println("return \"{%s  \" + ::toString((%s)std::get<%d>(variant)) + \"}\"; ", myName, myTypeName, i);
			}
		}
		out.println("default: ERROR()");
		out.println("}");
		out.println("}");
	}

	@Override
	public void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final Type type, final Cons cons) {
		out.println("// %4d  CONS  %s  %s", context.decl.line, type.toString(), name);
	}

	private static List<NameType> toChoiceList(final List<Type> typeList) {
		var ret = new ArrayList<NameType>();
		int choiceIndex = 0;
		for(var type: typeList) {
			if (type.isRecord() && type.toTypeRecord().isEmpty()) {
				continue;
			}
			if (type.isConstructedType()) {
				var name = String.format("Choice_%d", choiceIndex++);
				ret.add(new NameType(name, type));
			}
		}
		return ret;
	}


	private static class Candidate {
		final String name;
		final int    number;
		final String typeName;

		public Candidate(String name_, int number_, String typeName_) {
			name = name_;
			number = number_;
			typeName = typeName_;
		}

		@Override
		public String toString() {
			return String.format("{%s  %d  %s}", name, number, typeName);
		}
	}

	private static List<Candidate> toCandidateListAnon(Context context, final TypeChoice.Anon typeChoiceAnon) {
		var ret = new ArrayList<Candidate>();

		int choiceIndex = 0;
		for(var candidate: typeChoiceAnon.candidateList) {
			var type = candidate.type;

			String typeName;
			if (type.isRecord() && type.toTypeRecord().isEmpty()) {
				typeName = "std::monostate";
			} else if (type.isReference()) {
				typeName = type.toTypeReference().toReferenceType().toQName(context.program.self);
			} else if (type.isConstructedType()) {
				typeName = String.format("Choice_%d", choiceIndex++);
			} else {
				typeName = toTypeString(context.program.self, type);
			}

			for(var designator: candidate.designatorList) {
				var name   = designator.name;
				var number = designator.number;

				ret.add(new Candidate(name, number, typeName));
			}
		}

		return ret;
	}
	private static List<Candidate> toCandidateListName(Context context, final TypeChoice.Name typeChoiceName) {
		var ret = new ArrayList<Candidate>();

		var enumMap = typeChoiceName.designator.value.toTypeEnum().list.stream().collect(Collectors.toMap(o -> o.name, o -> o.number));

		int choiceIndex = 0;
		for(var candidate: typeChoiceName.candidateNameList) {
			var type = candidate.type;

			String typeName;
			if (type.isRecord() && type.toTypeRecord().isEmpty()) {
				typeName = "std::monostate";
			} else if (type.isReference()) {
				typeName = type.toTypeReference().toReferenceType().toQName(context.program.self);
			} else if (type.isConstructedType()) {
				typeName = String.format("Choice_%d", choiceIndex++);
			} else {
				typeName = toTypeString(context.program.self, type);
			}

			for(var name: candidate.nameList) {
				if (enumMap.containsKey(name)) {
					int number = enumMap.get(name);
					ret.add(new Candidate(name, number, typeName));
				} else {
					logger.error("Unexpected name");
					logger.error("  name  {}", name);
					throw new UnexpectedException("Unexpected name");
				}
			}
		}

		return ret;
	}

	private static void compileChoice(final Context context, final AutoIndentPrintWriter out, final List<NameType> choiceList) {
		for(var choice: choiceList) {
			var compiler = Compiler.getCompilerPair(choice.type);
			compiler.compileType(context,  out, choice.name, choice.type);
		}
	}
}