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

import yokwe.courier.program.Program.NumberName;

public class TypeChoice extends Type {
	public static class Candidate {
		public final List<NumberName> designatorList;
		public final Type             type;

		public Candidate(final List<NumberName> designatorList_, final Type type_) {
			designatorList = designatorList_;
			type           = type_;
		}

		@Override
		public String toString() {
			var string = String.join(" ", designatorList.stream().map(NumberName::toString).toList());
			return String.format("{{%s}  %s}", string, type.toString());
		}
	}
	public static class Anon extends TypeChoice {
		public final List<Candidate> candidateList;

		public Anon(final List<Candidate>candidateList_) {
			candidateList = candidateList_;
		}
		@Override
		public String toString() {
			var string = String.join(" ", candidateList.stream().map(Candidate::toString).toList());
			return String.format("{%s  ANON  {%s}}", kind, string);
		}
	}

	public static class CandidateName {
		public final List<String> nameList;
		public final Type         type;

		public CandidateName(final List<String> nameList_, final Type type_) {
			nameList = nameList_;
			type     = type_;
		}

		@Override
		public String toString() {
			return String.format("{{%s}  %s}", String.join(" ", nameList), type.toString());
		}
	}

	public static class Name extends TypeChoice {
		public final Reference.TYPE       designator;
		public final List<CandidateName>  candidateNameList;     // for each arm of choice

		public Name(final Reference.TYPE designator_, final List<CandidateName>  candidateNameList_) {
			designator        = designator_;
			candidateNameList = candidateNameList_;
		}
		@Override
		public String toString() {
			var string = String.format("{%s}", String.join(" ", candidateNameList.stream().map(CandidateName::toString).toList()));
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
