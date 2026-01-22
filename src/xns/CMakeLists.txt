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
	PRIVATE
		Config.cpp
#		Ethernet.cpp
		Type.cpp
)

target_link_libraries(xns util log4cxx)