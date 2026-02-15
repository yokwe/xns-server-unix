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

package yokwe.courier.program;

import java.util.ArrayList;
import java.util.List;

import yokwe.util.ToString;
import yokwe.util.UnexpectedException;

public class Program implements Comparable<Program> {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	public static class Info implements Comparable<Info> {
		final String name;
		final int    program;
		final int    version;

		public Info(final String name, final int program, final int version) {
			this.name    = name;
			this.program = program;
			this.version = version;
		}
		public Info(final String name, final String program, final String version) {
			this(name, Util.parseInt(program), Util.parseInt(version));
		}

		@Override
		public boolean equals(final Object o) {
			if (o instanceof Info that) {
				return program == that.program && version == that.version;
			}
			return false;
		}
		@Override
		public int compareTo(final Info that) {
			var ret = program - that.program;
			if (ret == 0) {
				ret = version - that.version;
			}
			if (ret == 0) {
				ret = name.compareTo(that.name);
			}
			return ret;
		}

		@Override
		public String toString() {
			return ToString.withFieldName(this);
		}

		public String toName() {
			return version == 0 ? name : String.format("%s%d", name, version);
		}
		public String toName(final String myName) {
			return String.format("%s.%s", toName(), myName);
		}
	}

	public static class Decl {
		public enum Kind {TYPE, CONS}

		public final Kind   kind;
		public final String name;
		public final Type   type;
		public final Cons   cons;

		public Decl(final String name, final Type type) {
			kind = Kind.TYPE;
			this.name = name;
			this.type = type;
			cons = null;
		}
		public Decl(final String name, final Type type, final Cons cons) {
			kind = Kind.CONS;
			this.name = name;
			this.type = type;
			this.cons = cons;
		}

		@Override
		public String toString() {
			if (kind == Kind.TYPE) {
				return String.format("{%s  %s  %s}", kind, name, type);
			}
			if (kind == Kind.CONS) {
				return String.format("{%s  %s  %s  %s}", kind, name, type, cons);
			}
			throw new UnexpectedException("Unexpected");
		}

		public boolean isType() {
			return kind == Kind.TYPE;
		}
		public boolean isCons() {
			return kind == Kind.CONS;
		}
	}

	// name number
	public static class NumberName {
		public final int    number;
		public final String name;

		public NumberName(final int number, final String name) {
			this.number = number;
			this.name   = name;
		}

		@Override
		public String toString() {
			return String.format("{%s  %d}", name, number);
		}
	}

	// name number type
	public static class NameNumberType {
		public final String name;
		public final int    number;
		public final Type   type;

		public NameNumberType(final String name, final int number, final Type type) {
			this.name   = name;
			this.number = number;
			this.type   = type;
		}

		@Override
		public String toString() {
			return String.format("{%s  %d  %s}", name, number, type.toString());
		}
	}

	// name type
	public static class NameType {
		public final String name;
		public final Type   type;
		public NameType(final String name, final Type type) {
			this.name = name;
			this.type = type;
		}

		@Override
		public String toString() {
			return String.format("{%s  %s}", name, type.toString());
		}
	}

	// name cons
	public static class NameCons {
		public final String name;
		public final Cons   cons;
		public NameCons(final String name, final Cons cons) {
			this.name = name;
			this.cons = cons;
		}

		@Override
		public String toString() {
			return String.format("{%s  %s}", name, cons.toString());
		}
	}


	public final Info       self;
	public final List<Info> dependList;
	public final List<Decl> declList;

	public Program(final Info self, final List<Info> dependList) {
		this.self       = self;
		this.dependList = dependList;
		declList   = new ArrayList<>();
	}

	@Override
	public int compareTo(final Program that) {
		return self.compareTo(that.self);
	}

	@Override
	public String toString() {
		return ToString.withFieldName(this);
	}

	public Info findDependProgram(final String name) {
		for(var e: dependList) {
			if (e.name.equals(name)) {
				return e;
			}
		}
		logger.error("name  {}", name);
		throw new UnexpectedException("Unpexpected");
	}

}
