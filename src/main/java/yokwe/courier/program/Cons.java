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

public class Cons {
	public enum Kind {
		BOOLEAN, NUMBER, STRING,
		ARRAY, CHOICE, RECORD,
		REFERENCE,
	}
	
	public static class BOOLEAN extends Cons {
		public final boolean value;
		
		public BOOLEAN(boolean value) {
			super(Kind.BOOLEAN);
			this.value = value;
		}
		
		@Override
		public String toString() {
			return value ? "TRUE" : "FALSE";
		}
	}
	public static final Cons TRUE  = new BOOLEAN(true);
	public static final Cons FALSE = new BOOLEAN(false);
	
	public static class NUMBER extends Cons {
		public final int value;
		
		public NUMBER(int value) {
			super(Kind.NUMBER);
			this.value = value;
		}
		public NUMBER(String value) {
			super(Kind.NUMBER);
			this.value = (int)Util.parseLong(value);
		}
		
		@Override
		public String toString() {
			return String.format("%d", value);
		}
	}
	public static class STRING extends Cons {
		public final String value;
		
		public STRING(String value) {
			super(Kind.STRING);
			this.value = value;
		}
		@Override
		public String toString() {
			return "\"" + value.replace("\"", "\\\"") + "\"";
		}
	}
	final Kind kind;
	
	public Cons(Kind type) {
		this.kind = type;
	}
	
	@Override
	public boolean equals(Object o) {
		return (o instanceof Cons) ? this.kind == ((Cons)o).kind : false;
	}
	
	public boolean isPredefined() {
		return switch(kind) {
			case BOOLEAN, NUMBER, STRING -> true;
			default -> false;
		};
	}
	public boolean isConstructed() {
		return switch(kind) {
			case ARRAY, CHOICE, RECORD -> true;
			default -> false;
		};
	}
	public boolean isReference() {
		return switch(kind) {
			case REFERENCE -> true;
			default -> false;
		};
	}
}