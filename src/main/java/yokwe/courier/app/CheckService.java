package yokwe.courier.app;

import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

import yokwe.courier.compiler.Compiler;
import yokwe.courier.compiler.Service;
import yokwe.courier.program.Builder;
import yokwe.courier.util.Util;
import yokwe.util.AutoIndentPrintWriter;
import yokwe.util.AutoIndentPrintWriter.Layout;

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

			if (!service.procedureList.isEmpty()) {
				serviceList.add(service);
			}
		}

		for(var service: serviceList) {
			generateService(service);
		}
		generateServices(serviceList);

		logger.debug("STOP");
	}

	static private void generateServices(List<Service> serviceList) {
		// output Services.h
		var path = Paths.get("src", "service", "Services.h");
		logger.info("path  {}", path.toString());
		try (var out = new AutoIndentPrintWriter(path)) {
			out.printlnRaw(Compiler.COPYRIGHT_COMMENT);
			out.println(
				"""
				//
				// Services.h
				//

				#pragma once
				""");
			for(var e: serviceList) {
				out.println("#include \"%s.h\"", e.module.toName());
			}
			out.println(
			    """

				#include "Service.h"

				namespace service {""");

			out.println("inline struct Services : public ServicesBase {");
			out.prepareLayout();
			for(int i = 0; i < serviceList.size(); i++) {
				var service     = serviceList.get(i);
				var programName = service.module.toName();
				var name = "module" + i;
				out.println("%s %s;", programName, name);
			}
			out.layout(Layout.LEFT, Layout.LEFT);
			out.println();

			var nameList = IntStream.range(0, serviceList.size()).mapToObj(o -> ("&module" + o)).toList();
			out.println("Services() : ServicesBase({%s}) {}", String.join(", ", nameList));
			out.println("} services;");

			out.println("}");
		}
	}

	static private void generateService(Service service) {
		var programName   = service.module.toName();
		var programNumber = service.module.programNo;
		var versionNumber = service.module.versionNo;

		var path = Paths.get("src", "service", programName + ".h");
		logger.info("path  {}", path.toString());

		try (var out = new AutoIndentPrintWriter(path)) {
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

				#include "Service.h"
				""");
			out.println("#include \"../courier/%s.h\"", programName);
			out.println();

			out.println("namespace service {");

			out.println("struct %s : public ServiceBase {", programName);
			out.println("inline static const constexpr uint32_t PROGRAM = %d;", programNumber);
			out.println("inline static const constexpr uint16_t VERSION = %d;", versionNumber);
			out.println("inline static const constexpr char*    NAME    = \"%s\";", programName);
			out.println();

			// output constructor
			out.println("%s() : ServiceBase(PROGRAM, VERSION, NAME) {", programName);
			out.println("procedureList = {%s};",
				String.join(", ", service.procedureList.stream().map(o -> String.format("&proc%d", o.value)).toList()));
			out.println("}");
			out.println();

			// function table
			out.println("// Function Table");
			out.println("struct FunctionTable {");
			out.prepareLayout();
			for(var e: service.procedureList) {
				var procName  = e.name;
				out.println("courier::%s::%s::Function %s;", programName, procName, Util.sanitizeSymbol(Util.uncapitalizeName(procName)));
			}
			out.layout(Layout.LEFT, Layout.LEFT);
			out.println("};");
			out.println("void set(const FunctionTable& functionTable) {");
			for(var e: service.procedureList) {
				var procName  = e.name;
				var procValue = e.value;

				// GetStrongCredentials.set(functionTable.getStrongCredential);
				out.println("proc%d.set(functionTable.%s);", procValue, Util.sanitizeSymbol(Util.uncapitalizeName(procName)));
			}
			out.println("};");
			out.println();

			// output class for error
			if (service.errorList.isEmpty()) {
				out.println("// No Error");
			} else {
				out.println("// List of Error  %d", service.errorList.size());
				out.prepareLayout();
				for(var e: service.errorList) {
					out.println("using %s = courier::%s::%s;", e.name, programName, e.name);
				}
				out.layout(Layout.LEFT, Layout.LEFT, Layout.LEFT, Layout.LEFT);
			}
			out.println();
			// output class for procedure
			out.println("private:");
			out.println("// List of Procedure  %d", service.procedureList.size());
			for(var e: service.procedureList) {
				var procName  = e.name;
				var procValue = e.value;

				// See https://stackoverflow.com/questions/63545816/how-to-call-a-non-default-parent-constructor-from-an-unnamed-derived-class-in-c
				out.println("struct : public Procedure<courier::%s::%s> {", programName, procName);
				out.println("using Procedure::Procedure;");
				out.println("} proc%s {%d, \"%s\"};", procValue, procValue, procName);
			}

			out.println("};");
			out.println("}");
		}
	}
}
