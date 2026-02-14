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
		void add(R value) {
			all.add(value);
		}
		void add(String name, V value) {
			valueMap.put(name, value);
		}
		void add(String name, R ref) {
			refMap.put(name, ref);
		}
		
		V getValue(String name) {
			String newName = name;
			while(refMap.containsKey(newName)) {
				R ref = refMap.get(newName);
				var temp = ref.toName();
				if (temp.equals(newName)) {
					logger.error("getType  Unexpected name  {}  {}", name, newName);
					throw new UnexpectedException("Unexpected");
				}
				newName = temp;
			}
			
			if (valueMap.containsKey(newName)) return valueMap.get(newName);
			logger.error("getType  Unexpected name  {}  {}", name, newName);
//			return null;
			throw new UnexpectedException("Unexpected");
		}

		public void fix() {
			for(R e: all) {
				var name = e.toName();
				var value = getValue(name);
				e.value = value;
			}
		}
		
		@Override
		public String toString() {
			return String.format("{all  %4d  valueMap  %4d  refMap  %4d}", all.size(), valueMap.size(), refMap.size());
		}
	}
	
	public static class TYPE extends Reference<Type> {
		public static Context<TYPE, Type> context = new Context<>();
		
		public static void add(TYPE value) {
			context.add(value);
		}
		public static void add(String name, Type value) {
			context.add(name, value);
		}
		public static void add(String name, TYPE ref) {
			context.add(name, ref);
		}
		public static void fix() {
			context.fix();
		}
		
		public TYPE(Program myProgram, String name) {
			super(Kind.TYPE, myProgram, name);
			context.add(this);
		}
		public TYPE(Program myProgram, String program, String name) {
			super(Kind.TYPE, myProgram, program, name);
			context.add(this);
		}
		public TYPE(String namespace, String name) {
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

		public static void add(CONS value) {
			context.add(value);
		}
		public static void add(String name, Cons value) {
			context.add(name, value);
		}
		public static void add(String name, CONS ref) {
			context.add(name, ref);
		}
		public static void fix() {
			context.fix();
		}

		public CONS(Program myProgram, String name) {
			super(Kind.CONS, myProgram, name);
			context.add(this);
		}
		public CONS(Program myProgram, String program, String name) {
			super(Kind.CONS, myProgram, program, name);
			context.add(this);
		}
		public CONS(String namespace, String name) {
			super(Kind.CONS, namespace, name);
			context.add(this);
		}
		
		@Override
		public String toString() {
			return String.format("%s%s", needsFix() ? "?" : "", toName());
		}
	}

	
	public enum Kind {TYPE, CONS};
	
	public final Kind   kind;
	public final Info   program;
	public final String namespace;
	public final String name;
	
	public V value;
	
	protected Reference(Kind kind, Program myProgram, String name) {
		this.kind      = kind;
		this.program   = myProgram.self;
		this.namespace = null;
		this.name      = name;
	}
	protected Reference(Kind kind, Program myProgram, String program, String name) {
		this.kind      = kind;
		this.program   = myProgram.findDependProgram(program);
		this.namespace = null;
		this.name      = name;
	}
	protected Reference(Kind kind, String namespace, String name) {
		this.kind      = kind;
		this.program   = null;
		this.namespace = namespace;
		this.name      = name;
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
