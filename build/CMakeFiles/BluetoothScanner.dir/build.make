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
CMAKE_SOURCE_DIR = /home/maximos/mDrop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maximos/mDrop/build

# Include any dependencies generated for this target.
include CMakeFiles/BluetoothScanner.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BluetoothScanner.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BluetoothScanner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BluetoothScanner.dir/flags.make

CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o: CMakeFiles/BluetoothScanner.dir/flags.make
CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o: ../src/Main/Main.cpp
CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o: CMakeFiles/BluetoothScanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maximos/mDrop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o -MF CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o.d -o CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o -c /home/maximos/mDrop/src/Main/Main.cpp

CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maximos/mDrop/src/Main/Main.cpp > CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.i

CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maximos/mDrop/src/Main/Main.cpp -o CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.s

CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o: CMakeFiles/BluetoothScanner.dir/flags.make
CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o: ../src/Bluetooth/BluetoothDeviceManager.cpp
CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o: CMakeFiles/BluetoothScanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maximos/mDrop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o -MF CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o.d -o CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o -c /home/maximos/mDrop/src/Bluetooth/BluetoothDeviceManager.cpp

CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maximos/mDrop/src/Bluetooth/BluetoothDeviceManager.cpp > CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.i

CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maximos/mDrop/src/Bluetooth/BluetoothDeviceManager.cpp -o CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.s

CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o: CMakeFiles/BluetoothScanner.dir/flags.make
CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o: ../src/Logger/Logger.cpp
CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o: CMakeFiles/BluetoothScanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maximos/mDrop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o -MF CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o.d -o CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o -c /home/maximos/mDrop/src/Logger/Logger.cpp

CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maximos/mDrop/src/Logger/Logger.cpp > CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.i

CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maximos/mDrop/src/Logger/Logger.cpp -o CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.s

# Object files for target BluetoothScanner
BluetoothScanner_OBJECTS = \
"CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o" \
"CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o" \
"CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o"

# External object files for target BluetoothScanner
BluetoothScanner_EXTERNAL_OBJECTS =

BluetoothScanner: CMakeFiles/BluetoothScanner.dir/src/Main/Main.cpp.o
BluetoothScanner: CMakeFiles/BluetoothScanner.dir/src/Bluetooth/BluetoothDeviceManager.cpp.o
BluetoothScanner: CMakeFiles/BluetoothScanner.dir/src/Logger/Logger.cpp.o
BluetoothScanner: CMakeFiles/BluetoothScanner.dir/build.make
BluetoothScanner: CMakeFiles/BluetoothScanner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maximos/mDrop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable BluetoothScanner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BluetoothScanner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BluetoothScanner.dir/build: BluetoothScanner
.PHONY : CMakeFiles/BluetoothScanner.dir/build

CMakeFiles/BluetoothScanner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BluetoothScanner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BluetoothScanner.dir/clean

CMakeFiles/BluetoothScanner.dir/depend:
	cd /home/maximos/mDrop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maximos/mDrop /home/maximos/mDrop /home/maximos/mDrop/build /home/maximos/mDrop/build /home/maximos/mDrop/build/CMakeFiles/BluetoothScanner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BluetoothScanner.dir/depend

