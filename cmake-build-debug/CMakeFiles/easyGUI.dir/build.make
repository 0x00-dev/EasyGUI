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
CMAKE_COMMAND = /home/strannyi_tip/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6494.38/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/strannyi_tip/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6494.38/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/strannyi_tip/dev/easyGUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/strannyi_tip/dev/easyGUI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/easyGUI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/easyGUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/easyGUI.dir/flags.make

CMakeFiles/easyGUI.dir/main.cpp.o: CMakeFiles/easyGUI.dir/flags.make
CMakeFiles/easyGUI.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strannyi_tip/dev/easyGUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/easyGUI.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/easyGUI.dir/main.cpp.o -c /home/strannyi_tip/dev/easyGUI/main.cpp

CMakeFiles/easyGUI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/easyGUI.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/strannyi_tip/dev/easyGUI/main.cpp > CMakeFiles/easyGUI.dir/main.cpp.i

CMakeFiles/easyGUI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/easyGUI.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/strannyi_tip/dev/easyGUI/main.cpp -o CMakeFiles/easyGUI.dir/main.cpp.s

CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.o: CMakeFiles/easyGUI.dir/flags.make
CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.o: ../src/Window/ModalWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strannyi_tip/dev/easyGUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.o -c /home/strannyi_tip/dev/easyGUI/src/Window/ModalWindow.cpp

CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/strannyi_tip/dev/easyGUI/src/Window/ModalWindow.cpp > CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.i

CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/strannyi_tip/dev/easyGUI/src/Window/ModalWindow.cpp -o CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.s

CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.o: CMakeFiles/easyGUI.dir/flags.make
CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.o: ../src/Core/Messenger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strannyi_tip/dev/easyGUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.o -c /home/strannyi_tip/dev/easyGUI/src/Core/Messenger.cpp

CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/strannyi_tip/dev/easyGUI/src/Core/Messenger.cpp > CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.i

CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/strannyi_tip/dev/easyGUI/src/Core/Messenger.cpp -o CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.s

CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.o: CMakeFiles/easyGUI.dir/flags.make
CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.o: ../src/Controls/Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/strannyi_tip/dev/easyGUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.o -c /home/strannyi_tip/dev/easyGUI/src/Controls/Button.cpp

CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/strannyi_tip/dev/easyGUI/src/Controls/Button.cpp > CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.i

CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/strannyi_tip/dev/easyGUI/src/Controls/Button.cpp -o CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.s

# Object files for target easyGUI
easyGUI_OBJECTS = \
"CMakeFiles/easyGUI.dir/main.cpp.o" \
"CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.o" \
"CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.o" \
"CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.o"

# External object files for target easyGUI
easyGUI_EXTERNAL_OBJECTS =

easyGUI: CMakeFiles/easyGUI.dir/main.cpp.o
easyGUI: CMakeFiles/easyGUI.dir/src/Window/ModalWindow.cpp.o
easyGUI: CMakeFiles/easyGUI.dir/src/Core/Messenger.cpp.o
easyGUI: CMakeFiles/easyGUI.dir/src/Controls/Button.cpp.o
easyGUI: CMakeFiles/easyGUI.dir/build.make
easyGUI: /home/strannyi_tip/lib/SFML-2.5.1/lib/libsfml-network.so.2.5.1
easyGUI: /home/strannyi_tip/lib/SFML-2.5.1/lib/libsfml-graphics.so.2.5.1
easyGUI: /home/strannyi_tip/lib/SFML-2.5.1/lib/libsfml-window.so.2.5.1
easyGUI: /home/strannyi_tip/lib/SFML-2.5.1/lib/libsfml-system.so.2.5.1
easyGUI: CMakeFiles/easyGUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/strannyi_tip/dev/easyGUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable easyGUI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/easyGUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/easyGUI.dir/build: easyGUI

.PHONY : CMakeFiles/easyGUI.dir/build

CMakeFiles/easyGUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/easyGUI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/easyGUI.dir/clean

CMakeFiles/easyGUI.dir/depend:
	cd /home/strannyi_tip/dev/easyGUI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/strannyi_tip/dev/easyGUI /home/strannyi_tip/dev/easyGUI /home/strannyi_tip/dev/easyGUI/cmake-build-debug /home/strannyi_tip/dev/easyGUI/cmake-build-debug /home/strannyi_tip/dev/easyGUI/cmake-build-debug/CMakeFiles/easyGUI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/easyGUI.dir/depend
