cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

project(Asteroids)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

file(GLOB src src/*.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(run ${src})

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(run ${SDL2_LIBRARIES})