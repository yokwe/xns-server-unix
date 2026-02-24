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
import java.util.Map;
import java.util.TreeMap;

import yokwe.courier.program.Program.Info;
import yokwe.util.UnexpectedException;

public abstract class Reference<V> {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();


	// R is Reference.TYPE or Referene.CONS
	// V is Type or Cons
	public static class Context<R extends Reference<V>, V> {
		public List<R>         all;
		public Map<String, V>  valueMap; // Type or Cons
		public Map<String, R>  refMap;   // Reference.TYPE or Referene.CONS

		public Context() {
			all      = new ArrayList<>();
			valueMap = new TreeMap<>();
			refMap   = new TreeMap<>();
		}
		void add(final R value) {
			all.add(value);
		}
		void add(final String name, final V value) {
			valueMap.put(name, value);
		}
		void add(final String name, final R ref) {
			refMap.put(name, ref);
		}

		V getValue(final String name) {
			var newName = name;
			while(refMap.containsKey(newName)) {
				var ref = refMap.get(newName);
				var temp = ref.toName();
				if (temp.equals(newName)) {
					logger.error("getType  Unexpected name  {}  {}", name, newName);
					throw new UnexpectedException("Unexpected");
				}
				newName = temp;
			}

			if (valueMap.containsKey(newName)) {
				return valueMap.get(newName);
			}
			logger.warn("getType  Unexpected name  {}  {}", name, newName);
			return null;
//			throw new UnexpectedException("Unexpected");
		}

		public void fix() {
			for(R e: all) {
				if (e.needsFix()) {
					var name = e.toName();
					var value = getValue(name);

					if (value != null) {
						e.value = value;
					} else {
						logger.error("fix failed  {}", name);
						throw new UnexpectedException("Unexpected");
					}
				}
			}
		}
		public boolean needsFix() {
			for(R e: all) {
				if (e.needsFix()) {
					return true;
				}
			}
			return false;
		}

		@Override
		public String toString() {
			return String.format("{all  %4d  valueMap  %4d  refMap  %4d}", all.size(), valueMap.size(), refMap.size());
		}
	}

	public static class TYPE extends Reference<Type> {
		public static Context<TYPE, Type> context = new Context<>();

		public static void add(final TYPE value) {
			context.add(value);
		}
		public static void add(final String name, final Type value) {
			context.add(name, value);
		}
		public static void add(final String name, final TYPE ref) {
			context.add(name, ref);
		}
		public static void fix() {
			context.fix();
		}

		public TYPE(final Program myProgram, final String name) {
			super(Kind.TYPE, myProgram, name);
			context.add(this);
		}
		public TYPE(final Program myProgram, final String program, final String name) {
			super(Kind.TYPE, myProgram, program, name);
			context.add(this);
		}
		public TYPE(final String namespace, final String name) {
			super(Kind.TYPE, namespace, name);
			context.add(this);
		}

		@Override
		public String toString() {
			return String.format("%s%s", needsFix() ? "?" : "", toName());
		}

		public Type toType() {
			return value;
		}
	}
	public static class CONS extends Reference<Cons> {
		public static Context<CONS, Cons> context = new Context<>();

		public static void add(final CONS value) {
			context.add(value);
		}
		public static void add(final String name, final Cons value) {
			context.add(name, value);
		}
		public static void add(final String name, final CONS ref) {
			context.add(name, ref);
		}
		public static void fix() {
			context.fix();
		}

		public CONS(final Program myProgram, final String name) {
			super(Kind.CONS, myProgram, name);
			context.add(this);
		}
		public CONS(final Program myProgram, final String program, final String name) {
			super(Kind.CONS, myProgram, program, name);
			context.add(this);
		}
		public CONS(final String namespace, final String name) {
			super(Kind.CONS, namespace, name);
			context.add(this);
		}

		@Override
		public String toString() {
			return String.format("%s%s", needsFix() ? "?" : "", toName());
		}

		public Cons toCons() {
			return value;
		}
	}


	public enum Kind {TYPE, CONS}

	public final Kind   kind;
	public final Info   program;
	public final String namespace;
	public final String name;
	public final String nameString;

	public V value;

	protected Reference(final Kind kind_, final Program myProgram, final String name_) {
		kind       = kind_;
		program    = myProgram.self;
		namespace  = null;
		name       = name_;
		nameString = program.toQName(name);
	}
	protected Reference(final Kind kind_, final Program myProgram, final String program_, final String name_) {
		kind       = kind_;
		program    = myProgram.findDependProgram(program_);
		namespace  = null;
		name       = name_;
		nameString = program.toQName(name);
	}
	protected Reference(final Kind kind_, final String namespace_, final String name_) {
		kind       = kind_;
		program    = null;
		namespace  = namespace_;
		name       = name_;
		nameString = namespace + "::" + name;
	}

	public boolean fixed() {
		return !needsFix();
	}
	public boolean needsFix() {
		return value == null;
	}

	@Override
	public String toString() {
		return String.format("{%s  %s%s}", kind, fixed() ? "" : "?", toName());
	}

	public String toName() {
		return nameString;
	}
	public String toQName(Program.Info that) {
		return (program == null) ? nameString : program.toQName(that, name);
	}

	// isXXX
	public boolean isInternal() {
		return namespace == null;
	}
	public boolean isExternal() {
		return namespace != null;
	}

	// toXXX
	public Reference.TYPE toTYPE() {
		return (Reference.TYPE)this;
	}
	public Reference.CONS toCONS() {
		return (Reference.CONS)this;
	}
}
