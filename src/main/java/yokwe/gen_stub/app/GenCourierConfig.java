package yokwe.gen_stub.app;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import yokwe.gen_stub.courier.program.Program;
import yokwe.gen_stub.courier.program.Program.DeclConst;
import yokwe.gen_stub.courier.program.ProgramBuilder;
import yokwe.gen_stub.courier.program.Type.Kind;
import yokwe.gen_stub.courier.program.Util;
import yokwe.util.FileUtil;
import yokwe.util.ToString;
import yokwe.util.json.JSON;

public class GenCourierConfig {
	protected static final Logger logger = LoggerFactory.getLogger(GenStub.class);
	
	static class ProcedureName implements Comparable<ProcedureName> {
		int    procedure;
		String name;
		
		ProcedureName(String name, int procedure) {
			this.procedure = procedure;
			this.name      = name;
		}
		
		@Override
		public String toString() {
			return ToString.withFieldName(this);
		}
		@Override
		public int compareTo(ProcedureName that) {
			return this.procedure - that.procedure;
		}
	}
	
	static class ProgramName implements Comparable<ProgramName> {
		int    program;
		int    version;
		String name;
		
		List<ProcedureName> procedures = new ArrayList<>();
		
		ProgramName(String name, int program, int version) {
			this.program = program;
			this.version = version;
			this.name    = String.format("%s%d", name, version);
		}
		
		void add(ProcedureName value) {
			procedures.add(value);
		}
		@Override
		public String toString() {
			return ToString.withFieldName(this);
		}
		@Override
		public int compareTo(ProgramName that) {
			int ret = this.program - that.program;
			if (ret == 0) ret = this.version - that.version;
			return ret;
		}
	}
	
	static class CourierConfig {
		List<ProgramName> programs = new ArrayList<>();
	}
	
	public static void main(String[] args) throws Exception {
		logger.debug("START");
		ProgramBuilder.initialize("data/courier/custom");
		ProgramBuilder.initialize("data/courier/XNSonUX");
		ProgramBuilder.initialize("data/courier/test");
		
		CourierConfig config = new CourierConfig();
		
		for(var program: Program.all.values()) {
			if (program.info.program == 0 && program.info.version == 0) continue;
			
			logger.info("program  {}", program.info.toString());
			var programName = new ProgramName(program.info.name, program.info.program, program.info.version);
			
			for(var decl: program.declList) {
				if (decl.type.kind == Kind.PROCEDURE) {
					DeclConst declConst = (DeclConst)decl;
					var procedureNumber = (int)Util.parseLong(declConst.constant.toString());
					logger.info("{}  {}  {}  {}", program.info.program, program.info.version, procedureNumber, declConst.name);
					
					var procedureName = new ProcedureName(declConst.name, procedureNumber);
					programName.add(procedureName);
				}
			}
			// sort procedure
			Collections.sort(programName.procedures);
			
			if (programName.procedures.isEmpty()) continue;
			config.programs.add(programName);
		}
		
		// sort program
		Collections.sort(config.programs);
		
		var string = JSON.marshal(config);
		FileUtil.write().file("tmp/courier-config.json", string);
		logger.info("string  {}", string);
	}
}
