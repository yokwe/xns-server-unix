#
# spp
#

add_library(spp STATIC)

target_sources(
	spp
	PUBLIC
		Connection.h
		ConnectionClient.h
		Packet.h
		Stream.h
	PRIVATE
		Connection.cpp
		Packet.cpp
)

target_link_libraries(spp service courier xns util)