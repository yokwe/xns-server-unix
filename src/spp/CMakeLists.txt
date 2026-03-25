#
# spp
#

add_library(spp STATIC)

target_sources(
	spp
	PUBLIC
		Clearinghouse3.h
		Connection.h
		ConnectionClient.h
		Packet.h
		SocketCHS.h
		Stream.h
	PRIVATE
		Clearinghouse3.cpp
		Connection.cpp
		Packet.cpp
		SocketCHS.cpp
)

target_link_libraries(spp service courier xns util)