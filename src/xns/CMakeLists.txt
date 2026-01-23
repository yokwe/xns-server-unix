#
# xns
#

add_library(xns STATIC)

target_sources(
	xns
	PUBLIC
		Config.h
		Ethernet.h
		XNS.h
	PRIVATE
		Config.cpp
#		Ethernet.cpp
		XNS.cpp
)

target_link_libraries(xns util log4cxx)