cmake_minimum_required(VERSION 3.16)
project(TestCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(TestCode main.cpp
        src/CmdParse/CmdParse.cpp src/CmdParse/CmdParse.h
        src/EasyLoggingCpp/easylogging++.h src/EasyLoggingCpp/easylogging++.cc
        src/MultiTimer/multi_timer.c src/MultiTimer/multi_timer.h
        src/Test/MultiTimerTest.cpp src/Test/MultiTimerTest.h
        src/Test/EasyLoggingTest.cpp src/Test/EasyLoggingTest.h
        src/Base64/base64.cpp src/Base64/base64.h
        src/Test/TestBase64.cpp src/Test/TestBase64.h
        src/cJson/cJSON.c src/cJson/cJSON.h
        src/Test/cJsonTest.cpp src/Test/cJsonTest.h)