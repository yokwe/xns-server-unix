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

import java.util.Map;
import java.util.TreeMap;

import yokwe.util.UnexpectedException;

public class Util {
	public static long parseLong(String text) {
		int length = text.length();
		
		try {
			switch(text.charAt(length - 1)) {
			case 'b':
			case 'B':
				return Long.parseUnsignedLong(text.substring(0, length - 1), 8);
			case 'x':
			case 'X':
				return Long.parseUnsignedLong(text.substring(0, length - 1), 16);
			case 'd':
			case 'D':
				return Long.parseUnsignedLong(text.substring(0, length - 1), 10);
			default:
				return Long.parseUnsignedLong(text, 10);
			}
		} catch (NumberFormatException e) {
			throw new UnexpectedException(String.format("text = %s", text), e);
		}
	}
	public static String toJavaConstName(String name) {
		StringBuilder ret = new StringBuilder();
		boolean lastCharIsUpper = false;
		for(int i = 0; i < name.length(); i++) {
			char c = name.charAt(i);

			if (Character.isLowerCase(c)) {
				ret.append(Character.toUpperCase(c));
				lastCharIsUpper = false;
			} else if (Character.isDigit(c)) {
				ret.append(c);
				lastCharIsUpper = false;
			} else if (Character.isUpperCase(c)) {
				if (lastCharIsUpper) {
					ret.append(c);
				} else {
					ret.append('_').append(c);
				}
				lastCharIsUpper = true;
			} else {
				throw new UnexpectedException(String.format("Unknown character type = %c - %04X", c, c));
			}
		}
		return ret.toString();
	}
	
	private static Map<String, String> sanitizeMap = new TreeMap<>();
	static {
		sanitizeMap.put("abort",  "abort__");
		sanitizeMap.put("and",    "and__");
		sanitizeMap.put("not",    "not__");
		sanitizeMap.put("or",     "or__");
		sanitizeMap.put("return", "return__");
	}

	public static String sanitizeSymbol(String symbol) {
		if (sanitizeMap.containsKey(symbol)) {
			return sanitizeMap.get(symbol);
		}
		return symbol;
	}

}
