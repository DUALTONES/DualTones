cmake_minimum_required(VERSION 3.0)
project(DualTones)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(DualTones ${SOURCES})

target_link_libraries(DualTones raylib)

#find_package(Python3 COMPONENTS Development REQUIRED)

#include_directories(${Python3_INCLUDE_DIRS})

#target_link_libraries(DualTones ${Python3_LIBRARIES})

if (UNIX)
    target_link_libraries(DualTones GL m pthread dl)
endif()

if (WIN32)
    target_link_libraries(DualTones opengl32 gdi32 winmm)
endif()
