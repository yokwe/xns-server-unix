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
    Context.h
    Packet.h
    Server.h
    Session.h
    SPP.h
  PRIVATE
    CHS.cpp
    Clearinghouse3.cpp
    Config.cpp
    Connection.cpp
    Echo.cpp
    Error.cpp
    main.cpp
    RIP.cpp
    Server.cpp
    Session.cpp
    SPP.cpp
    Time.cpp
  )

add_dependencies(server service courier xns util)

target_link_libraries (server service courier xns util)
