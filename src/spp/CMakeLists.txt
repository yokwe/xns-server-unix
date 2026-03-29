#
# spp
#

add_library(spp STATIC)

target_sources(
	spp
	PUBLIC
		Authentication2.h
		Clearinghouse3.h
		Client.h
		ClientCourier.h
		Connection.h
		ConnectionStream.h
		Packet.h
		SocketAUTH.h
		SocketBoot.h
		SocketCHS.h
		SocketCourier.h
		SocketSPP.h
		Stream.h
	PRIVATE
		Authentication2.cpp
		Clearinghouse3.cpp
		ClientCourier.cpp
		Connection.cpp
		ConnectionStream.cpp
		Packet.cpp
		SocketAUTH.cpp
		SocketBoot.cpp
		SocketCHS.cpp
		SocketCourier.cpp
		SocketSPP.cpp
	)

target_link_libraries(spp service courier xns util)