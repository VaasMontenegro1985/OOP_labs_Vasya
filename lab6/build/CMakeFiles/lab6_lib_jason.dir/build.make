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
CMAKE_SOURCE_DIR = /workspaces/OOP_labs_Vasya/lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/OOP_labs_Vasya/lab6/build

# Include any dependencies generated for this target.
include CMakeFiles/lab6_lib_jason.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab6_lib_jason.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6_lib_jason.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6_lib_jason.dir/flags.make

CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o: CMakeFiles/lab6_lib_jason.dir/flags.make
CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o: /workspaces/OOP_labs_Vasya/lab6/src/jason.cpp
CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o: CMakeFiles/lab6_lib_jason.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OOP_labs_Vasya/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o -MF CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o.d -o CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o -c /workspaces/OOP_labs_Vasya/lab6/src/jason.cpp

CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OOP_labs_Vasya/lab6/src/jason.cpp > CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.i

CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OOP_labs_Vasya/lab6/src/jason.cpp -o CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.s

# Object files for target lab6_lib_jason
lab6_lib_jason_OBJECTS = \
"CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o"

# External object files for target lab6_lib_jason
lab6_lib_jason_EXTERNAL_OBJECTS =

liblab6_lib_jason.a: CMakeFiles/lab6_lib_jason.dir/src/jason.cpp.o
liblab6_lib_jason.a: CMakeFiles/lab6_lib_jason.dir/build.make
liblab6_lib_jason.a: CMakeFiles/lab6_lib_jason.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/OOP_labs_Vasya/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab6_lib_jason.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lab6_lib_jason.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab6_lib_jason.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6_lib_jason.dir/build: liblab6_lib_jason.a
.PHONY : CMakeFiles/lab6_lib_jason.dir/build

CMakeFiles/lab6_lib_jason.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab6_lib_jason.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab6_lib_jason.dir/clean

CMakeFiles/lab6_lib_jason.dir/depend:
	cd /workspaces/OOP_labs_Vasya/lab6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/OOP_labs_Vasya/lab6 /workspaces/OOP_labs_Vasya/lab6 /workspaces/OOP_labs_Vasya/lab6/build /workspaces/OOP_labs_Vasya/lab6/build /workspaces/OOP_labs_Vasya/lab6/build/CMakeFiles/lab6_lib_jason.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab6_lib_jason.dir/depend

