package yokwe.courier.program;

import yokwe.courier.util.Util;
import yokwe.util.ToString;

public class Module implements Comparable<Module> {
	public final String name;
	public final int    programNo;
	public final int    versionNo;
	public final String nameString;

	public Module(final String name_, final int programNo_, final int versionNo_) {
		name       = name_;
		programNo  = programNo_;
		versionNo  = versionNo_;
		nameString = versionNo == 0 ? name : String.format("%s%d", name, versionNo);
	}
	public Module(final String name, final String program, final String version) {
		this(name, Util.parseInt(program), Util.parseInt(version));
	}

	@Override
	public String toString() {
		return ToString.withFieldName(this);
	}

	@Override
	public boolean equals(final Object o) {
		if (o instanceof Module that) {
			return this.programNo == that.programNo && this.versionNo == that.versionNo && this.name.equals(that.name);
		}
		return false;
	}
	@Override
	public int compareTo(final Module that) {
		return this.nameString.compareTo(that.nameString);
	}


	public String toName() {
		return nameString;
	}
	public String toQName(final String myName) {
		return nameString + "::" + myName;
	}
	public String toQName(final Module that, final String myName) {
		return this.equals(that) ? myName : toQName(myName);
	}
}