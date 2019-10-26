cmake_minimum_required(VERSION 3.10)
project(UtPod)

set(CMAKE_CXX_STANDARD 11)

add_executable(UtPod Song.cpp Song.h UtPod.cpp UtPod.h UtPodDriver.cpp)