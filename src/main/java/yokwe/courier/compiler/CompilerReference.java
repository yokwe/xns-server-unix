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

import yokwe.courier.compiler.Compiler.CompilerPair;
import yokwe.courier.compiler.Compiler.Context;
import yokwe.courier.program.Cons;
import yokwe.courier.program.ConsArray;
import yokwe.courier.program.ConsChoice;
import yokwe.courier.program.ConsRecord;
import yokwe.courier.program.ConsReference;
import yokwe.courier.program.Type;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.UnexpectedException;

public class CompilerReference extends CompilerPair {
	@Override
	public void compileType(final Context context, final AutoIndentPrintWriter out, final String name, final Type type) {
//		out.println("// %4d  TYPE  %s  %s", context.decl.line, type.toString(), name);
		var ref = type.toTypeReference().toReferenceType().toTYPE();
		var refName = ref.toQName(context.program.self);
		out.println("using %s = %s;", name, refName);
	}
	@Override
	public void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final Type type, final Cons cons) {
		var typeString = type.toTypeReference().ref.toQName(context.program.self);

		switch(cons) {
		case Cons.Boolean   ut -> compileCons(context, out, name, typeString, ut);
		case Cons.Number    ut -> compileCons(context, out, name, typeString, ut);
		case Cons.String    ut -> compileCons(context, out, name, typeString, ut);

		case ConsArray      ut -> compileCons(context, out, name, typeString, ut);
		case ConsChoice     ut -> compileCons(context, out, name, typeString, ut);
		case ConsRecord     ut -> compileCons(context, out, name, typeString, ut);

		case ConsReference  ut -> compileCons(context, out, name, typeString, ut, type);

		default -> throw new UnexpectedException("Unexpected type");
		}
	}

	private void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final String typeString, final Cons.Boolean cons) {
		out.println("static inline constexpr %s %s = %d;", typeString, name, cons.value ? 1 : 0);
	}
	private void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final String typeString, final Cons.Number cons) {
		out.println("static inline constexpr %s %s = %d;", typeString, name, cons.value);
	}
	private void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final String typeString, final Cons.String cons) {
		out.println("static inline constexpr %s %s = %d;", typeString, name, cons.value);
	}
	private void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final String typeString, final ConsArray cons) {
//		out.println("// %4d  CONS  ARRAY  %s  %s", context.decl.line, typeString, name, cons.kind);
		out.println("static inline const %s %s {  // %d", typeString, name, cons.constList.size());
		for(var e: cons.constList) {
			switch(e) {
			case Cons.Boolean ut -> out.println("%s,", ut.toString());
			case Cons.Number  ut -> out.println("%s,", ut.toString());
			case Cons.String  ut -> out.println("%s,", ut.toString());
			default -> throw new UnexpectedException("Unexpected type");
			}
		}
		out.println("};");
	}
	private void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final String typeString, final ConsChoice cons) {
		out.println("// %4d  CONS  CHOICE %s  %s", context.decl.line, typeString, name, cons.kind); // FIXME
	}
	private void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final String typeString, final ConsRecord cons) {
		out.println("// %4d  CONS  RECORD %s  %s", context.decl.line, typeString, name, cons.kind); // FIXME
	}
	private void compileCons(final Context context, final AutoIndentPrintWriter out, final String name, final String typeString, final ConsReference cons, Type type) {
//		out.println("// %4d  CONS  REF    %s  %s", context.decl.line, typeString, name, cons.kind);
		if (type.isReference() && type.toTypeReference().toReferenceType().value.isEnum()) {
			// special for enum constant
			out.println("static inline const %s %s = %s::%s;", typeString, name, typeString, cons.ref.name);
		} else {
			out.println("static inline const %s %s = %s;", typeString, name, cons.ref.toQName(context.program.self));
		}
	}
}