# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projects\Manikel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\Manikel\build

# Include any dependencies generated for this target.
include CMakeFiles/CalcTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CalcTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CalcTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CalcTests.dir/flags.make

CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj: CMakeFiles/CalcTests.dir/flags.make
CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj: CMakeFiles/CalcTests.dir/includes_CXX.rsp
CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj: C:/Projects/Manikel/tests/test_main.cpp
CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj: CMakeFiles/CalcTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\Manikel\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj -MF CMakeFiles\CalcTests.dir\tests\test_main.cpp.obj.d -o CMakeFiles\CalcTests.dir\tests\test_main.cpp.obj -c C:\Projects\Manikel\tests\test_main.cpp

CMakeFiles/CalcTests.dir/tests/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CalcTests.dir/tests/test_main.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\Manikel\tests\test_main.cpp > CMakeFiles\CalcTests.dir\tests\test_main.cpp.i

CMakeFiles/CalcTests.dir/tests/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CalcTests.dir/tests/test_main.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\Manikel\tests\test_main.cpp -o CMakeFiles\CalcTests.dir\tests\test_main.cpp.s

CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj: CMakeFiles/CalcTests.dir/flags.make
CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj: CMakeFiles/CalcTests.dir/includes_CXX.rsp
CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj: C:/Projects/Manikel/tests/calc_test.cpp
CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj: CMakeFiles/CalcTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\Manikel\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj -MF CMakeFiles\CalcTests.dir\tests\calc_test.cpp.obj.d -o CMakeFiles\CalcTests.dir\tests\calc_test.cpp.obj -c C:\Projects\Manikel\tests\calc_test.cpp

CMakeFiles/CalcTests.dir/tests/calc_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CalcTests.dir/tests/calc_test.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\Manikel\tests\calc_test.cpp > CMakeFiles\CalcTests.dir\tests\calc_test.cpp.i

CMakeFiles/CalcTests.dir/tests/calc_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CalcTests.dir/tests/calc_test.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\Manikel\tests\calc_test.cpp -o CMakeFiles\CalcTests.dir\tests\calc_test.cpp.s

# Object files for target CalcTests
CalcTests_OBJECTS = \
"CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj" \
"CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj"

# External object files for target CalcTests
CalcTests_EXTERNAL_OBJECTS =

CalcTests.exe: CMakeFiles/CalcTests.dir/tests/test_main.cpp.obj
CalcTests.exe: CMakeFiles/CalcTests.dir/tests/calc_test.cpp.obj
CalcTests.exe: CMakeFiles/CalcTests.dir/build.make
CalcTests.exe: lib/libgtest.a
CalcTests.exe: lib/libgtest_main.a
CalcTests.exe: lib/libgtest.a
CalcTests.exe: CMakeFiles/CalcTests.dir/linkLibs.rsp
CalcTests.exe: CMakeFiles/CalcTests.dir/objects1.rsp
CalcTests.exe: CMakeFiles/CalcTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Projects\Manikel\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CalcTests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CalcTests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CalcTests.dir/build: CalcTests.exe
.PHONY : CMakeFiles/CalcTests.dir/build

CMakeFiles/CalcTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CalcTests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CalcTests.dir/clean

CMakeFiles/CalcTests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\Manikel C:\Projects\Manikel C:\Projects\Manikel\build C:\Projects\Manikel\build C:\Projects\Manikel\build\CMakeFiles\CalcTests.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CalcTests.dir/depend

