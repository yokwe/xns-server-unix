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
    main.cpp
)

add_dependencies(server xns util)

target_link_libraries (server xns util)
