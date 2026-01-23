#
# xns
#

add_library(xns STATIC)

target_sources(
	xns
	PUBLIC
		Config.h
		Ethernet.h
		Type.h
		xns.h
	PRIVATE
		Config.cpp
#		Ethernet.cpp
		Type.cpp
		xns.cpp
)

target_link_libraries(xns util log4cxx)