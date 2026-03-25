#
# spp
#

add_library(spp STATIC)

target_sources(
	spp
	PUBLIC
		Clearinghouse3.h
		Client.h
		ClientCourier.h
		Connection.h
		ConnectionStream.h
		Packet.h
		SocketAUTH.h
		SocketCHS.h
		SocketCourier.h
		SocketSPP.h
		Stream.h
	PRIVATE
		Clearinghouse3.cpp
		ClientCourier.cpp
		Connection.cpp
		ConnectionStream.cpp
		Packet.cpp
		SocketAUTH.cpp
		SocketCHS.cpp
		SocketCourier.cpp
		SocketSPP.cpp
	)

target_link_libraries(spp service courier xns util)