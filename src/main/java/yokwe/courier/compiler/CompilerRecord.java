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

import yokwe.courier.compiler.Compiler.CompilerDecl;
import yokwe.courier.compiler.Compiler.CompilerPair;
import yokwe.courier.compiler.Compiler.Context;
import yokwe.courier.program.Cons;
import yokwe.courier.program.Type;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.AutoIndentPrintWriter.Layout;

public class CompilerRecord extends CompilerPair {
	private static String newName(String name) {
		var firstLetter = name.substring(0, 1);
		var firstLetterNew = firstLetter.toUpperCase();
		if (firstLetterNew.equals(firstLetter)) {
			return name + "_";
		} else {
			return firstLetterNew + name.substring(1);
		}
	}
	private static class CompileHeader implements CompilerDecl {
		@Override
		public void compileType(Context context, AutoIndentPrintWriter out, String name, Type type) {
//			out.println("// %4d  TYPE  %s  %s", context.decl.line, type.toString(), name);

			var typeRecord = type.toTypeRecord();
			if (typeRecord.fieldList.isEmpty()) {
				out.println("using %s = EMPTY_RECORD;", name);
				return;
			}

			// output record
			out.println("struct %s {", name);

			// output constructed type
			for(var field: typeRecord.fieldList) {
				if (field.type.isConstructedType()) {
					var newName = newName(field.name);
					var compiler = Compiler.getCompilerPair(field.type);
					compiler.header.compileType(context, out, newName, field.type);
				}
			}

			// output field
			out.prepareLayout();
			for(var field: typeRecord.fieldList) {
				String fieldTypeString;
				if (field.type.isConstructedType()) {
					fieldTypeString = newName(field.name);
				} else {
					fieldTypeString = toTypeString(context.program.self, field.type);
				}
				out.println("%s  %s;", fieldTypeString, field.name);
			}
			out.layout(Layout.LEFT, Layout.LEFT);
			out.println();

			// output methods
			out.println("void read(const ByteBuffer& bb);");
			out.println("void write(ByteBuffer& bb) const;");
			out.println("std::string toString() const;");
			out.println("};");
			out.println();
		}
		@Override
		public void compileCons(Context context, AutoIndentPrintWriter out, String name, Type type, Cons cons) {
			out.println("// %4d  CONS  %s  %s", context.decl.line, type.toString(), name); // FIXME
		}
	}
	private static class CompileSource implements CompilerDecl {
		@Override
		public void compileType(Context context, AutoIndentPrintWriter out, String name, Type type) {
			var typeRecord = type.toTypeRecord();
			if (typeRecord.fieldList.isEmpty()) {
				return;
			}

			String[] fieldNameArray = typeRecord.fieldList.stream().map(o -> o.name).toArray(String[]::new);
		    var fieldNameListString = String.join(", ", fieldNameArray);

			// output constructed type
			for(var field: typeRecord.fieldList) {
				if (field.type.isConstructedType()) {
					var newName = name + "::" + newName(field.name);
					var compiler = Compiler.getCompilerPair(field.type);
					compiler.source.compileType(context, out, newName, field.type);
				}
			}

		    out.println("//  %s", name);

		    // output read
			out.println("void %s::read(const ByteBuffer& bb) {", name);
			out.println("bb.read(%s);", fieldNameListString);
			out.println("}");

			// output write
			out.println("void %s::write(ByteBuffer& bb) const {", name);
			out.println("bb.write(%s);", fieldNameListString);
			out.println("}");

			// output toString
			out.println("std::string %s::toString() const {", name);
			var buf = new StringBuilder();
			for(int i = 0; i < fieldNameArray.length; i++) {
				if (i != 0) {
					buf.append(" + \" \" + ");
				}
				buf.append(String.format("::toString(%s)", fieldNameArray[i]));
			}
			out.println("return \"{\" + %s + \"}\";", buf.toString());
			out.println("}");
			out.println();
		}
		@Override
		public void compileCons(Context context, AutoIndentPrintWriter out, String name, Type type, Cons cons) {
			// TODO Auto-generated method stub
		}
	}

	public CompilerRecord() {
		super(new CompileHeader(), new CompileSource());
	}
}