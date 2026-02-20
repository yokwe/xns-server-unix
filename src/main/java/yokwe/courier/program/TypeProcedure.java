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

import yokwe.courier.program.Program.NameType;

public class TypeProcedure extends Type {
	public final List<NameType>  argumentList;
	public final List<NameType>  resultList;
	public final List<String> errorList;

	public TypeProcedure(final List<NameType>  argumentList, final List<NameType>  resultList, final List<String> errorList) {
		super(Kind.PROCEDURE);

		this.argumentList = argumentList;
		this.resultList   = resultList;
		this.errorList    = errorList;
	}

	@Override
	public String toString() {
		var argument = argumentList.isEmpty() ? "" : String.format(" {%s}", String.join(" ", argumentList.stream().map(NameType::toString).toList()));
		var result   = resultList.isEmpty() ? "" : String.format(" RETURNS {%s}", String.join(" ", resultList.stream().map(NameType::toString).toList()));
		var error    = errorList.isEmpty() ? "" : String.format(" REPORTS {%s}", String.join(" ", errorList));
		return String.format("{%s%s%s%s}", kind, argument, result, error);
	}
}
