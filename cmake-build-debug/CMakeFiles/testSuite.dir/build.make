# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/lars/programs/CLion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/lars/programs/CLion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lars/CLionProjects/LinearAlgebra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lars/CLionProjects/LinearAlgebra/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testSuite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testSuite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testSuite.dir/flags.make

CMakeFiles/testSuite.dir/main.cpp.o: CMakeFiles/testSuite.dir/flags.make
CMakeFiles/testSuite.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/CLionProjects/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testSuite.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSuite.dir/main.cpp.o -c /home/lars/CLionProjects/LinearAlgebra/main.cpp

CMakeFiles/testSuite.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSuite.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lars/CLionProjects/LinearAlgebra/main.cpp > CMakeFiles/testSuite.dir/main.cpp.i

CMakeFiles/testSuite.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSuite.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lars/CLionProjects/LinearAlgebra/main.cpp -o CMakeFiles/testSuite.dir/main.cpp.s

CMakeFiles/testSuite.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/testSuite.dir/main.cpp.o.requires

CMakeFiles/testSuite.dir/main.cpp.o.provides: CMakeFiles/testSuite.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/testSuite.dir/build.make CMakeFiles/testSuite.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/testSuite.dir/main.cpp.o.provides

CMakeFiles/testSuite.dir/main.cpp.o.provides.build: CMakeFiles/testSuite.dir/main.cpp.o


CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o: CMakeFiles/testSuite.dir/flags.make
CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o: ../SparseAlgebra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/CLionProjects/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o -c /home/lars/CLionProjects/LinearAlgebra/SparseAlgebra.cpp

CMakeFiles/testSuite.dir/SparseAlgebra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSuite.dir/SparseAlgebra.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lars/CLionProjects/LinearAlgebra/SparseAlgebra.cpp > CMakeFiles/testSuite.dir/SparseAlgebra.cpp.i

CMakeFiles/testSuite.dir/SparseAlgebra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSuite.dir/SparseAlgebra.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lars/CLionProjects/LinearAlgebra/SparseAlgebra.cpp -o CMakeFiles/testSuite.dir/SparseAlgebra.cpp.s

CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.requires:

.PHONY : CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.requires

CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.provides: CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.requires
	$(MAKE) -f CMakeFiles/testSuite.dir/build.make CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.provides.build
.PHONY : CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.provides

CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.provides.build: CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o


CMakeFiles/testSuite.dir/SparseVector.cpp.o: CMakeFiles/testSuite.dir/flags.make
CMakeFiles/testSuite.dir/SparseVector.cpp.o: ../SparseVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/CLionProjects/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testSuite.dir/SparseVector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSuite.dir/SparseVector.cpp.o -c /home/lars/CLionProjects/LinearAlgebra/SparseVector.cpp

CMakeFiles/testSuite.dir/SparseVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSuite.dir/SparseVector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lars/CLionProjects/LinearAlgebra/SparseVector.cpp > CMakeFiles/testSuite.dir/SparseVector.cpp.i

CMakeFiles/testSuite.dir/SparseVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSuite.dir/SparseVector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lars/CLionProjects/LinearAlgebra/SparseVector.cpp -o CMakeFiles/testSuite.dir/SparseVector.cpp.s

CMakeFiles/testSuite.dir/SparseVector.cpp.o.requires:

.PHONY : CMakeFiles/testSuite.dir/SparseVector.cpp.o.requires

CMakeFiles/testSuite.dir/SparseVector.cpp.o.provides: CMakeFiles/testSuite.dir/SparseVector.cpp.o.requires
	$(MAKE) -f CMakeFiles/testSuite.dir/build.make CMakeFiles/testSuite.dir/SparseVector.cpp.o.provides.build
.PHONY : CMakeFiles/testSuite.dir/SparseVector.cpp.o.provides

CMakeFiles/testSuite.dir/SparseVector.cpp.o.provides.build: CMakeFiles/testSuite.dir/SparseVector.cpp.o


CMakeFiles/testSuite.dir/SparseMatrix.cpp.o: CMakeFiles/testSuite.dir/flags.make
CMakeFiles/testSuite.dir/SparseMatrix.cpp.o: ../SparseMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/CLionProjects/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/testSuite.dir/SparseMatrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSuite.dir/SparseMatrix.cpp.o -c /home/lars/CLionProjects/LinearAlgebra/SparseMatrix.cpp

CMakeFiles/testSuite.dir/SparseMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSuite.dir/SparseMatrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lars/CLionProjects/LinearAlgebra/SparseMatrix.cpp > CMakeFiles/testSuite.dir/SparseMatrix.cpp.i

CMakeFiles/testSuite.dir/SparseMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSuite.dir/SparseMatrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lars/CLionProjects/LinearAlgebra/SparseMatrix.cpp -o CMakeFiles/testSuite.dir/SparseMatrix.cpp.s

CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.requires:

.PHONY : CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.requires

CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.provides: CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/testSuite.dir/build.make CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.provides.build
.PHONY : CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.provides

CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.provides.build: CMakeFiles/testSuite.dir/SparseMatrix.cpp.o


# Object files for target testSuite
testSuite_OBJECTS = \
"CMakeFiles/testSuite.dir/main.cpp.o" \
"CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o" \
"CMakeFiles/testSuite.dir/SparseVector.cpp.o" \
"CMakeFiles/testSuite.dir/SparseMatrix.cpp.o"

# External object files for target testSuite
testSuite_EXTERNAL_OBJECTS =

testSuite: CMakeFiles/testSuite.dir/main.cpp.o
testSuite: CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o
testSuite: CMakeFiles/testSuite.dir/SparseVector.cpp.o
testSuite: CMakeFiles/testSuite.dir/SparseMatrix.cpp.o
testSuite: CMakeFiles/testSuite.dir/build.make
testSuite: CMakeFiles/testSuite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lars/CLionProjects/LinearAlgebra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable testSuite"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testSuite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testSuite.dir/build: testSuite

.PHONY : CMakeFiles/testSuite.dir/build

CMakeFiles/testSuite.dir/requires: CMakeFiles/testSuite.dir/main.cpp.o.requires
CMakeFiles/testSuite.dir/requires: CMakeFiles/testSuite.dir/SparseAlgebra.cpp.o.requires
CMakeFiles/testSuite.dir/requires: CMakeFiles/testSuite.dir/SparseVector.cpp.o.requires
CMakeFiles/testSuite.dir/requires: CMakeFiles/testSuite.dir/SparseMatrix.cpp.o.requires

.PHONY : CMakeFiles/testSuite.dir/requires

CMakeFiles/testSuite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testSuite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testSuite.dir/clean

CMakeFiles/testSuite.dir/depend:
	cd /home/lars/CLionProjects/LinearAlgebra/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/CLionProjects/LinearAlgebra /home/lars/CLionProjects/LinearAlgebra /home/lars/CLionProjects/LinearAlgebra/cmake-build-debug /home/lars/CLionProjects/LinearAlgebra/cmake-build-debug /home/lars/CLionProjects/LinearAlgebra/cmake-build-debug/CMakeFiles/testSuite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testSuite.dir/depend
