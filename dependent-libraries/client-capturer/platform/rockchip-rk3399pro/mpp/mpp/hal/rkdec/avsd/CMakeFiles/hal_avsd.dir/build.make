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
include mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/depend.make

# Include the progress variables for this target.
include mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/progress.make

# Include the compile flags for this target's objects.
include mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/flags.make

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/flags.make
mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o: mpp/hal/rkdec/avsd/hal_avsd_reg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o   -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd/hal_avsd_reg.c

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd/hal_avsd_reg.c > CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.i

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd/hal_avsd_reg.c -o CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.s

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.requires:

.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.requires

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.provides: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.requires
	$(MAKE) -f mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/build.make mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.provides.build
.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.provides

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.provides.build: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o


mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/flags.make
mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o: mpp/hal/rkdec/avsd/hal_avsd_api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o   -c /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd/hal_avsd_api.c

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hal_avsd.dir/hal_avsd_api.c.i"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd/hal_avsd_api.c > CMakeFiles/hal_avsd.dir/hal_avsd_api.c.i

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hal_avsd.dir/hal_avsd_api.c.s"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd/hal_avsd_api.c -o CMakeFiles/hal_avsd.dir/hal_avsd_api.c.s

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.requires:

.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.requires

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.provides: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.requires
	$(MAKE) -f mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/build.make mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.provides.build
.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.provides

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.provides.build: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o


# Object files for target hal_avsd
hal_avsd_OBJECTS = \
"CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o" \
"CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o"

# External object files for target hal_avsd
hal_avsd_EXTERNAL_OBJECTS =

mpp/hal/rkdec/avsd/libhal_avsd.a: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o
mpp/hal/rkdec/avsd/libhal_avsd.a: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o
mpp/hal/rkdec/avsd/libhal_avsd.a: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/build.make
mpp/hal/rkdec/avsd/libhal_avsd.a: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libhal_avsd.a"
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && $(CMAKE_COMMAND) -P CMakeFiles/hal_avsd.dir/cmake_clean_target.cmake
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hal_avsd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/build: mpp/hal/rkdec/avsd/libhal_avsd.a

.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/build

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/requires: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_reg.c.o.requires
mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/requires: mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/hal_avsd_api.c.o.requires

.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/requires

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/clean:
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd && $(CMAKE_COMMAND) -P CMakeFiles/hal_avsd.dir/cmake_clean.cmake
.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/clean

mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/depend:
	cd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd /root/Documents/my-program/internet-video-audio/libraries/client-capturer/platform/rockchip-rk3399pro/mpp/mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mpp/hal/rkdec/avsd/CMakeFiles/hal_avsd.dir/depend

