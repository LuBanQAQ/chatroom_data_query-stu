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
CMAKE_SOURCE_DIR = /home/cst/chatroom_data_query-stu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cst/chatroom_data_query-stu/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ChatRoomManage.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ChatRoomManage.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ChatRoomManage.dir/flags.make

src/CMakeFiles/ChatRoomManage.dir/main.cpp.o: src/CMakeFiles/ChatRoomManage.dir/flags.make
src/CMakeFiles/ChatRoomManage.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cst/chatroom_data_query-stu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ChatRoomManage.dir/main.cpp.o"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChatRoomManage.dir/main.cpp.o -c /home/cst/chatroom_data_query-stu/src/main.cpp

src/CMakeFiles/ChatRoomManage.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatRoomManage.dir/main.cpp.i"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cst/chatroom_data_query-stu/src/main.cpp > CMakeFiles/ChatRoomManage.dir/main.cpp.i

src/CMakeFiles/ChatRoomManage.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatRoomManage.dir/main.cpp.s"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cst/chatroom_data_query-stu/src/main.cpp -o CMakeFiles/ChatRoomManage.dir/main.cpp.s

src/CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.o: src/CMakeFiles/ChatRoomManage.dir/flags.make
src/CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.o: ../src/db/mysql.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cst/chatroom_data_query-stu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.o"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.o -c /home/cst/chatroom_data_query-stu/src/db/mysql.cpp

src/CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.i"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cst/chatroom_data_query-stu/src/db/mysql.cpp > CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.i

src/CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.s"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cst/chatroom_data_query-stu/src/db/mysql.cpp -o CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.s

src/CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.o: src/CMakeFiles/ChatRoomManage.dir/flags.make
src/CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.o: ../src/model/friendmoel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cst/chatroom_data_query-stu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.o"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.o -c /home/cst/chatroom_data_query-stu/src/model/friendmoel.cpp

src/CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.i"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cst/chatroom_data_query-stu/src/model/friendmoel.cpp > CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.i

src/CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.s"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cst/chatroom_data_query-stu/src/model/friendmoel.cpp -o CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.s

src/CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.o: src/CMakeFiles/ChatRoomManage.dir/flags.make
src/CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.o: ../src/model/groupmodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cst/chatroom_data_query-stu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.o"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.o -c /home/cst/chatroom_data_query-stu/src/model/groupmodel.cpp

src/CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.i"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cst/chatroom_data_query-stu/src/model/groupmodel.cpp > CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.i

src/CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.s"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cst/chatroom_data_query-stu/src/model/groupmodel.cpp -o CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.s

src/CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.o: src/CMakeFiles/ChatRoomManage.dir/flags.make
src/CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.o: ../src/model/offlinemessagemodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cst/chatroom_data_query-stu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.o"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.o -c /home/cst/chatroom_data_query-stu/src/model/offlinemessagemodel.cpp

src/CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.i"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cst/chatroom_data_query-stu/src/model/offlinemessagemodel.cpp > CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.i

src/CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.s"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cst/chatroom_data_query-stu/src/model/offlinemessagemodel.cpp -o CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.s

src/CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.o: src/CMakeFiles/ChatRoomManage.dir/flags.make
src/CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.o: ../src/model/usermodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cst/chatroom_data_query-stu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.o"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.o -c /home/cst/chatroom_data_query-stu/src/model/usermodel.cpp

src/CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.i"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cst/chatroom_data_query-stu/src/model/usermodel.cpp > CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.i

src/CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.s"
	cd /home/cst/chatroom_data_query-stu/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cst/chatroom_data_query-stu/src/model/usermodel.cpp -o CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.s

# Object files for target ChatRoomManage
ChatRoomManage_OBJECTS = \
"CMakeFiles/ChatRoomManage.dir/main.cpp.o" \
"CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.o" \
"CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.o" \
"CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.o" \
"CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.o" \
"CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.o"

# External object files for target ChatRoomManage
ChatRoomManage_EXTERNAL_OBJECTS =

../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/main.cpp.o
../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/db/mysql.cpp.o
../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/model/friendmoel.cpp.o
../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/model/groupmodel.cpp.o
../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/model/offlinemessagemodel.cpp.o
../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/model/usermodel.cpp.o
../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/build.make
../bin/ChatRoomManage: src/CMakeFiles/ChatRoomManage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cst/chatroom_data_query-stu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../../bin/ChatRoomManage"
	cd /home/cst/chatroom_data_query-stu/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChatRoomManage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ChatRoomManage.dir/build: ../bin/ChatRoomManage

.PHONY : src/CMakeFiles/ChatRoomManage.dir/build

src/CMakeFiles/ChatRoomManage.dir/clean:
	cd /home/cst/chatroom_data_query-stu/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ChatRoomManage.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ChatRoomManage.dir/clean

src/CMakeFiles/ChatRoomManage.dir/depend:
	cd /home/cst/chatroom_data_query-stu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cst/chatroom_data_query-stu /home/cst/chatroom_data_query-stu/src /home/cst/chatroom_data_query-stu/build /home/cst/chatroom_data_query-stu/build/src /home/cst/chatroom_data_query-stu/build/src/CMakeFiles/ChatRoomManage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ChatRoomManage.dir/depend

