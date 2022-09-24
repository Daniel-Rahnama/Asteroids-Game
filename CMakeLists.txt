cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

project(Asteroids)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

file(GLOB src src/*.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} "C:/Libraries/SDL2/x86_64-w64-mingw32/include")

add_executable(Asteroids ${src})

target_link_libraries(Asteroids pthread)

string(STRIP "${SDL2_LIBRARIES}" "C:/Libraries/SDL2/x86_64-w64-mingw32/lib/")
target_link_libraries(Asteroids ${SDL2_LIBRARIES})