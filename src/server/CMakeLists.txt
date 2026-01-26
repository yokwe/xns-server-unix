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
    Boot.cpp
    Echo.cpp
    Error.cpp
    IDP.cpp
    main.cpp
    PEX.cpp
    RIP.cpp
    SPP.cpp
)

add_dependencies(server xns util)

target_link_libraries (server xns util)
