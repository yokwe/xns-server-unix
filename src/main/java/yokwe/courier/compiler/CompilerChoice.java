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
import java.util.Map;
import java.util.stream.Collectors;

import yokwe.courier.compiler.Compiler.CompilerPair;
import yokwe.courier.compiler.Compiler.Context;
import yokwe.courier.program.Cons;
import yokwe.courier.program.Program.NameNumberType;
import yokwe.courier.program.Program.NumberName;
import yokwe.courier.program.Type;
import yokwe.courier.program.TypeChoice;
import yokwe.courier.program.TypeEnum;
import yokwe.courier.util.Util;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.AutoIndentPrintWriter.Layout;
import yokwe.util.UnexpectedException;

public class CompilerChoice extends CompilerPair {
//	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	@Override
	public void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final Type type) {
		var typeChoice = type.toTypeChoice();
		switch(typeChoice) {
		case TypeChoice.Anon ut -> compileType(context, out, name, ut);
		case TypeChoice.Name ut -> compileType(context, out, name, ut);
		default -> throw new UnexpectedException("Unexpected");
		}
	}

	void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final TypeChoice.Anon type) {
		out.println("struct %s {  // CHOICE ANON", name);

		// output enum type
		var enumName = "Key";
		{
			var list = new ArrayList<NumberName>();
			for(var e: type.candidateList) {
				list.addAll(e.designatorList);
			}

			var anonEnum = new TypeEnum(list);
			var compiler = Compiler.getCompilerPair(anonEnum);
			compiler.compileType(context, out, enumName, anonEnum);
		}

		var candidateList = toCandidateList(type);

		outputBody(context, out, enumName, candidateList);

		out.println("};");
	}

	private void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final TypeChoice.Name type) {
		out.println("struct %s {  // CHOICE NAME", name);

		var enumName = type.designator.toQName(context.program.self);
		var candidateList = toCandidateList(type);

		outputBody(context, out, enumName, candidateList);

		out.println("};");
	}

	private void outputBody(final Context context, final AutoIndentPrintWriter out, final String enumName, final List<NameNumberType> candidateList) {
		// create typeNameList and output mapping of enum and type
		var typeNameList = toTypeNameList(context, out, candidateList);

		// compile constructed type in candidateList
		compileConsructedType(context, out, candidateList);

		// output enum field
		out.println("%s key;", enumName);

		// output variables and methods
		out.println("std::variant<%s> variant;", String.join(", ", typeNameList));
		out.println();

		// create typeNameList and output mapping of enum and type
	    // output read
		out.println("inline void read(const ByteBuffer& bb) {");
		out.println("bb.read(key);");
		out.println("switch(key) {");
		for(var i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);

			var myName = candidate.name;
			var myTypeName = typeNameList.get(i);

			out.println("case %s::%s: {", enumName, Util.sanitizeSymbol(candidate.name));
			if (myTypeName.equals("std::monostate")) {
				out.println("variant.emplace<%d>(std::monostate{}); // Empty record  %s", i, myName);
			} else {
				out.println("%s value;", myTypeName);
				out.println("bb.read(value);");
				out.println("variant.emplace<%d>(value);", i);
			}
			out.println("}");
			out.println("break;");
		}
		out.println("default: ERROR()");
		out.println("}");
		out.println("}");

	    // output write
		out.println("inline void write(ByteBuffer& bb) const {");
		out.println("bb.write(key);");
		out.println("switch(key) {");
		for(var i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			var myName    = candidate.name;

			out.println("case %s::%s: {", enumName, Util.sanitizeSymbol(myName));
			if (candidate.type.isRecord() && candidate.type.toTypeRecord().isEmpty()) {
				out.println("// Empty record  %s", myName);
			} else {
				out.println("auto value = std::get<%d>(variant);", i);
				out.println("bb.write(value);");
			}
			out.println("}");
			out.println("break;");
		}
		out.println("default: ERROR()");
		out.println("}");
		out.println("}");

	    // output toString
		out.println("inline std::string toString() const {");
		out.println("switch(key) {");
		for(var i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			var myName   = candidate.name;

			out.println("case %s::%s: {", enumName, Util.sanitizeSymbol(myName));
			if (candidate.type.isRecord() && candidate.type.toTypeRecord().isEmpty()) {
				out.println(String.format("return \"{%s  {}}\";", myName));
			} else {
				out.println("auto value = std::get<%d>(variant);", i);
				out.println(String.format("return \"{%s  \" + ::toString(value) + \"}\";", myName));
			}
			out.println("}");
			out.println("break;");
		}
		out.println("default: ERROR()");
		out.println("}");
		out.println("}");
	}

	@Override
	public void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final Type type, final Cons cons) {
		out.println("// %4d  CONS  %s  %s", context.decl.line, type.toString(), name);
	}

	private static List<NameNumberType> toCandidateList(final TypeChoice.Name typeChoiceName) {
		Map<String, Integer> map = typeChoiceName.designator.value.toTypeEnum().list.stream().collect(Collectors.toMap(o -> o.name, o -> o.number));

		var ret = new ArrayList<NameNumberType>();

		for(var e: typeChoiceName.candidateNameList) {
			var type = e.type;
			for(var ee: e.nameList) {
				var name = ee;
				var number = map.get(name);

				ret.add(new NameNumberType(name, number, type));
			}
		}

		return ret;
	}
	private static List<NameNumberType> toCandidateList(final TypeChoice.Anon typeChoiceAnon) {
		var ret = new ArrayList<NameNumberType>();

		for(var e: typeChoiceAnon.candidateList) {
			var type = e.type;
			for(var ee: e.designatorList) {
				var name   = ee.name;
				var number = ee.number;

				ret.add(new NameNumberType(name, number, type));
			}
		}

		return ret;
	}

	private static List<String> toTypeNameList(final Context context, final AutoIndentPrintWriter out, final List<NameNumberType> candidateList) {
		var typeNameList = new ArrayList<String>();
		for(var i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			if (candidate.type.isRecord() && candidate.type.toTypeRecord().isEmpty()) {
				typeNameList.add("std::monostate");
			} else if (candidate.type.isReference()) {
				var typeName = candidate.type.toTypeReference().toReferenceType().toQName(context.program.self);
				typeNameList.add(typeName);
			} else if (candidate.type.isConstructedType()) {
				var typeName = String.format("Choice_%d", i);
				typeNameList.add(typeName);
			} else {
				var myName = toTypeString(context.program.self, candidate.type);
				typeNameList.add(myName);
			}
		}

		// output choice and type
		out.prepareLayout();
		out.println("// number name type");
		for(var i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);
			out.println("//  %d  %s  %s", i, candidate.name, typeNameList.get(i));
		}
		out.layout(Layout.LEFT, Layout.RIGHT, Layout.LEFT, Layout.LEFT);
		out.println();

		return typeNameList;
	}

	private static void compileConsructedType(final Context context, final AutoIndentPrintWriter out, final List<NameNumberType> candidateList) {
		for(var i = 0; i < candidateList.size(); i++) {
			var candidate = candidateList.get(i);

			if (candidate.type.isRecord() && candidate.type.toTypeRecord().isEmpty()) {
				//
			} else if (candidate.type.isConstructedType()) {
				var typeName = String.format("Choice_%d", i);
				var myType = candidate.type;
				var compiler = Compiler.getCompilerPair(myType);
				compiler.compileType(context, out, typeName, myType);
			}
		}
	}
}