cmake_minimum_required(VERSION 3.16)
project(TestCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(TestCode main.cpp
        src/CmdParse/CmdParse.cpp src/CmdParse/CmdParse.h
        src/EasyLoggingCpp/easylogging++.h src/EasyLoggingCpp/easylogging++.cc
        )