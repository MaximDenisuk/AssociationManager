#cmake_minimum_required(VERSION 2.8)
cmake_minimum_required(VERSION 3.13)
project(AssociationManager)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

message("====>" + ${CMAKE_C_COMPILER})
message("====>" + ${CMAKE_CXX_COMPILER})

add_executable(
    ${PROJECT_NAME}
    main.cpp
    common/commonTypes.cpp
    common/commonTypes.h
    src/cMsgValidator.cpp
    src/cMsgValidator.h
    common/constants.h
    src/Logger.cpp src/Logger.h
    src/cEntityController.cpp
    src/cEntityController.h
    src/cStorage.cpp
    src/cStorage.h
    src/cEntity.cpp
    src/cEntity.h
    src/cView.cpp
    src/cView.h
    src/cHelperFunctions.cpp
    src/cHelperFunctions.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_SEARCH_END_STATIC 1)


