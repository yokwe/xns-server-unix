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
		
		public Info(String name, int program, int version) {
			this.name    = name;
			this.program = program;
			this.version = version;
		}
		public Info(String name, String program, String version) {
			this(name, Util.parseInt(program), Util.parseInt(version));
		}
		@Override
		public boolean equals(Object o) {
			if (o instanceof Info) {
				var that = (Info)o;
				return this.program == that.program && this.version == that.version;
			} else {
				return false;
			}
		}

		@Override
		public int compareTo(Info that) {
			int ret = this.program - that.program;
			if (ret == 0) ret = this.version - that.version;
			if (ret == 0) ret = this.name.compareTo(that.name);
			return ret;
		}
		
		@Override
		public String toString() {
			return ToString.withFieldName(this);
		}
		public String toName() {
			return (version == 0) ? name : String.format("%s%d", name, version);
		}
	}
	
	public static class Decl {
		public enum Kind {TYPE, CONS};
		
		public final Kind   kind;
		public final String name;
		public final Type   type;
		public final Cons   cons;
				
		public Decl(String name, Type type) {
			this.kind = Kind.TYPE;
			this.name = name;
			this.type = type;
			this.cons = null;
		}
		public Decl(String name, Type type, Cons cons) {
			this.kind = Kind.CONS;
			this.name = name;
			this.type = type;
			this.cons = cons;
		}
		
		@Override
		public String toString() {
			if (kind == Kind.TYPE) return String.format("{%s  %s  %s}", kind, name, type);
			if (kind == Kind.CONS) return String.format("{%s  %s  %s  %s}", kind, name, type, cons);
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
		
		public NumberName(int number, String name) {
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
		
		public NameNumberType(String name, int number, Type type) {
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
		public NameType(String name, Type type) {
			this.name = name;
			this.type = type;
		}
		
		@Override
		public String toString() {
			return String.format("{%s  %s}", name, type.toString());
		};
	}
	
	// name cons
	public static class NameCons {
		public final String name;
		public final Cons   cons;
		public NameCons(String name, Cons cons) {
			this.name = name;
			this.cons = cons;
		}
		
		@Override
		public String toString() {
			return String.format("{%s  %s}", name, cons.toString());
		};
	}
	
	// Reference
	public static class Reference {
		public final Info   program;
		public final String namespace;
		public final String name;

		public Reference(Program myProgram, String name) {
			this.program   = myProgram.self;
			this.namespace = null;
			this.name      = name;
		}
		public Reference(Program myProgram, String program, String name) {				
			this.program   = myProgram.findDepend(program);
			this.namespace = null;
			this.name      = name;
		}
		public Reference(String namespace, String name) {
			this.name      = name;
			this.program   = null;
			this.namespace = namespace;
		}
		
		@Override
		public String toString() {
			return isExternal() ? String.format("%s::%s", namespace, name) : String.format("%s%d.%s", program.name, program.version, name);
		}
		
		public boolean isInernal() {
			return namespace == null;
		}
		public boolean isExternal() {
			return namespace != null;
		}
	}
	

	public final Info       self;
	public final List<Info> dependList;
	public final List<Decl> declList;
	
	public Program(Info self, List<Info> dependList) {
		this.self       = self;
		this.dependList = dependList;
		this.declList   = new ArrayList<>();
	}

	@Override
	public int compareTo(Program that) {
		return this.self.compareTo(that.self);
	}
	
	@Override
	public String toString() {
		return ToString.withFieldName(this);
	}
	
	public void addDepend(List<Info> list) {
		dependList.addAll(list);
	}
	public void addDecl(List<Decl> list) {
		declList.addAll(list);
	}
	
	public Info findDepend(String name) {
		for(var e: dependList) {
			if (e.name.equals(name)) return e;
		}
		logger.error("name  {}", name);
		throw new UnexpectedException("Unpexpected anem");
	}
}
