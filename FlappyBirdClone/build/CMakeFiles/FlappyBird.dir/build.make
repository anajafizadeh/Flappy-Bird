# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amirali/Desktop/FlappyBirdClone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amirali/Desktop/FlappyBirdClone/build

# Include any dependencies generated for this target.
include CMakeFiles/FlappyBird.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FlappyBird.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FlappyBird.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FlappyBird.dir/flags.make

CMakeFiles/FlappyBird.dir/main.cpp.o: CMakeFiles/FlappyBird.dir/flags.make
CMakeFiles/FlappyBird.dir/main.cpp.o: /Users/amirali/Desktop/FlappyBirdClone/main.cpp
CMakeFiles/FlappyBird.dir/main.cpp.o: CMakeFiles/FlappyBird.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/amirali/Desktop/FlappyBirdClone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FlappyBird.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FlappyBird.dir/main.cpp.o -MF CMakeFiles/FlappyBird.dir/main.cpp.o.d -o CMakeFiles/FlappyBird.dir/main.cpp.o -c /Users/amirali/Desktop/FlappyBirdClone/main.cpp

CMakeFiles/FlappyBird.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FlappyBird.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amirali/Desktop/FlappyBirdClone/main.cpp > CMakeFiles/FlappyBird.dir/main.cpp.i

CMakeFiles/FlappyBird.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FlappyBird.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amirali/Desktop/FlappyBirdClone/main.cpp -o CMakeFiles/FlappyBird.dir/main.cpp.s

# Object files for target FlappyBird
FlappyBird_OBJECTS = \
"CMakeFiles/FlappyBird.dir/main.cpp.o"

# External object files for target FlappyBird
FlappyBird_EXTERNAL_OBJECTS =

FlappyBird: CMakeFiles/FlappyBird.dir/main.cpp.o
FlappyBird: CMakeFiles/FlappyBird.dir/build.make
FlappyBird: /usr/local/lib/libsfml-graphics.2.6.1.dylib
FlappyBird: /usr/local/lib/libsfml-audio.2.6.1.dylib
FlappyBird: /usr/local/lib/libsfml-window.2.6.1.dylib
FlappyBird: /usr/local/lib/libsfml-system.2.6.1.dylib
FlappyBird: CMakeFiles/FlappyBird.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/amirali/Desktop/FlappyBirdClone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FlappyBird"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FlappyBird.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FlappyBird.dir/build: FlappyBird
.PHONY : CMakeFiles/FlappyBird.dir/build

CMakeFiles/FlappyBird.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FlappyBird.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FlappyBird.dir/clean

CMakeFiles/FlappyBird.dir/depend:
	cd /Users/amirali/Desktop/FlappyBirdClone/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amirali/Desktop/FlappyBirdClone /Users/amirali/Desktop/FlappyBirdClone /Users/amirali/Desktop/FlappyBirdClone/build /Users/amirali/Desktop/FlappyBirdClone/build /Users/amirali/Desktop/FlappyBirdClone/build/CMakeFiles/FlappyBird.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FlappyBird.dir/depend
