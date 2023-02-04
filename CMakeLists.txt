cmake_minimum_required(VERSION 3.25.2)
project(worms)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" ON)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(CPM)
include(build_configuration)

CPMAddPackage(
NAME SFML
VERSION 2.5.1
GITHUB_REPOSITORY SFML/SFML
GIT_TAG 2.5.1
OPTIONS "BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS}"
)


add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

add_subdirectory(engine)
add_subdirectory(game)