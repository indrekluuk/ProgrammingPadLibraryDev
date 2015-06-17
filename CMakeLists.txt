cmake_minimum_required(VERSION 3.2)
project(ProgrammingPadLibraryDev)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}") #  -std=c++11


include_directories("./frameworks")
include_directories("./library/Scheduler")
include_directories("./sketch_ProgrammableBot")
include_directories("./tests")


set(FRAMEWORK_SOURCE_FILES
        frameworks/gtest/gtest-all.cc)

set(LIBRARY_SOURCE_FILES
        library/Scheduler/Scheduler.cpp
        library/Scheduler/Sequencer.cpp)

set(TEST_SOURCE_FILES
        tests/main.cpp
        tests/Arduino.cpp
)


add_executable(ProgrammingPadLibraryDev
        ${FRAMEWORK_SOURCE_FILES}
        ${LIBRARY_SOURCE_FILES}
        ${TEST_SOURCE_FILES}
        sketch_ProgrammingPad/ProgrammingPad.cpp
        sketch_ProgrammingPad/ProgrammingPad.h
        sketch_ProgrammingPad/Command.cpp
        sketch_ProgrammingPad/Command.h
        sketch_ProgrammingPad/ProgramSub.cpp
        sketch_ProgrammingPad/ProgramSub.h sketch_ProgrammingPad/Commands.cpp sketch_ProgrammingPad/CommandSelector.h)

