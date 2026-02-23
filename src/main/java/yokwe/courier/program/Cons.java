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

import yokwe.courier.util.Util;
import yokwe.util.UnexpectedException;

public class Cons {
	public enum Kind {
		BOOLEAN, NUMBER, STRING,
		ARRAY, CHOICE, RECORD,
		REFERENCE,
	}

	public static class Boolean extends Cons {
		public static final Cons TRUE  = new Boolean(true);
		public static final Cons FALSE = new Boolean(false);

		public final boolean value;

		public Boolean(final boolean value) {
			super(Kind.BOOLEAN);
			this.value = value;
		}

		@Override
		public java.lang.String toString() {
			return value ? "TRUE" : "FALSE";
		}
	}
	public static class Number extends Cons {
		public final int value;

		public Number(final int value) {
			super(Kind.NUMBER);
			this.value = value;
		}
		public Number(final java.lang.String value) {
			super(Kind.NUMBER);
			this.value = Util.parseInt(value);
		}

		@Override
		public java.lang.String toString() {
			return Util.toString(value);
		}
	}
	public static class String extends Cons {
		public final java.lang.String value;

		public String(final java.lang.String value) {
			super(Kind.STRING);
			this.value = value;
		}
		@Override
		public java.lang.String toString() {
			return value;
		}
	}

	public final Kind kind;

	public Cons(final Kind type) {
		kind = type;
	}

	@Override
	public boolean equals(final Object o) {
		return o instanceof Cons c ? kind == c.kind : false;
	}

	@Override
	public java.lang.String toString() {
		return kind.toString();
	}

	// getValueXXX
	public boolean getValueBoolean() {
		if (this instanceof Boolean) {
			return ((Boolean)this).value;
		}
		throw new UnexpectedException("Unexpected");
	}
	public int getValueNumber() {
		if (this instanceof Number) {
			return ((Number)this).value;
		}
		throw new UnexpectedException("Unexpected");
	}
	public java.lang.String getValueSting() {
		if (this instanceof String) {
			return ((String)this).value;
		}
		throw new UnexpectedException("Unexpected");
	}

	// toXXX
	public Boolean toConsBoolean() {
		return (Boolean)this;
	}
	public Number toConsNumber() {
		return (Number)this;
	}
	public String toConsString() {
		return (String)this;
	}
	public ConsArray toConsArray() {
		return (ConsArray)this;
	}
	public ConsChoice toConsChoice() {
		return (ConsChoice)this;
	}
	public ConsRecord toConsRecord() {
		return (ConsRecord)this;
	}
	public ConsReference toConsReference() {
		return (ConsReference)this;
	}

	// isXXX
	public boolean isBoolean() {
		return kind == Kind.BOOLEAN;
	}
	public boolean isNuber() {
		return kind == Kind.NUMBER;
	}
	public boolean isString() {
		return kind == Kind.STRING;
	}
	public boolean isArray() {
		return kind == Kind.ARRAY;
	}
	public boolean isChoice() {
		return kind == Kind.CHOICE;
	}
	public boolean isRecord() {
		return kind == Kind.RECORD;
	}
	public boolean isReference() {
		return kind == Kind.REFERENCE;
	}
}