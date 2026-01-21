#
# util
#

add_library(util STATIC)

target_sources(
	util
	PUBLIC
		BPF.h
		ByteBuffer.h
		Debug.h
		net.h
		Perf.h
		ThreadControl.h
    	Util.h
	PRIVATE
		BPF.cpp
		ByteBuffer.cpp
		net.cpp
		Perf.cpp
		ThreadControl.cpp
		Util.cpp
)

target_link_libraries(util log4cxx)