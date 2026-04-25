#
# main
#

add_executable(
    main
)

  target_sources(
	main
    PUBLIC
    PRIVATE
        main.cpp
  )

add_dependencies(main service courier xns util)

target_link_libraries (main spp service courier xns util)
