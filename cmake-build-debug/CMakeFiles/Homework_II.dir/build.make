# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/70/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/akif/Projects/CLionProjects/HomeworkII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/akif/Projects/CLionProjects/HomeworkII/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Homework_II.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Homework_II.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Homework_II.dir/flags.make

CMakeFiles/Homework_II.dir/main.cpp.o: CMakeFiles/Homework_II.dir/flags.make
CMakeFiles/Homework_II.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akif/Projects/CLionProjects/HomeworkII/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Homework_II.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework_II.dir/main.cpp.o -c /home/akif/Projects/CLionProjects/HomeworkII/main.cpp

CMakeFiles/Homework_II.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework_II.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/akif/Projects/CLionProjects/HomeworkII/main.cpp > CMakeFiles/Homework_II.dir/main.cpp.i

CMakeFiles/Homework_II.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework_II.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/akif/Projects/CLionProjects/HomeworkII/main.cpp -o CMakeFiles/Homework_II.dir/main.cpp.s

# Object files for target Homework_II
Homework_II_OBJECTS = \
"CMakeFiles/Homework_II.dir/main.cpp.o"

# External object files for target Homework_II
Homework_II_EXTERNAL_OBJECTS =

Homework_II: CMakeFiles/Homework_II.dir/main.cpp.o
Homework_II: CMakeFiles/Homework_II.dir/build.make
Homework_II: CMakeFiles/Homework_II.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/akif/Projects/CLionProjects/HomeworkII/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Homework_II"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Homework_II.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Homework_II.dir/build: Homework_II

.PHONY : CMakeFiles/Homework_II.dir/build

CMakeFiles/Homework_II.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Homework_II.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Homework_II.dir/clean

CMakeFiles/Homework_II.dir/depend:
	cd /home/akif/Projects/CLionProjects/HomeworkII/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/akif/Projects/CLionProjects/HomeworkII /home/akif/Projects/CLionProjects/HomeworkII /home/akif/Projects/CLionProjects/HomeworkII/cmake-build-debug /home/akif/Projects/CLionProjects/HomeworkII/cmake-build-debug /home/akif/Projects/CLionProjects/HomeworkII/cmake-build-debug/CMakeFiles/Homework_II.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Homework_II.dir/depend

