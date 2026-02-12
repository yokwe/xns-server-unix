package yokwe.courier.app;

import yokwe.courier.program.Builder;

public class CheckLexer {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();
	
	public static void main(String[] args) throws Exception {
		logger.debug("START");
		
		String[] pathList = {
			"data/courier/custom",
			"data/courier/XNSonUX",
		};
		for(var e: pathList) {
			process(e);
		}
		logger.debug("STOP");
	}
	
	static void process(String path) {
		logger.info("path  {}", path);
		for(var e: Builder.getCourierFileList(path)) {
			logger.info("      {}", e);
			Builder.getContext(e);
		}
	}

}
