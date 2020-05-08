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
CMAKE_SOURCE_DIR = /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp

# Include any dependencies generated for this target.
include mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/depend.make

# Include the progress variables for this target.
include mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/progress.make

# Include the compile flags for this target's objects.
include mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o: mpp/legacy/vpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rockchip_vpu_static.dir/vpu.c.o   -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu.c

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rockchip_vpu_static.dir/vpu.c.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu.c > CMakeFiles/rockchip_vpu_static.dir/vpu.c.i

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rockchip_vpu_static.dir/vpu.c.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu.c -o CMakeFiles/rockchip_vpu_static.dir/vpu.c.s

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.requires:

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.provides: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.requires
	$(MAKE) -f mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.provides.build
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.provides

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.provides.build: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o


mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o: mpp/legacy/vpu_api.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_api.cpp

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_api.cpp > CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.i

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_api.cpp -o CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.s

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.requires:

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.provides: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.requires
	$(MAKE) -f mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.provides.build
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.provides

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.provides.build: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o


mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o: mpp/legacy/vpu_api_legacy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_api_legacy.cpp

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_api_legacy.cpp > CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.i

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_api_legacy.cpp -o CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.s

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.requires:

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.provides: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.requires
	$(MAKE) -f mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.provides.build
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.provides

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.provides.build: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o


mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o: mpp/legacy/vpu_mem_legacy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o   -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_mem_legacy.c

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_mem_legacy.c > CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.i

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/vpu_mem_legacy.c -o CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.s

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.requires:

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.provides: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.requires
	$(MAKE) -f mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.provides.build
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.provides

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.provides.build: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o


mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o: mpp/legacy/rk_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/rk_list.cpp

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/rk_list.cpp > CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.i

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/rk_list.cpp -o CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.s

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.requires:

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.provides: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.requires
	$(MAKE) -f mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.provides.build
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.provides

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.provides.build: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o


mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o: mpp/legacy/ppOp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/ppOp.cpp

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/ppOp.cpp > CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.i

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/ppOp.cpp -o CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.s

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.requires:

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.provides: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.requires
	$(MAKE) -f mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.provides.build
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.provides

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.provides.build: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o


mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/flags.make
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o: mpp/mpp_info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/mpp_info.cpp

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/mpp_info.cpp > CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.i

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/mpp_info.cpp -o CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.s

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.requires:

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.provides: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.requires
	$(MAKE) -f mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.provides.build
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.provides

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.provides.build: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o


# Object files for target rockchip_vpu_static
rockchip_vpu_static_OBJECTS = \
"CMakeFiles/rockchip_vpu_static.dir/vpu.c.o" \
"CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o" \
"CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o" \
"CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o" \
"CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o" \
"CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o" \
"CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o"

# External object files for target rockchip_vpu_static
rockchip_vpu_static_EXTERNAL_OBJECTS =

mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build.make
mpp/legacy/librockchip_vpu_static.a: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library librockchip_vpu_static.a"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && $(CMAKE_COMMAND) -P CMakeFiles/rockchip_vpu_static.dir/cmake_clean_target.cmake
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rockchip_vpu_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build: mpp/legacy/librockchip_vpu_static.a

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/build

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu.c.o.requires
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api.cpp.o.requires
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_api_legacy.cpp.o.requires
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/vpu_mem_legacy.c.o.requires
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/rk_list.cpp.o.requires
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/ppOp.cpp.o.requires
mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires: mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/__/mpp_info.cpp.o.requires

.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/requires

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/clean:
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy && $(CMAKE_COMMAND) -P CMakeFiles/rockchip_vpu_static.dir/cmake_clean.cmake
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/clean

mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/depend:
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mpp/legacy/CMakeFiles/rockchip_vpu_static.dir/depend
