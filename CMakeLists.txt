cmake_minimum_required(VERSION 3.9)
project(SysOps C)

set(CMAKE_C_STANDARD 11)

add_executable(SysOps main.c charray.c charray.h StatCharray.c StatCharray.h)