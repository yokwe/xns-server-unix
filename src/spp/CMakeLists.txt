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
		Packet.h
		SocketAUTH.h
		SocketBoot.h
		SocketCHS.h
		SocketCourier.h
		SocketSPP.h
		Stream.h
		StreamPEX.h
		StreamSPP.h
	PRIVATE
		Authentication2.cpp
		Clearinghouse3.cpp
		ClientCourier.cpp
		Connection.cpp
		Packet.cpp
		SocketAUTH.cpp
		SocketBoot.cpp
		SocketCHS.cpp
		SocketSPP.cpp
		StreamPEX.cpp
		StreamSPP.cpp
	)

target_link_libraries(spp service courier xns util)