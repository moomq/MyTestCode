# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)
# Set the project name
project(TestCode)

MESSAGE(STATUS "This is PROJECT_SOURCE_DIR dir " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is CMAKE_SOURCE_DIR dir " ${CMAKE_SOURCE_DIR})
MESSAGE(STATUS "This is CMAKE_CURRENT_BINARY_DIR dir " ${CMAKE_CURRENT_BINARY_DIR})

# try conditional compilation
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

# check results and add flag
if(COMPILER_SUPPORTS_CXX11)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# find a boost install with the libraries filesystem and system
#find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# check if boost was found
#if(Boost_FOUND)
#    message ("boost found")
#else()
#    message (FATAL_ERROR "Cannot find Boost")
#endif()

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
        CmdParse/CmdParse.cpp
        EasyLoggingCpp/easylogging++.cc
        MultiTimer/multi_timer.c
        Test/MultiTimerTest.cpp
        Test/EasyLoggingTest.cpp
        Base64/base64.cpp
        Test/TestBase64.cpp
        cJson/cJSON.c
        Test/cJsonTest.cpp
        main.cpp
        )

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(TestCodeLib ${SOURCES})

#Generate the static library from the library sources
#add_library(TestCodeLibShare SHARED ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(TestCodeLib
        PUBLIC
            ${PROJECT_SOURCE_DIR}/Base64
            ${PROJECT_SOURCE_DIR}/cJson
            ${PROJECT_SOURCE_DIR}/CmdParse
            ${PROJECT_SOURCE_DIR}/EasyLoggingCpp
            ${PROJECT_SOURCE_DIR}/MultiTimer
            ${PROJECT_SOURCE_DIR}/Test
        )

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES})

# link the new hello_library target with the hello_binary target
target_link_libraries(${PROJECT_NAME}
        PRIVATE
            TestCodeLib
#            Boost::filesystem
        )

#############################################
# Unit tests

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unit_tests main.cpp)

target_link_libraries(unit_tests
        TestCodeLib
        )

add_test(test_all unit_tests)


############################################################
# Install
############################################################
# Binaries
set(BUILD_DIR ${PROJECT_SOURCE_DIR}/../build)
MESSAGE(STATUS "This is BUILD_DIR dir " ${BUILD_DIR})
install (TARGETS ${PROJECT_NAME} DESTINATION ${BUILD_DIR}/bin)

# Library
# Note: may not work on windows
#install (TARGETS TestCodeLib LIBRARY DESTINATION ${BUILD_DIR}/lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/Base64 DESTINATION ${BUILD_DIR}/include)

# Config
install (FILES test.conf DESTINATION ${BUILD_DIR}/etc)