#
# server
#

add_executable(
  server
  )

target_sources(
	server
	PUBLIC
    Config.h
#    Connection.h
#    ConnectionClient.h
#    ConnectionClientCourier.h
#    ConnectionStream.h
    Context.h
    Packet.h
    Server.h
    Session.h
    SocketCHS.h
    SocketEcho.h
    SocketError.h
    SocketManager.h
    SocketRIP.h
    SocketTime.h
#    SPP.h
  PRIVATE
#    AUTH.cpp
#    CHS.cpp
    Clearinghouse3.cpp
    Config.cpp
#    Connection.cpp
#    ConnectionClientCourier.cpp
#    ConnectionStream.cpp
#    Echo.cpp
#    Error.cpp
    main.cpp
#    Packet.cpp
#    RIP.cpp
    Server.cpp
    Session.cpp
    SocketCHS.cpp
    SocketEcho.cpp
    SocketError.cpp
    SocketManager.cpp
    SocketRIP.cpp
    SocketTime.cpp
#    SPP.cpp
#    Time.cpp
  )

add_dependencies(server service courier xns util)

target_link_libraries (server service courier xns util)
