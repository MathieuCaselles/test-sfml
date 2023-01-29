cmake_minimum_required(VERSION 3.25.2)

add_executable(worms)
target_link_libraries(worms PUBLIC
    project_options
    worms::engine
    #    sfml_main
)
target_include_directories(worms PUBLIC
 $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../>
)

target_sources(worms PRIVATE
  main.cpp
)
