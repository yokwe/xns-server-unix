package yokwe.courier.app;

import yokwe.courier.program.Builder;

public class CheckProgram {
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
			for(var e: builder.getCourierFileList(path)) {
				logger.info("      {}", e);
				builder.scanFile(e);
			}
		}
		builder.fixReference();
		
		logger.info("programMap  {}", builder.programMap.size());
		logger.info("type        {}  {}", builder.typeMap.size(), builder.typeMapRef.size());
		logger.info("cons        {}  {}", builder.consMap.size(), builder.consMapRef.size());
		
		
		logger.debug("STOP");
	}
}
