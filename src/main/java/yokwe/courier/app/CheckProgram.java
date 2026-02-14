package yokwe.courier.app;

import yokwe.courier.program.Builder;
import yokwe.courier.program.Reference;

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
								
		for(var program: builder.programMap.values()) {
			logger.info("{}", String.format("program   %-16s  %3d  %3d", program.self.toName(), program.dependList.size(), program.declList.size()));
		}
		
		logger.info("TYPE  {}", Reference.TYPE.context.toString());
		logger.info("CONS  {}", Reference.CONS.context.toString());
		
		logger.debug("STOP");
	}
}
