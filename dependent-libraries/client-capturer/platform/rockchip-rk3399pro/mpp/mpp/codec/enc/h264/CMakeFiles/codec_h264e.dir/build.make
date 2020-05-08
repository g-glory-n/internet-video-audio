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
include mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/depend.make

# Include the progress variables for this target.
include mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/progress.make

# Include the compile flags for this target's objects.
include mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/flags.make

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o: mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/flags.make
mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o: mpp/codec/enc/h264/src/h264e_api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/codec_h264e.dir/src/h264e_api.c.o   -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264/src/h264e_api.c

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/codec_h264e.dir/src/h264e_api.c.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264/src/h264e_api.c > CMakeFiles/codec_h264e.dir/src/h264e_api.c.i

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/codec_h264e.dir/src/h264e_api.c.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264/src/h264e_api.c -o CMakeFiles/codec_h264e.dir/src/h264e_api.c.s

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.requires:

.PHONY : mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.requires

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.provides: mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.requires
	$(MAKE) -f mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/build.make mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.provides.build
.PHONY : mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.provides

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.provides.build: mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o


# Object files for target codec_h264e
codec_h264e_OBJECTS = \
"CMakeFiles/codec_h264e.dir/src/h264e_api.c.o"

# External object files for target codec_h264e
codec_h264e_EXTERNAL_OBJECTS =

mpp/codec/enc/h264/libcodec_h264e.a: mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o
mpp/codec/enc/h264/libcodec_h264e.a: mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/build.make
mpp/codec/enc/h264/libcodec_h264e.a: mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcodec_h264e.a"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 && $(CMAKE_COMMAND) -P CMakeFiles/codec_h264e.dir/cmake_clean_target.cmake
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codec_h264e.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/build: mpp/codec/enc/h264/libcodec_h264e.a

.PHONY : mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/build

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/requires: mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/src/h264e_api.c.o.requires

.PHONY : mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/requires

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/clean:
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 && $(CMAKE_COMMAND) -P CMakeFiles/codec_h264e.dir/cmake_clean.cmake
.PHONY : mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/clean

mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/depend:
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264 /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mpp/codec/enc/h264/CMakeFiles/codec_h264e.dir/depend
