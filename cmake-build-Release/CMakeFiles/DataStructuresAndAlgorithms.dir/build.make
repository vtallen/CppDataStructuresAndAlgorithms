# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/cmake-build-Release

# Include any dependencies generated for this target.
include CMakeFiles/DataStructuresAndAlgorithms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DataStructuresAndAlgorithms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructuresAndAlgorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructuresAndAlgorithms.dir/flags.make

CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o: CMakeFiles/DataStructuresAndAlgorithms.dir/flags.make
CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o: /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/main.cpp
CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o: CMakeFiles/DataStructuresAndAlgorithms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o -MF CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o.d -o CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o -c /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/main.cpp

CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/main.cpp > CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.i

CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/main.cpp -o CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.s

# Object files for target DataStructuresAndAlgorithms
DataStructuresAndAlgorithms_OBJECTS = \
"CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o"

# External object files for target DataStructuresAndAlgorithms
DataStructuresAndAlgorithms_EXTERNAL_OBJECTS =

DataStructuresAndAlgorithms: CMakeFiles/DataStructuresAndAlgorithms.dir/main.cpp.o
DataStructuresAndAlgorithms: CMakeFiles/DataStructuresAndAlgorithms.dir/build.make
DataStructuresAndAlgorithms: CMakeFiles/DataStructuresAndAlgorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DataStructuresAndAlgorithms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructuresAndAlgorithms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructuresAndAlgorithms.dir/build: DataStructuresAndAlgorithms
.PHONY : CMakeFiles/DataStructuresAndAlgorithms.dir/build

CMakeFiles/DataStructuresAndAlgorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataStructuresAndAlgorithms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataStructuresAndAlgorithms.dir/clean

CMakeFiles/DataStructuresAndAlgorithms.dir/depend:
	cd /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/cmake-build-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/cmake-build-Release /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/cmake-build-Release /home/vtallen/Nextcloud/Programming/Cpp/DataStructuresAndAlgorithms/cmake-build-Release/CMakeFiles/DataStructuresAndAlgorithms.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructuresAndAlgorithms.dir/depend
