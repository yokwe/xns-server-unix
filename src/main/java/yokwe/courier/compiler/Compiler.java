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

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Map;
import java.util.stream.Collectors;

import yokwe.courier.program.Cons;
import yokwe.courier.program.Program;
import yokwe.courier.program.Program.Decl;
import yokwe.courier.program.Program.Info;
import yokwe.courier.program.Type;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.UnexpectedException;

public class Compiler {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	public static final String sourceDir = "src/courier";

	public static class Context implements AutoCloseable {
		public final Program               program;
		public final String                name;
		public final Path                  path;
		public final AutoIndentPrintWriter out;

		public Decl decl;

		public Context(final Program program_) {
			program = program_;
			name    = program.self.toName();
			path    = Paths.get("src", "courier", name + ".h");
			out     = new AutoIndentPrintWriter(toOutputStream(path.toFile()));

			decl = null;
		}

		@Override
		public void close() {
			out.close();
		}

		private OutputStream toOutputStream(final File file) {
			 try {
				return new FileOutputStream(file);
			 } catch (FileNotFoundException e) {
				var exceptionName = e.getClass().getSimpleName();
				logger.error("{} {}", exceptionName, e);
				throw new UnexpectedException(exceptionName, e);
			 }
		}
	}


	public void compile(final Program program) {
		try (var context = new Context(program)) {
			var out     = context.out;

			// preamble
			out.printlnRaw(COPYRIGHT_COMMENT);
			out.println(
				"""
				//
				// %s.h
				//

				#pragma once

				#include <string>
				#include <vector>
				#include <array>

				#include "../util/ByteBuffer.h"

				#include "Courier.h"
				""".formatted(context.name));

			{
				var list = program.dependList.stream().map(Info::toName).sorted().collect(Collectors.toList());
				for(var e: list) {
					out.println("#include \"%s.h\"", e);
				}
				out.println();
			}

			out.println("namespace courier::%s {", context.name);

			// process declList
			for(var decl: program.declList) {
				context.decl = decl;
				var compiler = compilerMap.get(decl.type.kind);
				if (decl.isType()) {
					if (containsSelf(context, decl.type, decl.name)) {
						// FIXME
						logger.warn("Contains self  {}", decl.name);
					}
					compiler.compileType(context, out, decl.name, decl.type);
				}
				if (decl.isCons()) {
					compiler.compileCons(context, out, decl.name, decl.type, decl.cons);
				}
				context.decl = null;
			}

			// postamble
			out.println("}");
		}
	}

	private static final String COPYRIGHT_COMMENT =
		"""
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
		 """;

	public static abstract class CompilerPair {
		private static final Map<Type.Kind, String> typeStringMap = Map.ofEntries(
			Map.entry(Type.Kind.BOOLEAN,       CompilerBoolean.TYPE_STRING),
			Map.entry(Type.Kind.CARDINAL,      CompilerCardinal.TYPE_STRING),
			Map.entry(Type.Kind.INTEGER,       CompilerInteger.TYPE_STRING),
			Map.entry(Type.Kind.LONG_CARDINAL, CompilerLongCardinal.TYPE_STRING),
			Map.entry(Type.Kind.LONG_INTEGER,  CompilerLongInteger.TYPE_STRING),
			Map.entry(Type.Kind.STRING,        CompilerString.TYPE_STRING),
			Map.entry(Type.Kind.UNSPECIFIED,   CompilerUnspecified.TYPE_STRING)
		);
		public static String toTypeString(final Program.Info that, final Type type) {
			if (typeStringMap.containsKey(type.kind)) {
				return typeStringMap.get(type.kind);
			}

			if (type.isReference()) {
				return type.toTypeReference().toReferenceType().toQName(that);
			}

			logger.error("Unexpected type");
			logger.error("  type  {}", type.toString());
			throw new UnexpectedException("Unexpected type");
		}

		public abstract void compileType(Context context, AutoIndentPrintWriter out, String name, Type type);
		public abstract void compileCons(Context context, AutoIndentPrintWriter out, String name, Type type, Cons cons);
	}

	public static CompilerPair getCompilerPair(final Type type) {
		return getCompilerPair(type.kind);
	}
	public static CompilerPair getCompilerPair(final Type.Kind kind) {
		return compilerMap.get(kind);
	}

	private static final Map<Type.Kind, CompilerPair> compilerMap = Map.ofEntries(
		Map.entry(Type.Kind.BOOLEAN,       new CompilerBoolean()),
		Map.entry(Type.Kind.CARDINAL,      new CompilerCardinal()),
		Map.entry(Type.Kind.INTEGER,       new CompilerInteger()),
		Map.entry(Type.Kind.LONG_CARDINAL, new CompilerLongCardinal()),
		Map.entry(Type.Kind.LONG_INTEGER,  new CompilerLongInteger()),
		Map.entry(Type.Kind.STRING,        new CompilerString()),
		Map.entry(Type.Kind.UNSPECIFIED,   new CompilerUnspecified()),
		Map.entry(Type.Kind.ARRAY,         new CompilerArray()),
		Map.entry(Type.Kind.CHOICE,        new CompilerChoice()),
		Map.entry(Type.Kind.ENUM,          new CompilerEnum()),
		Map.entry(Type.Kind.ERROR,         new CompilerError()),
		Map.entry(Type.Kind.PROCEDURE,     new CompilerProcedure()),
		Map.entry(Type.Kind.RECORD,        new CompilerRecord()),
		Map.entry(Type.Kind.SEQUENCE,      new CompilerSequence()),
		Map.entry(Type.Kind.REFERENCE,     new CompilerReference())
	);

	public static boolean containsSelf(Context context, Type type, String name) {
		var list = new ArrayDeque<String>();
		var qName = context.program.self.toQName(name);
		list.add(qName);
		return containsSelf(context, type, list);
	}
	private static boolean containsSelf(Context context, Type type, Deque<String> list) {
		if (type.isReference()) {
			var refType = type.toTypeReference().toReferenceType();
			var qName = refType.toName();

			if (list.contains(qName)) {
				return true;
			}

			list.addLast(qName);
			var result = containsSelf(context, refType.value, list);
			list.removeLast();
			if (result) {
				return true;
			}
		}
		if (type.isRecord()) {
			var typeRecord = type.toTypeRecord();
			for(var e: typeRecord.fieldList) {
				if (containsSelf(context, e.type, list)) {
					return true;
				}
			}
		}
		if (type.isChoice()) {
			var typeChoice = type.toTypeChoice();
			if (typeChoice.isAnon()) {
				var typeChoiceAnon = typeChoice.toAnon();
				for(var e: typeChoiceAnon.candidateList) {
					if (containsSelf(context, e.type, list)) {
						return true;
					}
				}
			}
			if (typeChoice.isName()) {
				var typeChoiceName = typeChoice.toName();
				for(var e: typeChoiceName.candidateNameList) {
					if (containsSelf(context, e.type, list)) {
						return true;
					}
				}
			}
		}
		if (type.isSequence()) {
			var typeSequence = type.toTypeSequence();
			if (containsSelf(context, typeSequence.element, list)) {
				return true;
			}
		}
		if (type.isArray()) {
			var typeArray = type.toTypeArray();
			if (containsSelf(context, typeArray.element, list)) {
				return true;
			}
		}
		return false;
	}

}
