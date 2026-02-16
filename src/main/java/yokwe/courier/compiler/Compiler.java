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
import yokwe.courier.program.Program.Info;
import yokwe.courier.program.Type;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.UnexpectedException;

public class Compiler {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	// TYPE  name: TYPE = XXX;

	//	// predefined
	//	BOOLEAN, CARDINAL, INTEGER, LONG_CARDINAL, LONG_INTEGER, STRING, UNSPECIFIED,
	//	// constructed
	//	ARRAY, CHOICE, ENUM, ERROR, PROCEDURE, RECORD, SEQUENCE,
	//	// reference
	//	REFERENCE

	// CONS  name: TYPE = XXX

	public static final String sourceDir = "src/courier";

	public static class Context implements AutoCloseable {
		public final Program               program;
		public final String                name;

		public final Path                  pathHeader;
		public final Path                  pathSouce;

		public final AutoIndentPrintWriter outHeader;
		public final AutoIndentPrintWriter outSource;

		public Context(final Program program_) {
			program    = program_;
			name       = program.self.toName();
			pathSouce  = Paths.get("src", "courier", name + ".cpp");
			pathHeader = Paths.get("src", "courier", name + ".h");
			outSource  = new AutoIndentPrintWriter(toOutputStream(pathSouce.toFile()));
			outHeader  = new AutoIndentPrintWriter(toOutputStream(pathHeader.toFile()));
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
		out.println(
			"""
			//
			// %s.h
			//

			#pragma once

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
			if (decl.isType()) {
				compileHeader(context, decl.name, decl.type);
			}
			if (decl.isCons()) {
				compileHeader(context, decl.name, decl.type, decl.cons);
			}
		}

		// postamble
		out.println("}");
	}

	private interface CompileType {
		void compile(Context context, String name, Type type);
	}
	private static Map<Type.Kind, CompileType> headerTypeMap = Map.ofEntries(
			Map.entry(Type.Kind.BOOLEAN,       new HeaderType.BOOLEAN()),
			Map.entry(Type.Kind.CARDINAL,      new HeaderType.CARDINAL()),
			Map.entry(Type.Kind.INTEGER,       new HeaderType.INTEGER()),
			Map.entry(Type.Kind.LONG_CARDINAL, new HeaderType.LONG_CARDINAL()),
			Map.entry(Type.Kind.LONG_INTEGER,  new HeaderType.LONG_INTEGER()),
			Map.entry(Type.Kind.STRING,        new HeaderType.STRING()),
			Map.entry(Type.Kind.UNSPECIFIED,   new HeaderType.UNSPECIFIED()),
			Map.entry(Type.Kind.ARRAY,         new HeaderType.ARRAY()),
			Map.entry(Type.Kind.CHOICE,        new HeaderType.CHOICE()),
			Map.entry(Type.Kind.ENUM,          new HeaderType.ENUM()),
			Map.entry(Type.Kind.ERROR,         new HeaderType.ERROR()),
			Map.entry(Type.Kind.PROCEDURE,     new HeaderType.PROCEDURE()),
			Map.entry(Type.Kind.RECORD,        new HeaderType.RECORD()),
			Map.entry(Type.Kind.SEQUENCE,      new HeaderType.SEQUENCE()),
			Map.entry(Type.Kind.REFERENCE,     new HeaderType.REFERENCE())
	);

	public static class HeaderType {
		public static class BOOLEAN implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class CARDINAL implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class INTEGER implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class LONG_CARDINAL implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class LONG_INTEGER implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class STRING implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class UNSPECIFIED implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class ARRAY implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class CHOICE implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class ENUM implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class ERROR implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class PROCEDURE implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class RECORD implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class SEQUENCE implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
		public static class REFERENCE implements CompileType {
			@Override
			public void compile(final Context context, final String name, final Type type) {
				// FIXME
			}
		}
	}

	public interface CompileCons {
		void compile(Context context, String name, Type type, Cons cons);
	}
	CompileCons a = new HeaderCons.BOOLEAN();
	private static Map<Type.Kind, CompileCons> headerConsMap = Map.ofEntries(
			Map.entry(Type.Kind.BOOLEAN,       new HeaderCons.BOOLEAN()),
			Map.entry(Type.Kind.CARDINAL,      new HeaderCons.CARDINAL()),
			Map.entry(Type.Kind.INTEGER,       new HeaderCons.INTEGER()),
			Map.entry(Type.Kind.LONG_CARDINAL, new HeaderCons.LONG_CARDINAL()),
			Map.entry(Type.Kind.LONG_INTEGER,  new HeaderCons.LONG_INTEGER()),
			Map.entry(Type.Kind.STRING,        new HeaderCons.STRING()),
			Map.entry(Type.Kind.UNSPECIFIED,   new HeaderCons.UNSPECIFIED()),
			Map.entry(Type.Kind.ARRAY,         new HeaderCons.ARRAY()),
			Map.entry(Type.Kind.CHOICE,        new HeaderCons.CHOICE()),
			Map.entry(Type.Kind.ENUM,          new HeaderCons.ENUM()),
			Map.entry(Type.Kind.ERROR,         new HeaderCons.ERROR()),
			Map.entry(Type.Kind.PROCEDURE,     new HeaderCons.PROCEDURE()),
			Map.entry(Type.Kind.RECORD,        new HeaderCons.RECORD()),
			Map.entry(Type.Kind.SEQUENCE,      new HeaderCons.SEQUENCE()),
			Map.entry(Type.Kind.REFERENCE,     new HeaderCons.REFERENCE())
	);

	public static class HeaderCons {
		public static class BOOLEAN implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class CARDINAL implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class INTEGER implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class LONG_CARDINAL implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class LONG_INTEGER implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class STRING implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class UNSPECIFIED implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class ARRAY implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class CHOICE implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class ENUM implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class ERROR implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class PROCEDURE implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class RECORD implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class SEQUENCE implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// FIXME
			}
		}
		public static class REFERENCE implements CompileCons {
			@Override
			public void compile(final Context context, final String name, final Type type, final Cons cons) {
				// TODO Auto-generated method stub
			}
		}
	}


	void compileHeader(final Context context, final String name, final Type type) {
		var compiler = headerTypeMap.get(type.kind);
		compiler.compile(context, name, type);
	}
	void compileHeader(final Context context, final String name, final Type type, final Cons cons) {
		var compiler = headerConsMap.get(type.kind);
		compiler.compile(context, name, type, cons);
	}


	void compileSource(final Context context) {
		var program = context.program;
		var out     = context.outSource;

		// preamble
		out.println(
			"""
			//
			// %s.cpp
			//

			#include "%s.h"
			""".formatted(context.name, context.name));
		out.println("namespace courier::%s {", context.name);

		// process declList
		for(var decl: program.declList) {
			if (decl.isType()) {
				compileSource(context, decl.name, decl.type);
			}
			if (decl.isCons()) {
				compileSource(context, decl.name, decl.type, decl.cons);
			}
		}

		// postamble
		out.println("}");
	}
	void compileSource(final Context context, final String name, final Type type) {
		// FIXME
	}
	void compileSource(final Context context, final String name, final Type type, final Cons cons) {
		// FIXME
	}

}
