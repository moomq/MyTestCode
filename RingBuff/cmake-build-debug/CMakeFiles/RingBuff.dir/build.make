# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RingBuff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RingBuff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RingBuff.dir/flags.make

CMakeFiles/RingBuff.dir/main.cpp.obj: CMakeFiles/RingBuff.dir/flags.make
CMakeFiles/RingBuff.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RingBuff.dir/main.cpp.obj"
	C:\Msys2\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RingBuff.dir\main.cpp.obj -c H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\main.cpp

CMakeFiles/RingBuff.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RingBuff.dir/main.cpp.i"
	C:\Msys2\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\main.cpp > CMakeFiles\RingBuff.dir\main.cpp.i

CMakeFiles/RingBuff.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RingBuff.dir/main.cpp.s"
	C:\Msys2\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\main.cpp -o CMakeFiles\RingBuff.dir\main.cpp.s

CMakeFiles/RingBuff.dir/ringbuff.cpp.obj: CMakeFiles/RingBuff.dir/flags.make
CMakeFiles/RingBuff.dir/ringbuff.cpp.obj: ../ringbuff.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RingBuff.dir/ringbuff.cpp.obj"
	C:\Msys2\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RingBuff.dir\ringbuff.cpp.obj -c H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\ringbuff.cpp

CMakeFiles/RingBuff.dir/ringbuff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RingBuff.dir/ringbuff.cpp.i"
	C:\Msys2\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\ringbuff.cpp > CMakeFiles\RingBuff.dir\ringbuff.cpp.i

CMakeFiles/RingBuff.dir/ringbuff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RingBuff.dir/ringbuff.cpp.s"
	C:\Msys2\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\ringbuff.cpp -o CMakeFiles\RingBuff.dir\ringbuff.cpp.s

# Object files for target RingBuff
RingBuff_OBJECTS = \
"CMakeFiles/RingBuff.dir/main.cpp.obj" \
"CMakeFiles/RingBuff.dir/ringbuff.cpp.obj"

# External object files for target RingBuff
RingBuff_EXTERNAL_OBJECTS =

RingBuff.exe: CMakeFiles/RingBuff.dir/main.cpp.obj
RingBuff.exe: CMakeFiles/RingBuff.dir/ringbuff.cpp.obj
RingBuff.exe: CMakeFiles/RingBuff.dir/build.make
RingBuff.exe: CMakeFiles/RingBuff.dir/linklibs.rsp
RingBuff.exe: CMakeFiles/RingBuff.dir/objects1.rsp
RingBuff.exe: CMakeFiles/RingBuff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable RingBuff.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RingBuff.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RingBuff.dir/build: RingBuff.exe

.PHONY : CMakeFiles/RingBuff.dir/build

CMakeFiles/RingBuff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RingBuff.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RingBuff.dir/clean

CMakeFiles/RingBuff.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\cmake-build-debug H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\cmake-build-debug H:\GitResponsity\MyGitRepository\MyTestCode\RingBuff\cmake-build-debug\CMakeFiles\RingBuff.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RingBuff.dir/depend
