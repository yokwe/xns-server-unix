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

package yokwe.courier.app;

import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import yokwe.courier.compiler.Compiler;
import yokwe.courier.compiler.Service;
import yokwe.courier.program.Builder;
import yokwe.util.AutoIndentPrintWriter;

public class CheckCompile {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	public static void main(final String[] args) throws Exception {
		logger.debug("START");

		var serviceList = new ArrayList<Service>();

		String[] pathList = {
			"data/courier/custom",
			"data/courier/XNSonUX",
		};

		var builder = new Builder();

		builder.scanDirectory(pathList);

		var compiler = new Compiler();

		for(var program: builder.programMap.values()) {
			logger.info("{}", String.format("program   %-16s  %3d  %3d", program.self.toName(), program.dependList.size(), program.declList.size()));

			var service = compiler.compile(program);
			serviceList.add(service);
		}

		generateService(serviceList);

		logger.debug("STOP");
	}

	static private void generateService(List<Service> serviceList) {
		var path = Paths.get("src", "courier", "Services.h");
		try (var out  = new AutoIndentPrintWriter(path)) {
			// preamble
			out.printlnRaw(Compiler.COPYRIGHT_COMMENT);
			out.println(
				"""
				//
				// Services.h
				//

				#pragma once

				#include <string>
				#include <vector>
				#include <array>
				#include <functional>

				#include "../util/Util.h"
				#include "../util/ByteBuffer.h"

				#include "Courier.h"
				#include "Service.h"

				""");

			for(var service: serviceList) {
				if (service.procedureList.isEmpty()) {
					continue;
				}
				out.println("#include \"%s.h\"", service.module.toName());
			}
			out.println();

			out.println("namespace courier::service {");


			for(var service: serviceList) {
				if (service.procedureList.isEmpty()) {
					continue;
				}

				var programName   = service.module.toName();
				var programNumber = service.module.programNo;
				var versionNumber = service.module.versionNo;

				out.println("// Service  name  %-24s   programNumber  %4d  versionNumber  %2d", programName, programNumber, versionNumber);
				out.println("struct %s : public Program {", programName);
				out.println("private:");
				// output class for procedure
				for(var e: service.procedureList) {
					var procName  = e.name;
					var procValue = e.value;

					out.println("struct Proc%d : public Procedure<courier::%s::%s> {", procValue, programName, procName);
					out.println("using Procedure::Procedure;");
					out.println("} proc%d {%d, \"%s\"};", procValue, procValue, procName);
				}
				out.println();

				out.println("public:");

				for(var e: service.procedureList) {
					var procName  = e.name;
					var procValue = e.value;
					out.println("void set%s(Proc%d::Function newValue) {", procName, procValue);
					out.println("proc%d.set(newValue);", procValue);
					out.println("}");
				}
				out.println();

				out.println("%s() : Program(%d, %d, \"%s\") {", programName, programNumber, versionNumber, programName);
				var list = service.procedureList.stream().map(o -> String.format("&proc%d", o.value)).toList();
				out.println("procedureList = {%s};", String.join(", ", list));
				out.println("}");

//				out.println("ByteBuffer call(const ByteBuffer& input);  // intput is CallMessage  output can be ReturnMessage or AbortMessage");

				out.println("};");
			}
		}
	}
}

