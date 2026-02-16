package yokwe.courier.app;

import yokwe.courier.compiler.Compiler;
import yokwe.courier.program.Builder;

public class CheckCompile {
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

		for(var program: builder.programMap.values()) {
			logger.info("{}", String.format("program   %-16s  %3d  %3d", program.self.toName(), program.dependList.size(), program.declList.size()));

			compiler.compile(program);
		}

		logger.debug("STOP");
	}

}
