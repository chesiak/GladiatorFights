# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aleksandra/CLionProjects/P2/BaCa/Zad_E

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Zad_E.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Zad_E.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Zad_E.dir/flags.make

CMakeFiles/Zad_E.dir/main.cpp.o: CMakeFiles/Zad_E.dir/flags.make
CMakeFiles/Zad_E.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aleksandra/CLionProjects/P2/BaCa/Zad_E/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Zad_E.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Zad_E.dir/main.cpp.o -c /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/main.cpp

CMakeFiles/Zad_E.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Zad_E.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/main.cpp > CMakeFiles/Zad_E.dir/main.cpp.i

CMakeFiles/Zad_E.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Zad_E.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/main.cpp -o CMakeFiles/Zad_E.dir/main.cpp.s

# Object files for target Zad_E
Zad_E_OBJECTS = \
"CMakeFiles/Zad_E.dir/main.cpp.o"

# External object files for target Zad_E
Zad_E_EXTERNAL_OBJECTS =

Zad_E: CMakeFiles/Zad_E.dir/main.cpp.o
Zad_E: CMakeFiles/Zad_E.dir/build.make
Zad_E: CMakeFiles/Zad_E.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aleksandra/CLionProjects/P2/BaCa/Zad_E/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Zad_E"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Zad_E.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Zad_E.dir/build: Zad_E

.PHONY : CMakeFiles/Zad_E.dir/build

CMakeFiles/Zad_E.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Zad_E.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Zad_E.dir/clean

CMakeFiles/Zad_E.dir/depend:
	cd /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aleksandra/CLionProjects/P2/BaCa/Zad_E /home/aleksandra/CLionProjects/P2/BaCa/Zad_E /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/cmake-build-debug /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/cmake-build-debug /home/aleksandra/CLionProjects/P2/BaCa/Zad_E/cmake-build-debug/CMakeFiles/Zad_E.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Zad_E.dir/depend
