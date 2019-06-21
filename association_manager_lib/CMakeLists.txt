cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 14)
set(target lAssociationManager)

message("-------------------------- Run ${target} CMAKE --------------------------")

include_directories(
)

file(GLOB_RECURSE SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../common/*.cpp
)
message(STATUS "SOURCES: ${SOURCES}")

add_library(${target} ${SOURCES})

message("-------------------------- End ${target} CMAKE --------------------------")