cmake_minimum_required(VERSION 3.25.2)
project(worms)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" ON)

include(CPM)
include(build_configuration)

CPMAddPackage("gh:SFML/SFML#2.5.1")

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

add_subdirectory(engine)
add_subdirectory(game)
