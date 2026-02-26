package yokwe.courier.app;

import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import yokwe.courier.compiler.Compiler;
import yokwe.courier.compiler.Service;
import yokwe.courier.program.Builder;
import yokwe.util.AutoIndentPrintWriter;

public class CheckService {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	public static void main(final String[] args) throws Exception {
		logger.debug("START");


		String[] pathList = {
			"data/courier/custom",
			"data/courier/XNSonUX",
		};

		var builder = new Builder();
		builder.scanDirectory(pathList);

		var compiler = new Compiler();

		var serviceList = new ArrayList<Service>();
		for(var program: builder.programMap.values()) {
			logger.info("{}", String.format("program   %-16s  %3d  %3d", program.self.toName(), program.dependList.size(), program.declList.size()));

			var service = compiler.compile(program);
			serviceList.add(service);
		}

		generateService(serviceList);

		logger.debug("STOP");
	}

	static private void generateService(List<Service> serviceList) {
		for(var service: serviceList) {
			if (service.procedureList.isEmpty()) {
				continue;
			}

			var programName   = service.module.toName();
			var programNumber = service.module.programNo;
			var versionNumber = service.module.versionNo;

			var path = Paths.get("src", "service", programName + ".h");
			logger.info("path  {}", path.toString());

			try (var out  = new AutoIndentPrintWriter(path)) {
				// preamble
				out.printlnRaw(Compiler.COPYRIGHT_COMMENT);
				out.println(
					"""
					//
					// %s.h
					//
					""", programName);
				out.println(
					"""
					#pragma once

					#include "../util/ByteBuffer.h"

					#include "Service.h"
					""");
				out.println("#include \"../courier/%s.h\"", programName);
				out.println();

				out.println("namespace service {");

				out.println("// Service  name  %-24s   programNumber  %4d  versionNumber  %2d", programName, programNumber, versionNumber);
				out.println("struct %s : public Program {", programName);
				out.println("private:");

				// output class for procedure
				out.println("// List of Procedure  %d", service.procedureList.size());
				for(var e: service.procedureList) {
					var procName  = e.name;
					var procValue = e.value;

					out.println("struct Proc%d : public Procedure<courier::%s::%s> {", procValue, programName, procName);
					out.println("using Procedure::Procedure;");
					out.println("} proc%d {%d, \"%s\"};", procValue, procValue, procName);
				}
				out.println();

				out.println("public:");

				// output class for error
				if (service.errorList.isEmpty()) {
					out.println("// No Error");
				} else {
					out.println("// List of Error  %d", service.errorList.size());
					for(var e: service.errorList) {
						out.println("struct %s : public ErrorBase {", e.name);
						out.println("%s() : ErrorBase(%d, \"%s\") {}", e.name, e.value, e.name);
						out.println("};");
					}
				}
				out.println();

				// output set function
				out.println("// List of setXXX  %d", service.procedureList.size());
				for(var e: service.procedureList) {
					var procName  = e.name;
					var procValue = e.value;
					out.println("void set%s(Proc%d::Function newValue) {", procName, procValue);
					out.println("proc%d.set(newValue);", procValue);
					out.println("}");
				}
				out.println();

				// output constructor
				out.println("%s() : Program(%d, %d, \"%s\") {", programName, programNumber, versionNumber, programName);
				var list = service.procedureList.stream().map(o -> String.format("&proc%d", o.value)).toList();
				out.println("procedureList = {%s};", String.join(", ", list));
				out.println("}");

				out.println("};");
				out.println("}");
			}
		}
	}
}
