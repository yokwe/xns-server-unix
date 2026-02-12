package yokwe.courier.app;

import yokwe.courier.program.Builder;

public class CheckParser {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();
	
	public static void main(String[] args) throws Exception {
		logger.debug("START");
		
		String[] pathList = {
			"data/courier/custom",
			"data/courier/XNSonUX",
		};
		
		var builder = new Builder();
		
		for(var path: pathList) {
			logger.info("path  {}", path);
			for(var e: Builder.getCourierFileList(path)) {
				logger.info("      {}", e);
				var context = Builder.getContext(e);
				builder.getProgram(context);
			}
		}
		logger.debug("STOP");
	}
}
