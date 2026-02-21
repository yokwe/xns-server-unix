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
import yokwe.courier.program.TypeEnum;
import yokwe.courier.util.Util;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.AutoIndentPrintWriter.Layout;

public class CompilerEnum extends CompilerPair {
	private static class CompileHeader implements CompilerDecl {
		@Override
		public void compileType(Context context, AutoIndentPrintWriter out, String name, Type type) {
//			out.println("// %4d  TYPE  %s  %s", context.decl.line, type.toString(), name);

			var typeEnum = type.toTypeEnum();
		    out.println("//  %s", name);
			out.println("enum class %s : uint16_t {", name);
			out.prepareLayout();
			for(var e: typeEnum.list) {
				out.println("%s = %d,", Util.sanitizeSymbol(e.name), e.number);
			}
			out.layout(Layout.LEFT, Layout.LEFT, Layout.RIGHT);
			out.println("};");
			out.println("std::string toString(%s);", name);
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
		    out.println("//  %s", name);
			compileToString(out, name, type.toTypeEnum());
		}
		@Override
		public void compileCons(Context context, AutoIndentPrintWriter out, String name, Type type, Cons cons) {
			// TODO Auto-generated method stub
		}
	}

	public CompilerEnum() {
		super(new CompileHeader(), new CompileSource());
	}

	private static void compileToString(AutoIndentPrintWriter out, String name, TypeEnum typeEnum) {
		out.println("std::string toString(%s value) {", name);
		out.println("static std::unordered_map<%s, std::string, ScopedEnumHash> map = {", name);
		out.prepareLayout();
		for(var e: typeEnum.list) {
			out.println("{%s::%s, \"%d\"},", name, Util.sanitizeSymbol(e.name), e.number);
		}
		out.layout(Layout.LEFT, Layout.RIGHT);
		out.println("};");
		out.println("return map.contains(value) ? map[value] : std_sprintf(\"%d\", std::to_underlying(value));");
		out.println("};");
		out.println();
	}
}