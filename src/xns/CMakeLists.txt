#
# xns
#

add_library(xns STATIC)

target_sources(
	xns
	PUBLIC
		Config.h
		Echo.h
		Error.h
		Ethernet.h
		IDP.h
		PEX.h
		RIP.h
		SPP.h
		XNS.h
	PRIVATE
		Config.cpp
		Echo.cpp
		Error.cpp
		Ethernet.cpp
		IDP.cpp
		PEX.cpp
		RIP.cpp
		SPP.cpp
		XNS.cpp
)

target_link_libraries(xns util log4cxx)