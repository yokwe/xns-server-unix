package yokwe.courier.app;

import yokwe.courier.program.Builder;
import yokwe.courier.program.Program.ReferenceCons;
import yokwe.courier.program.Program.ReferenceType;

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
		
		logger.info("typeMap        {}", builder.typeMap.size());
		logger.info("consMap        {}", builder.consMap.size());
		logger.info("typeMapRef     {}", builder.typeMapRef.size());
		logger.info("consMapRef     {}", builder.consMapRef.size());
		logger.info("ReferenceType  {}", ReferenceType.all.size());
		logger.info("ReferenceCons  {}", ReferenceCons.all.size());
		
		logger.debug("STOP");
	}
}
