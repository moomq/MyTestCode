cmake_minimum_required(VERSION 3.16)
project(TestCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(TestCode main.cpp
        src/CmdParse/CmdParse.cpp src/CmdParse/CmdParse.h
        src/EasyLoggingCpp/easylogging++.h src/EasyLoggingCpp/easylogging++.cc
        src/MultiTimer/multi_timer.c src/MultiTimer/multi_timer.h
        src/Test/MultiTimerTest.cpp src/Test/MultiTimerTest.h
        src/Test/EasyLoggingTest.cpp src/Test/EasyLoggingTest.h)