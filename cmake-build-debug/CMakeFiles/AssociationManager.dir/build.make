# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mdenysiuk/SW/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mdenysiuk/SW/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mdenysiuk/CLionProjects/AssociationManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AssociationManager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AssociationManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AssociationManager.dir/flags.make

CMakeFiles/AssociationManager.dir/main.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AssociationManager.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/main.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/main.cpp

CMakeFiles/AssociationManager.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/main.cpp > CMakeFiles/AssociationManager.dir/main.cpp.i

CMakeFiles/AssociationManager.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/main.cpp -o CMakeFiles/AssociationManager.dir/main.cpp.s

CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.o: ../common/commonTypes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/common/commonTypes.cpp

CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/common/commonTypes.cpp > CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.i

CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/common/commonTypes.cpp -o CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.s

CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.o: ../src/cMsgValidator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/src/cMsgValidator.cpp

CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/src/cMsgValidator.cpp > CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.i

CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/src/cMsgValidator.cpp -o CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.s

CMakeFiles/AssociationManager.dir/src/Logger.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/src/Logger.cpp.o: ../src/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AssociationManager.dir/src/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/src/Logger.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/src/Logger.cpp

CMakeFiles/AssociationManager.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/src/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/src/Logger.cpp > CMakeFiles/AssociationManager.dir/src/Logger.cpp.i

CMakeFiles/AssociationManager.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/src/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/src/Logger.cpp -o CMakeFiles/AssociationManager.dir/src/Logger.cpp.s

CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.o: ../src/cEntityController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/src/cEntityController.cpp

CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/src/cEntityController.cpp > CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.i

CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/src/cEntityController.cpp -o CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.s

CMakeFiles/AssociationManager.dir/src/cStorage.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/src/cStorage.cpp.o: ../src/cStorage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AssociationManager.dir/src/cStorage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/src/cStorage.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/src/cStorage.cpp

CMakeFiles/AssociationManager.dir/src/cStorage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/src/cStorage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/src/cStorage.cpp > CMakeFiles/AssociationManager.dir/src/cStorage.cpp.i

CMakeFiles/AssociationManager.dir/src/cStorage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/src/cStorage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/src/cStorage.cpp -o CMakeFiles/AssociationManager.dir/src/cStorage.cpp.s

CMakeFiles/AssociationManager.dir/src/cEntity.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/src/cEntity.cpp.o: ../src/cEntity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AssociationManager.dir/src/cEntity.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/src/cEntity.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/src/cEntity.cpp

CMakeFiles/AssociationManager.dir/src/cEntity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/src/cEntity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/src/cEntity.cpp > CMakeFiles/AssociationManager.dir/src/cEntity.cpp.i

CMakeFiles/AssociationManager.dir/src/cEntity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/src/cEntity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/src/cEntity.cpp -o CMakeFiles/AssociationManager.dir/src/cEntity.cpp.s

CMakeFiles/AssociationManager.dir/src/cView.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/src/cView.cpp.o: ../src/cView.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AssociationManager.dir/src/cView.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/src/cView.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/src/cView.cpp

CMakeFiles/AssociationManager.dir/src/cView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/src/cView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/src/cView.cpp > CMakeFiles/AssociationManager.dir/src/cView.cpp.i

CMakeFiles/AssociationManager.dir/src/cView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/src/cView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/src/cView.cpp -o CMakeFiles/AssociationManager.dir/src/cView.cpp.s

CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.o: CMakeFiles/AssociationManager.dir/flags.make
CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.o: ../src/cHelperFunctions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.o -c /home/mdenysiuk/CLionProjects/AssociationManager/src/cHelperFunctions.cpp

CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mdenysiuk/CLionProjects/AssociationManager/src/cHelperFunctions.cpp > CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.i

CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mdenysiuk/CLionProjects/AssociationManager/src/cHelperFunctions.cpp -o CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.s

# Object files for target AssociationManager
AssociationManager_OBJECTS = \
"CMakeFiles/AssociationManager.dir/main.cpp.o" \
"CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.o" \
"CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.o" \
"CMakeFiles/AssociationManager.dir/src/Logger.cpp.o" \
"CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.o" \
"CMakeFiles/AssociationManager.dir/src/cStorage.cpp.o" \
"CMakeFiles/AssociationManager.dir/src/cEntity.cpp.o" \
"CMakeFiles/AssociationManager.dir/src/cView.cpp.o" \
"CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.o"

# External object files for target AssociationManager
AssociationManager_EXTERNAL_OBJECTS =

AssociationManager: CMakeFiles/AssociationManager.dir/main.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/common/commonTypes.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/src/cMsgValidator.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/src/Logger.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/src/cEntityController.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/src/cStorage.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/src/cEntity.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/src/cView.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/src/cHelperFunctions.cpp.o
AssociationManager: CMakeFiles/AssociationManager.dir/build.make
AssociationManager: CMakeFiles/AssociationManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable AssociationManager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AssociationManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AssociationManager.dir/build: AssociationManager

.PHONY : CMakeFiles/AssociationManager.dir/build

CMakeFiles/AssociationManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AssociationManager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AssociationManager.dir/clean

CMakeFiles/AssociationManager.dir/depend:
	cd /home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mdenysiuk/CLionProjects/AssociationManager /home/mdenysiuk/CLionProjects/AssociationManager /home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug /home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug /home/mdenysiuk/CLionProjects/AssociationManager/cmake-build-debug/CMakeFiles/AssociationManager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AssociationManager.dir/depend

