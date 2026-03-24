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
        Context.h
        Server.h
        Session.h
        SocketEcho.h
        SocketError.h
        SocketManager.h
        SocketRIP.h
        SocketTime.h
    PRIVATE
        Config.cpp
        main.cpp
        Server.cpp
        Session.cpp
        SocketEcho.cpp
        SocketError.cpp
        SocketManager.cpp
        SocketRIP.cpp
        SocketTime.cpp
  )

add_dependencies(server service courier xns util)

target_link_libraries (server service courier xns util)
