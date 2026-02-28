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

import yokwe.courier.compiler.Compiler.CompilerPair;
import yokwe.courier.compiler.Compiler.Context;
import yokwe.courier.program.Cons;
import yokwe.courier.program.Type;
import yokwe.courier.util.Util;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.AutoIndentPrintWriter.Layout;

public class CompilerRecord extends CompilerPair {
	@Override
	public void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final Type type) {
//		out.println("// %4d  TYPE  %s  %s", context.decl.line, type.toString(), name);

		var typeRecord = type.toTypeRecord();

		// if record has no field
		if (typeRecord.isEmpty()) {
			out.println("using %s = EMPTY_RECORD;", name);
			return;
		}

		// output record
		out.println("struct %s {", name);

		// output constructed type
		for(var field: typeRecord.fieldList) {
			if (field.type.isConstructedType()) {
				var newName = Util.capitalizeName(field.name);
				var compiler = Compiler.getCompilerPair(field.type);
				compiler.compileType(context, out, newName, field.type);
			}
		}

		// output field
		out.prepareLayout();
		for(var field: typeRecord.fieldList) {
			String fieldTypeString;
			if (field.type.isConstructedType()) {
				fieldTypeString = Util.capitalizeName(field.name);
			} else {
				fieldTypeString = toTypeString(context.program.self, field.type);
			}
			out.println("%s  %s;", fieldTypeString, field.name);
		}
		out.layout(Layout.LEFT, Layout.LEFT);
		out.println();

		// output constructor
		{
			var argList = new ArrayList<String>();
			for(var field: typeRecord.fieldList) {
				var fieldTypeString = toTypeString(context.program.self, field.type, field.name);
				argList.add(String.format("%s %s_", fieldTypeString, field.name));
			}
			List<String> initList = typeRecord.fieldList.stream().map(o -> String.format("%s(%s_)", o.name, o.name)).toList();

			out.println("%s() {}", name);
			out.println("%s(const %s& that) = default;", name, name);
			out.println("%s(%s&& that)      = default;", name, name);
			out.println("%s(%s) : %s {}", name, String.join(", ", argList), String.join(", ", initList));
			out.println();
			out.println("%s& operator=(const %s&)     = default;", name, name);
			out.println("%s& operator=(%s&&) noexcept = default;", name, name);
			out.println();
		}

		// output methods
		var fieldNameArray = typeRecord.fieldList.stream().map(o -> o.name).toArray(String[]::new);
	    var fieldNameListString = String.join(", ", fieldNameArray);

	    // output read
		out.println("inline void read(const ByteBuffer& bb) {");
		out.println("bb.read(%s);", fieldNameListString);
		out.println("}");

		// output write
		out.println("inline void write(ByteBuffer& bb) const {");
		out.println("bb.write(%s);", fieldNameListString);
		out.println("}");

		// output toString
		out.println("inline std::string toString() const {");
		var buf = new StringBuilder();
		for(var i = 0; i < fieldNameArray.length; i++) {
			if (i != 0) {
				buf.append(" + \" \" + ");
			}
			buf.append(String.format("::toString(%s)", fieldNameArray[i]));
		}
		out.println("return \"{\" + %s + \"}\";", buf.toString());
		out.println("}");

		out.println("};");
		out.println();
	}

	@Override
	public void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final Type type, final Cons cons) {
		out.println("// %4d  CONS  %s  %s", context.decl.line, type.toString(), name); // FIXME
	}
}