cmake_minimum_required(VERSION 3.10)

project(yamper VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp libs/*.cpp)

add_executable(yamper ${SRC_FILES})

option(LINK_OPENGL ON)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
if(LINK_OPENGL)
	find_package(OpenGL REQUIRED)
endif()

target_link_libraries(yamper PRIVATE sfml-graphics sfml-audio)

target_include_directories(yamper PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/libs)

if(LINK_OPENGL)
	target_link_libraries(yamper PUBLIC ${OPENGL_LIBRARIES})
	target_include_directories(yamper PUBLIC ${OPENGL_INCLUDE_DIRS})
endif()

configure_file(res/Roboto-Medium.ttf Roboto-Medium.ttf COPYONLY)