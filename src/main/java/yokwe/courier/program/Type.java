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

public class Type {
	public static final Type BOOLEAN       = new Type(Kind.BOOLEAN);
	public static final Type CARDINAL      = new Type(Kind.CARDINAL);
	public static final Type LONG_CARDINAL = new Type(Kind.LONG_CARDINAL);
	public static final Type INTEGER       = new Type(Kind.INTEGER);
	public static final Type LONG_INTEGER  = new Type(Kind.LONG_INTEGER);
	public static final Type STRING        = new Type(Kind.STRING);
	public static final Type UNSPECIFIED   = new Type(Kind.UNSPECIFIED);

	public enum Kind {
		// predefined
		BOOLEAN, CARDINAL, INTEGER, LONG_CARDINAL, LONG_INTEGER, STRING, UNSPECIFIED,
		// constructed
		ARRAY, CHOICE, ENUM, ERROR, PROCEDURE, RECORD, SEQUENCE,
		// reference
		REFERENCE
	}

	public final Kind kind;

	public Type(final Kind kind) {
		this.kind = kind;
	}

	@Override
	public boolean equals(final Object o) {
		return o instanceof Type t ? kind == t.kind : false;
	}
	@Override
	public String toString() {
		return kind.toString();
	}

	// toXXX
	public TypeReference toTypeReference() {
		return (TypeReference)this;
	}
	public TypeEnum toTypeEnum() {
		return (TypeEnum)this;
	}

	// isXXX
	public boolean isReference() {
		return kind == Kind.REFERENCE;
	}
	public boolean isEnum() {
		return kind == Kind.ENUM;
	}
	public boolean isChoice() {
		return kind == Kind.CHOICE;
	}
}
