#
# xns
#

add_library(xns STATIC)

target_sources(
	xns
	PUBLIC
		Echo.h
		Error.h
		Ethernet.h
		IDP.h
		PEX.h
		RIP.h
		SPP.h
		XNS.h
	PRIVATE
		IDP.cpp
		RIP.cpp
		XNS.cpp
)

target_link_libraries(xns util log4cxx)