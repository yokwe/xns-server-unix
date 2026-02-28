#
# service
#

add_library(service STATIC)

target_sources(
	service
	PUBLIC
		Service.h
		Services.h
	PRIVATE
		Service.cpp
)

target_link_libraries(service courier xns util log4cxx)