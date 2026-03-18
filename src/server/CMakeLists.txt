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
    Connection.h
    ConnectionStream.h
    Context.h
    CourierConnection.h
    Packet.h
    Server.h
    Session.h
    SPP.h
  PRIVATE
    CHS.cpp
    Clearinghouse3.cpp
    Config.cpp
    Connection.cpp
    ConnectionStream.cpp
    CourierConnection.cpp
    Echo.cpp
    Error.cpp
    main.cpp
    Packet.cpp
    RIP.cpp
    Server.cpp
    Session.cpp
    SPP.cpp
    Time.cpp
  )

add_dependencies(server service courier xns util)

target_link_libraries (server service courier xns util)
