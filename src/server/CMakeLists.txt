#
# server
#

add_executable(
  server
  )

target_sources(
	server
	PUBLIC
    CHS.h
    Config.h
    Server.h
  PRIVATE
    CHS.cpp
    Config.cpp
    Echo.cpp
    Error.cpp
    Ethernet.cpp
    IDP.cpp
    main.cpp
    PEX.cpp
    RIP.cpp
    Server.cpp
    SPP.cpp
    Time.cpp
  )

add_dependencies(server service courier xns util)

target_link_libraries (server service courier xns courier util)
