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
    Server.h
  PRIVATE
    CHS.cpp
    Config.cpp
    Echo.cpp
    Error.cpp
    main.cpp
    RIP.cpp
    Server.cpp
    Time.cpp
  )

add_dependencies(server service courier xns util)

target_link_libraries (server service courier xns util)
