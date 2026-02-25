package yokwe.courier.compiler;

import java.util.List;

import yokwe.courier.program.Module;

public class Service {
	public static class ProcedureInfo implements Comparable<ProcedureInfo> {
		public final int          value;
		public final String       name;
		public final List<String> errorNameList;

		public ProcedureInfo(int value, String name, List<String> errorNameList) {
			this.value         = value;
			this.name          = name;
			this.errorNameList = errorNameList;
		}

		@Override
		public String toString() {
			return String.format("{%d  %s  {%s}", value, name, String.join("  ", errorNameList));
		}

		@Override
		public int compareTo(ProcedureInfo that) {
			return Integer.compare(this.value, that.value);
		}
	}
	public static class ErrorInfo implements Comparable<ErrorInfo> {
		public final int    value;
		public final String name;

		public ErrorInfo(int value, String name) {
			this.value  = value;
			this.name   = name;
		}

		@Override
		public String toString() {
			return String.format("{%d  %s}", value, name);
		}

		@Override
		public int compareTo(ErrorInfo that) {
			return Integer.compare(this.value, that.value);
		}
	}

	public Module              module;
	public List<ErrorInfo>     errorList;
	public List<ProcedureInfo> procedureList;

	public Service(Module module, List<ErrorInfo> errorList, List<ProcedureInfo> procedureList) {
		this.module        = module;
		this.errorList     = errorList;
		this.procedureList = procedureList;
	}
}