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
CMAKE_COMMAND = /opt/clion-2019.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vlad/Desktop/2_year/ACS/lab_2/integrate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlad/Desktop/2_year/ACS/lab_2/integrate/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/integrate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/integrate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/integrate.dir/flags.make

CMakeFiles/integrate.dir/main.cpp.o: CMakeFiles/integrate.dir/flags.make
CMakeFiles/integrate.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/Desktop/2_year/ACS/lab_2/integrate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/integrate.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/integrate.dir/main.cpp.o -c /home/vlad/Desktop/2_year/ACS/lab_2/integrate/main.cpp

CMakeFiles/integrate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/integrate.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/Desktop/2_year/ACS/lab_2/integrate/main.cpp > CMakeFiles/integrate.dir/main.cpp.i

CMakeFiles/integrate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/integrate.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/Desktop/2_year/ACS/lab_2/integrate/main.cpp -o CMakeFiles/integrate.dir/main.cpp.s

# Object files for target integrate
integrate_OBJECTS = \
"CMakeFiles/integrate.dir/main.cpp.o"

# External object files for target integrate
integrate_EXTERNAL_OBJECTS =

integrate: CMakeFiles/integrate.dir/main.cpp.o
integrate: CMakeFiles/integrate.dir/build.make
integrate: CMakeFiles/integrate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlad/Desktop/2_year/ACS/lab_2/integrate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable integrate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/integrate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/integrate.dir/build: integrate

.PHONY : CMakeFiles/integrate.dir/build

CMakeFiles/integrate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/integrate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/integrate.dir/clean

CMakeFiles/integrate.dir/depend:
	cd /home/vlad/Desktop/2_year/ACS/lab_2/integrate/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlad/Desktop/2_year/ACS/lab_2/integrate /home/vlad/Desktop/2_year/ACS/lab_2/integrate /home/vlad/Desktop/2_year/ACS/lab_2/integrate/cmake-build-debug /home/vlad/Desktop/2_year/ACS/lab_2/integrate/cmake-build-debug /home/vlad/Desktop/2_year/ACS/lab_2/integrate/cmake-build-debug/CMakeFiles/integrate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/integrate.dir/depend

