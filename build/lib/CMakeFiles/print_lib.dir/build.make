# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nano1/test/cmake_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nano1/test/cmake_test/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/print_lib.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/print_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/print_lib.dir/flags.make

lib/CMakeFiles/print_lib.dir/print/print.cpp.o: lib/CMakeFiles/print_lib.dir/flags.make
lib/CMakeFiles/print_lib.dir/print/print.cpp.o: ../lib/print/print.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nano1/test/cmake_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/print_lib.dir/print/print.cpp.o"
	cd /home/nano1/test/cmake_test/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/print_lib.dir/print/print.cpp.o -c /home/nano1/test/cmake_test/lib/print/print.cpp

lib/CMakeFiles/print_lib.dir/print/print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/print_lib.dir/print/print.cpp.i"
	cd /home/nano1/test/cmake_test/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nano1/test/cmake_test/lib/print/print.cpp > CMakeFiles/print_lib.dir/print/print.cpp.i

lib/CMakeFiles/print_lib.dir/print/print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/print_lib.dir/print/print.cpp.s"
	cd /home/nano1/test/cmake_test/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nano1/test/cmake_test/lib/print/print.cpp -o CMakeFiles/print_lib.dir/print/print.cpp.s

lib/CMakeFiles/print_lib.dir/print/print.cpp.o.requires:

.PHONY : lib/CMakeFiles/print_lib.dir/print/print.cpp.o.requires

lib/CMakeFiles/print_lib.dir/print/print.cpp.o.provides: lib/CMakeFiles/print_lib.dir/print/print.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/print_lib.dir/build.make lib/CMakeFiles/print_lib.dir/print/print.cpp.o.provides.build
.PHONY : lib/CMakeFiles/print_lib.dir/print/print.cpp.o.provides

lib/CMakeFiles/print_lib.dir/print/print.cpp.o.provides.build: lib/CMakeFiles/print_lib.dir/print/print.cpp.o


# Object files for target print_lib
print_lib_OBJECTS = \
"CMakeFiles/print_lib.dir/print/print.cpp.o"

# External object files for target print_lib
print_lib_EXTERNAL_OBJECTS =

lib/libprint_lib.a: lib/CMakeFiles/print_lib.dir/print/print.cpp.o
lib/libprint_lib.a: lib/CMakeFiles/print_lib.dir/build.make
lib/libprint_lib.a: lib/CMakeFiles/print_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nano1/test/cmake_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libprint_lib.a"
	cd /home/nano1/test/cmake_test/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/print_lib.dir/cmake_clean_target.cmake
	cd /home/nano1/test/cmake_test/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/print_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/print_lib.dir/build: lib/libprint_lib.a

.PHONY : lib/CMakeFiles/print_lib.dir/build

lib/CMakeFiles/print_lib.dir/requires: lib/CMakeFiles/print_lib.dir/print/print.cpp.o.requires

.PHONY : lib/CMakeFiles/print_lib.dir/requires

lib/CMakeFiles/print_lib.dir/clean:
	cd /home/nano1/test/cmake_test/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/print_lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/print_lib.dir/clean

lib/CMakeFiles/print_lib.dir/depend:
	cd /home/nano1/test/cmake_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nano1/test/cmake_test /home/nano1/test/cmake_test/lib /home/nano1/test/cmake_test/build /home/nano1/test/cmake_test/build/lib /home/nano1/test/cmake_test/build/lib/CMakeFiles/print_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/print_lib.dir/depend

