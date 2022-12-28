cmake_minimum_required(VERSION 3.10)

project(yamper VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp libs/*.cpp)

add_executable(yamper ${SRC_FILES})

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

target_link_libraries(yamper PUBLIC sfml-graphics sfml-audio)

target_include_directories(yamper PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/libs)

configure_file(res/Roboto-Medium.ttf Roboto-Medium.ttf COPYONLY)