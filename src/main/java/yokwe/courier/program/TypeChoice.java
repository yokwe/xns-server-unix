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

import java.util.List;

import yokwe.courier.program.Program.NameNumberType;
import yokwe.courier.program.Program.NameType;

public class TypeChoice extends Type {
	public static class Anon extends TypeChoice {
		public final List<NameNumberType> candidateList;

		public Anon(final List<NameNumberType>candidateList) {
			this.candidateList = candidateList;
		}
		@Override
		public String toString() {
			var list = candidateList.stream().map(NameNumberType::toString).toList();
			var string = String.format("{%s}", String.join(" ", list));
			return String.format("{%s  ANON  %s}", kind, string);
		}
	}

	public static class Name extends TypeChoice {
		public final Reference.TYPE designator;
		public final List<NameType> candidateList;

		public Name(final Reference.TYPE designator, final List<NameType> candidateList) {
			this.designator    = designator;
			this.candidateList = candidateList;
		}
		@Override
		public String toString() {
			var list = candidateList.stream().map(NameType::toString).toList();
			var string = String.format("{%s}", String.join(" ", list));
			return String.format("{%s  NAME  %s  %s}", kind, designator.toString(), string);
		}
	}

	public TypeChoice() {
		super(Kind.CHOICE);
	}

	// isXXX
	public boolean isAnon() {
		return this instanceof Anon;
	}
	public boolean isName() {
		return this instanceof Name;
	}

	// toXXX
	public Anon toAnon() {
		return (Anon)this;
	}
	public Name toName() {
		return (Name)this;
	}


}
