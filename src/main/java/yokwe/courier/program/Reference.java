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
	}


	public enum Kind {TYPE, CONS}

	public final Kind   kind;
	public final Info   program;
	public final String namespace;
	public final String name;

	public V value;

	protected Reference(final Kind kind_, final Program myProgram, final String name_) {
		kind      = kind_;
		program   = myProgram.self;
		namespace = null;
		name      = name_;
	}
	protected Reference(final Kind kind_, final Program myProgram, final String program_, final String name_) {
		kind      = kind_;
		program   = myProgram.findDependProgram(program_);
		namespace = null;
		name      = name_;
	}
	protected Reference(final Kind kind_, final String namespace_, final String name_) {
		kind      = kind_;
		program   = null;
		namespace = namespace_;
		name      = name_;
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
		return isExternal() ? String.format("%s::%s", namespace, name) : String.format("%s.%s", program.toName(), name);
	}

	// isXXX
	public boolean isInternal() {
		return namespace == null;
	}
	public boolean isExternal() {
		return namespace != null;
	}
}
