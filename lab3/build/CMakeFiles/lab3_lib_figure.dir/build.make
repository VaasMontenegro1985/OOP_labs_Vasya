# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /workspaces/OOP_labs_Vasya/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/OOP_labs_Vasya/lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/lab3_lib_figure.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab3_lib_figure.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3_lib_figure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3_lib_figure.dir/flags.make

CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o: CMakeFiles/lab3_lib_figure.dir/flags.make
CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o: /workspaces/OOP_labs_Vasya/lab3/src/figure.cpp
CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o: CMakeFiles/lab3_lib_figure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OOP_labs_Vasya/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o -MF CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o.d -o CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o -c /workspaces/OOP_labs_Vasya/lab3/src/figure.cpp

CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OOP_labs_Vasya/lab3/src/figure.cpp > CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.i

CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OOP_labs_Vasya/lab3/src/figure.cpp -o CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.s

# Object files for target lab3_lib_figure
lab3_lib_figure_OBJECTS = \
"CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o"

# External object files for target lab3_lib_figure
lab3_lib_figure_EXTERNAL_OBJECTS =

liblab3_lib_figure.a: CMakeFiles/lab3_lib_figure.dir/src/figure.cpp.o
liblab3_lib_figure.a: CMakeFiles/lab3_lib_figure.dir/build.make
liblab3_lib_figure.a: CMakeFiles/lab3_lib_figure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/OOP_labs_Vasya/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab3_lib_figure.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lab3_lib_figure.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3_lib_figure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3_lib_figure.dir/build: liblab3_lib_figure.a
.PHONY : CMakeFiles/lab3_lib_figure.dir/build

CMakeFiles/lab3_lib_figure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab3_lib_figure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab3_lib_figure.dir/clean

CMakeFiles/lab3_lib_figure.dir/depend:
	cd /workspaces/OOP_labs_Vasya/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/OOP_labs_Vasya/lab3 /workspaces/OOP_labs_Vasya/lab3 /workspaces/OOP_labs_Vasya/lab3/build /workspaces/OOP_labs_Vasya/lab3/build /workspaces/OOP_labs_Vasya/lab3/build/CMakeFiles/lab3_lib_figure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab3_lib_figure.dir/depend

