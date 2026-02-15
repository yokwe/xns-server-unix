package yokwe.courier.app;

import yokwe.courier.program.Builder;

public class CheckContext {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	public static void main(final String[] args) throws Exception {
		logger.debug("START");

		String[] pathList = {
			"data/courier/custom",
			"data/courier/XNSonUX",
		};

		var builder = new Builder();

		for(var path: pathList) {
			logger.info("path  {}", path);
			for(var e: builder.getCourierFileList(path)) {
				logger.info("      {}", e);
				builder.getCourierProgramContext(e);
			}
		}

		logger.debug("STOP");
	}
}
