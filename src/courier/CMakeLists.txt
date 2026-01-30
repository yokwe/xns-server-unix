#
# courier
#

add_library(courier STATIC)

target_sources(
	courier
	PUBLIC
		Courier.h
		Time.h
	PRIVATE
		Time.cpp
)

target_link_libraries(courier xns util log4cxx)