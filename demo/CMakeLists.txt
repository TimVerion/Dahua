cmake_minimum_required(VERSION 2.8)

project(demo)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fPIC")

SET(DHNETSDKSO /home/wilson/code/Dahua/demo/camera/lib/libdhnetsdk.so)

add_definitions(-D ELPP_THREAD_SAFE)
add_definitions(-D DATE_ROLL_BACK_LOG)
add_definitions(-D ISCONSOLE)

aux_source_directory(. DIRSRCS)
include_directories(./ ./utils/log ./camera ./camera/include)
add_subdirectory(utils)
add_subdirectory(camera)

add_executable(demo ${DIRSRCS})
target_link_libraries(demo utils camera ${DHNETSDKSO})