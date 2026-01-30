#
# server
#

add_executable(
  server
  )

target_sources(
	server
	PUBLIC
    Server.h
  PRIVATE
    CHS.cpp
    Echo.cpp
    Error.cpp
    Ethernet.cpp
    IDP.cpp
    main.cpp
    PEX.cpp
    RIP.cpp
    SPP.cpp
    Time.cpp
)

add_dependencies(server xns courier util)

target_link_libraries (server xns courier util)
