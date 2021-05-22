cmake_minimum_required(VERSION 3.16)
project(RingBuff)

set(CMAKE_CXX_STANDARD 14)

add_executable(RingBuff main.cpp ringbuff.cpp ringbuff.h)