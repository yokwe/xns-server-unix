#
# courier
#

add_library(courier STATIC)

target_sources(
	courier
	PUBLIC
		Config.h
		Courier.h
		Time.h
	PRIVATE
		Config.cpp
		Courier.cpp
		Time.cpp
)

target_link_libraries(courier xns util log4cxx)