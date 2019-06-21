cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 14)
project(AssociationManagerViewer)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
set(PATH_TO_ASSOCIATION_MANAGER_LIB "${CMAKE_CURRENT_SOURCE_DIR}/association_manager_lib")
message(STATUS "====> ${CMAKE_C_COMPILER}")
message(STATUS "====> ${CMAKE_CXX_COMPILER}")

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/common
        ${PATH_TO_ASSOCIATION_MANAGER_LIB}
)

file(GLOB_RECURSE SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp
)
message(STATUS "SOURCES: ${SOURCES}")

add_subdirectory(${PATH_TO_ASSOCIATION_MANAGER_LIB} ${CMAKE_CURRENT_BINARY_DIR}/association_manager_lib)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} lAssociationManager)

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_SEARCH_END_STATIC 1)

