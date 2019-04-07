cmake_minimum_required(VERSION 3.13)
project(AssociationManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(AssociationManager main.cpp common/commonTypes.cpp common/commonTypes.h src/cMsgValidator.cpp src/cMsgValidator.h common/constants.h src/Logger.cpp src/Logger.h src/cEntityController.cpp src/cEntityController.h src/cStorage.cpp src/cStorage.h src/cEntity.cpp src/cEntity.h src/cView.cpp src/cView.h)