# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3"

# Include any dependencies generated for this target.
include CMakeFiles/exo3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exo3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exo3.dir/flags.make

CMakeFiles/exo3.dir/main.c.o: CMakeFiles/exo3.dir/flags.make
CMakeFiles/exo3.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exo3.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/exo3.dir/main.c.o   -c "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/main.c"

CMakeFiles/exo3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exo3.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/main.c" > CMakeFiles/exo3.dir/main.c.i

CMakeFiles/exo3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exo3.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/main.c" -o CMakeFiles/exo3.dir/main.c.s

CMakeFiles/exo3.dir/source/DFA.c.o: CMakeFiles/exo3.dir/flags.make
CMakeFiles/exo3.dir/source/DFA.c.o: source/DFA.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/exo3.dir/source/DFA.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/exo3.dir/source/DFA.c.o   -c "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/DFA.c"

CMakeFiles/exo3.dir/source/DFA.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exo3.dir/source/DFA.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/DFA.c" > CMakeFiles/exo3.dir/source/DFA.c.i

CMakeFiles/exo3.dir/source/DFA.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exo3.dir/source/DFA.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/DFA.c" -o CMakeFiles/exo3.dir/source/DFA.c.s

CMakeFiles/exo3.dir/source/DFA_Generalisation.c.o: CMakeFiles/exo3.dir/flags.make
CMakeFiles/exo3.dir/source/DFA_Generalisation.c.o: source/DFA_Generalisation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/exo3.dir/source/DFA_Generalisation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/exo3.dir/source/DFA_Generalisation.c.o   -c "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/DFA_Generalisation.c"

CMakeFiles/exo3.dir/source/DFA_Generalisation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exo3.dir/source/DFA_Generalisation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/DFA_Generalisation.c" > CMakeFiles/exo3.dir/source/DFA_Generalisation.c.i

CMakeFiles/exo3.dir/source/DFA_Generalisation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exo3.dir/source/DFA_Generalisation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/DFA_Generalisation.c" -o CMakeFiles/exo3.dir/source/DFA_Generalisation.c.s

CMakeFiles/exo3.dir/source/exo3_1.c.o: CMakeFiles/exo3.dir/flags.make
CMakeFiles/exo3.dir/source/exo3_1.c.o: source/exo3_1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/exo3.dir/source/exo3_1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/exo3.dir/source/exo3_1.c.o   -c "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/exo3_1.c"

CMakeFiles/exo3.dir/source/exo3_1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exo3.dir/source/exo3_1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/exo3_1.c" > CMakeFiles/exo3.dir/source/exo3_1.c.i

CMakeFiles/exo3.dir/source/exo3_1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exo3.dir/source/exo3_1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/exo3_1.c" -o CMakeFiles/exo3.dir/source/exo3_1.c.s

CMakeFiles/exo3.dir/source/exo3_2.c.o: CMakeFiles/exo3.dir/flags.make
CMakeFiles/exo3.dir/source/exo3_2.c.o: source/exo3_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/exo3.dir/source/exo3_2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/exo3.dir/source/exo3_2.c.o   -c "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/exo3_2.c"

CMakeFiles/exo3.dir/source/exo3_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exo3.dir/source/exo3_2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/exo3_2.c" > CMakeFiles/exo3.dir/source/exo3_2.c.i

CMakeFiles/exo3.dir/source/exo3_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exo3.dir/source/exo3_2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/source/exo3_2.c" -o CMakeFiles/exo3.dir/source/exo3_2.c.s

# Object files for target exo3
exo3_OBJECTS = \
"CMakeFiles/exo3.dir/main.c.o" \
"CMakeFiles/exo3.dir/source/DFA.c.o" \
"CMakeFiles/exo3.dir/source/DFA_Generalisation.c.o" \
"CMakeFiles/exo3.dir/source/exo3_1.c.o" \
"CMakeFiles/exo3.dir/source/exo3_2.c.o"

# External object files for target exo3
exo3_EXTERNAL_OBJECTS =

exo3: CMakeFiles/exo3.dir/main.c.o
exo3: CMakeFiles/exo3.dir/source/DFA.c.o
exo3: CMakeFiles/exo3.dir/source/DFA_Generalisation.c.o
exo3: CMakeFiles/exo3.dir/source/exo3_1.c.o
exo3: CMakeFiles/exo3.dir/source/exo3_2.c.o
exo3: CMakeFiles/exo3.dir/build.make
exo3: CMakeFiles/exo3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable exo3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exo3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exo3.dir/build: exo3

.PHONY : CMakeFiles/exo3.dir/build

CMakeFiles/exo3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exo3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exo3.dir/clean

CMakeFiles/exo3.dir/depend:
	cd "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3" "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3" "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3" "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3" "/home/noutcheu/Documents/Info Master 1/Compilation/TP/exo3/CMakeFiles/exo3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/exo3.dir/depend

