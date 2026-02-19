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

		public final Path                  pathHeader;
		public final Path                  pathSouce;

		public final AutoIndentPrintWriter outHeader;
		public final AutoIndentPrintWriter outSource;

		public Decl decl;

		public Context(final Program program_) {
			program    = program_;
			name       = program.self.toName();
			pathSouce  = Paths.get("src", "courier", name + ".cpp");
			pathHeader = Paths.get("src", "courier", name + ".h");
			outSource  = new AutoIndentPrintWriter(toOutputStream(pathSouce.toFile()));
			outHeader  = new AutoIndentPrintWriter(toOutputStream(pathHeader.toFile()));

			decl = null;
		}

		@Override
		public void close() {
			outSource.close();
			outHeader.close();
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
			compileHeader(context);
			compileSource(context);
		}
	}

	void compileHeader(final Context context) {
		var program = context.program;
		var out     = context.outHeader;

		// preamble
		out.printlnRaw(COPYRIGHT_COMMENT);
		out.println(
			"""
			//
			// %s.h
			//

			#pragma once

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
			var compiler = compilerMap.get(decl.type.kind).header;
			if (decl.isType()) {
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


	void compileSource(final Context context) {
		var program = context.program;
		var out     = context.outSource;

		// preamble
		out.printlnRaw(COPYRIGHT_COMMENT);
		out.println(
			"""
			//
			// %s.cpp
			//

			#include "../util/Util.h"
			static const Logger logger(__FILE__);

			#include "%s.h"
			""".formatted(context.name, context.name));
		out.println("namespace courier::%s {", context.name);

		// process declList
		for(var decl: program.declList) {
			context.decl = decl;
			var compiler = compilerMap.get(decl.type.kind).source;
			if (decl.isType()) {
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

	public interface CompilerDecl {
		public void compileType(Context context, AutoIndentPrintWriter out, String name, Type type);
		public void compileCons(Context context, AutoIndentPrintWriter out, String name, Type type, Cons cons);
	}

	public static class CompilerPair {
		public final CompilerDecl header;
		public final CompilerDecl source;

		public CompilerPair(CompilerDecl header_, CompilerDecl source_) {
			header = header_;
			source = source_;
		}
	}

	public static CompilerPair getCompilerPair(Type type) {
		return compilerMap.get(type.kind);
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
}
