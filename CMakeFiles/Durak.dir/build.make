# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/user/ECE350Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/ECE350Final

# Include any dependencies generated for this target.
include CMakeFiles/Durak.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Durak.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Durak.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Durak.dir/flags.make

CMakeFiles/Durak.dir/src/main.cpp.o: CMakeFiles/Durak.dir/flags.make
CMakeFiles/Durak.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/Durak.dir/src/main.cpp.o: CMakeFiles/Durak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ECE350Final/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Durak.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Durak.dir/src/main.cpp.o -MF CMakeFiles/Durak.dir/src/main.cpp.o.d -o CMakeFiles/Durak.dir/src/main.cpp.o -c /home/user/ECE350Final/src/main.cpp

CMakeFiles/Durak.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Durak.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ECE350Final/src/main.cpp > CMakeFiles/Durak.dir/src/main.cpp.i

CMakeFiles/Durak.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Durak.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ECE350Final/src/main.cpp -o CMakeFiles/Durak.dir/src/main.cpp.s

CMakeFiles/Durak.dir/src/Card.cpp.o: CMakeFiles/Durak.dir/flags.make
CMakeFiles/Durak.dir/src/Card.cpp.o: src/Card.cpp
CMakeFiles/Durak.dir/src/Card.cpp.o: CMakeFiles/Durak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ECE350Final/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Durak.dir/src/Card.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Durak.dir/src/Card.cpp.o -MF CMakeFiles/Durak.dir/src/Card.cpp.o.d -o CMakeFiles/Durak.dir/src/Card.cpp.o -c /home/user/ECE350Final/src/Card.cpp

CMakeFiles/Durak.dir/src/Card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Durak.dir/src/Card.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ECE350Final/src/Card.cpp > CMakeFiles/Durak.dir/src/Card.cpp.i

CMakeFiles/Durak.dir/src/Card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Durak.dir/src/Card.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ECE350Final/src/Card.cpp -o CMakeFiles/Durak.dir/src/Card.cpp.s

CMakeFiles/Durak.dir/src/Deck.cpp.o: CMakeFiles/Durak.dir/flags.make
CMakeFiles/Durak.dir/src/Deck.cpp.o: src/Deck.cpp
CMakeFiles/Durak.dir/src/Deck.cpp.o: CMakeFiles/Durak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ECE350Final/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Durak.dir/src/Deck.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Durak.dir/src/Deck.cpp.o -MF CMakeFiles/Durak.dir/src/Deck.cpp.o.d -o CMakeFiles/Durak.dir/src/Deck.cpp.o -c /home/user/ECE350Final/src/Deck.cpp

CMakeFiles/Durak.dir/src/Deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Durak.dir/src/Deck.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ECE350Final/src/Deck.cpp > CMakeFiles/Durak.dir/src/Deck.cpp.i

CMakeFiles/Durak.dir/src/Deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Durak.dir/src/Deck.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ECE350Final/src/Deck.cpp -o CMakeFiles/Durak.dir/src/Deck.cpp.s

# Object files for target Durak
Durak_OBJECTS = \
"CMakeFiles/Durak.dir/src/main.cpp.o" \
"CMakeFiles/Durak.dir/src/Card.cpp.o" \
"CMakeFiles/Durak.dir/src/Deck.cpp.o"

# External object files for target Durak
Durak_EXTERNAL_OBJECTS =

Durak: CMakeFiles/Durak.dir/src/main.cpp.o
Durak: CMakeFiles/Durak.dir/src/Card.cpp.o
Durak: CMakeFiles/Durak.dir/src/Deck.cpp.o
Durak: CMakeFiles/Durak.dir/build.make
Durak: CMakeFiles/Durak.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/ECE350Final/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Durak"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Durak.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Durak.dir/build: Durak
.PHONY : CMakeFiles/Durak.dir/build

CMakeFiles/Durak.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Durak.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Durak.dir/clean

CMakeFiles/Durak.dir/depend:
	cd /home/user/ECE350Final && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/ECE350Final /home/user/ECE350Final /home/user/ECE350Final /home/user/ECE350Final /home/user/ECE350Final/CMakeFiles/Durak.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Durak.dir/depend

