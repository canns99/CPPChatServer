# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/wx/Documents/network/threadPool/threadPool20220615

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wx/Documents/network/threadPool/threadPool20220615/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mysqlPool.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mysqlPool.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mysqlPool.dir/flags.make

src/CMakeFiles/mysqlPool.dir/Connection.cpp.o: src/CMakeFiles/mysqlPool.dir/flags.make
src/CMakeFiles/mysqlPool.dir/Connection.cpp.o: ../src/Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wx/Documents/network/threadPool/threadPool20220615/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mysqlPool.dir/Connection.cpp.o"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mysqlPool.dir/Connection.cpp.o -c /home/wx/Documents/network/threadPool/threadPool20220615/src/Connection.cpp

src/CMakeFiles/mysqlPool.dir/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysqlPool.dir/Connection.cpp.i"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wx/Documents/network/threadPool/threadPool20220615/src/Connection.cpp > CMakeFiles/mysqlPool.dir/Connection.cpp.i

src/CMakeFiles/mysqlPool.dir/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysqlPool.dir/Connection.cpp.s"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wx/Documents/network/threadPool/threadPool20220615/src/Connection.cpp -o CMakeFiles/mysqlPool.dir/Connection.cpp.s

src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.requires:

.PHONY : src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.requires

src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.provides: src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/mysqlPool.dir/build.make src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.provides.build
.PHONY : src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.provides

src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.provides.build: src/CMakeFiles/mysqlPool.dir/Connection.cpp.o


src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o: src/CMakeFiles/mysqlPool.dir/flags.make
src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o: ../src/ConnectionPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wx/Documents/network/threadPool/threadPool20220615/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o -c /home/wx/Documents/network/threadPool/threadPool20220615/src/ConnectionPool.cpp

src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.i"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wx/Documents/network/threadPool/threadPool20220615/src/ConnectionPool.cpp > CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.i

src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.s"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wx/Documents/network/threadPool/threadPool20220615/src/ConnectionPool.cpp -o CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.s

src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.requires:

.PHONY : src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.requires

src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.provides: src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/mysqlPool.dir/build.make src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.provides.build
.PHONY : src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.provides

src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.provides.build: src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o


src/CMakeFiles/mysqlPool.dir/main.cpp.o: src/CMakeFiles/mysqlPool.dir/flags.make
src/CMakeFiles/mysqlPool.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wx/Documents/network/threadPool/threadPool20220615/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mysqlPool.dir/main.cpp.o"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mysqlPool.dir/main.cpp.o -c /home/wx/Documents/network/threadPool/threadPool20220615/src/main.cpp

src/CMakeFiles/mysqlPool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysqlPool.dir/main.cpp.i"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wx/Documents/network/threadPool/threadPool20220615/src/main.cpp > CMakeFiles/mysqlPool.dir/main.cpp.i

src/CMakeFiles/mysqlPool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysqlPool.dir/main.cpp.s"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wx/Documents/network/threadPool/threadPool20220615/src/main.cpp -o CMakeFiles/mysqlPool.dir/main.cpp.s

src/CMakeFiles/mysqlPool.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/mysqlPool.dir/main.cpp.o.requires

src/CMakeFiles/mysqlPool.dir/main.cpp.o.provides: src/CMakeFiles/mysqlPool.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/mysqlPool.dir/build.make src/CMakeFiles/mysqlPool.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/mysqlPool.dir/main.cpp.o.provides

src/CMakeFiles/mysqlPool.dir/main.cpp.o.provides.build: src/CMakeFiles/mysqlPool.dir/main.cpp.o


src/CMakeFiles/mysqlPool.dir/test.cpp.o: src/CMakeFiles/mysqlPool.dir/flags.make
src/CMakeFiles/mysqlPool.dir/test.cpp.o: ../src/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wx/Documents/network/threadPool/threadPool20220615/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/mysqlPool.dir/test.cpp.o"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mysqlPool.dir/test.cpp.o -c /home/wx/Documents/network/threadPool/threadPool20220615/src/test.cpp

src/CMakeFiles/mysqlPool.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysqlPool.dir/test.cpp.i"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wx/Documents/network/threadPool/threadPool20220615/src/test.cpp > CMakeFiles/mysqlPool.dir/test.cpp.i

src/CMakeFiles/mysqlPool.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysqlPool.dir/test.cpp.s"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wx/Documents/network/threadPool/threadPool20220615/src/test.cpp -o CMakeFiles/mysqlPool.dir/test.cpp.s

src/CMakeFiles/mysqlPool.dir/test.cpp.o.requires:

.PHONY : src/CMakeFiles/mysqlPool.dir/test.cpp.o.requires

src/CMakeFiles/mysqlPool.dir/test.cpp.o.provides: src/CMakeFiles/mysqlPool.dir/test.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/mysqlPool.dir/build.make src/CMakeFiles/mysqlPool.dir/test.cpp.o.provides.build
.PHONY : src/CMakeFiles/mysqlPool.dir/test.cpp.o.provides

src/CMakeFiles/mysqlPool.dir/test.cpp.o.provides.build: src/CMakeFiles/mysqlPool.dir/test.cpp.o


# Object files for target mysqlPool
mysqlPool_OBJECTS = \
"CMakeFiles/mysqlPool.dir/Connection.cpp.o" \
"CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o" \
"CMakeFiles/mysqlPool.dir/main.cpp.o" \
"CMakeFiles/mysqlPool.dir/test.cpp.o"

# External object files for target mysqlPool
mysqlPool_EXTERNAL_OBJECTS =

../bin/mysqlPool: src/CMakeFiles/mysqlPool.dir/Connection.cpp.o
../bin/mysqlPool: src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o
../bin/mysqlPool: src/CMakeFiles/mysqlPool.dir/main.cpp.o
../bin/mysqlPool: src/CMakeFiles/mysqlPool.dir/test.cpp.o
../bin/mysqlPool: src/CMakeFiles/mysqlPool.dir/build.make
../bin/mysqlPool: src/CMakeFiles/mysqlPool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wx/Documents/network/threadPool/threadPool20220615/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../../bin/mysqlPool"
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mysqlPool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mysqlPool.dir/build: ../bin/mysqlPool

.PHONY : src/CMakeFiles/mysqlPool.dir/build

src/CMakeFiles/mysqlPool.dir/requires: src/CMakeFiles/mysqlPool.dir/Connection.cpp.o.requires
src/CMakeFiles/mysqlPool.dir/requires: src/CMakeFiles/mysqlPool.dir/ConnectionPool.cpp.o.requires
src/CMakeFiles/mysqlPool.dir/requires: src/CMakeFiles/mysqlPool.dir/main.cpp.o.requires
src/CMakeFiles/mysqlPool.dir/requires: src/CMakeFiles/mysqlPool.dir/test.cpp.o.requires

.PHONY : src/CMakeFiles/mysqlPool.dir/requires

src/CMakeFiles/mysqlPool.dir/clean:
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mysqlPool.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mysqlPool.dir/clean

src/CMakeFiles/mysqlPool.dir/depend:
	cd /home/wx/Documents/network/threadPool/threadPool20220615/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wx/Documents/network/threadPool/threadPool20220615 /home/wx/Documents/network/threadPool/threadPool20220615/src /home/wx/Documents/network/threadPool/threadPool20220615/build /home/wx/Documents/network/threadPool/threadPool20220615/build/src /home/wx/Documents/network/threadPool/threadPool20220615/build/src/CMakeFiles/mysqlPool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mysqlPool.dir/depend

