cmake_minimum_required(VERSION 3.6)
project(cpp_nanotekspice)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

FILE(GLOB INCLUDES include/*.hh)
FILE(GLOB COMPONENTS src/component/*.cpp)
FILE(GLOB PARSER src/parser/*.cpp)
FILE(GLOB EXECUTION src/execution/*.cpp)

set(SOURCE_FILES
        ${EXECUTION}
        ${PARSER}
        ${COMPONENTS}
        ${INCLUDES})

set(TESTS4001 src/component/Gates.cpp
        units/tests-component4001.cpp)
set(TESTS4008 src/component/Gates.cpp
        units/tests-component4008.cpp)
set(TESTS4011 src/component/Gates.cpp
        units/tests-component4011.cpp)
set(TESTS4013 src/component/Gates.cpp
        src/component/ComponentClock.cpp
        units/tests-component4013.cpp)
set(TESTS4017 src/component/Gates.cpp
        src/component/Component4017.cpp
        src/component/ComponentClock.cpp
        units/tests-component4017.cpp)
set(TESTS4030 src/component/Gates.cpp
        units/tests-component4030.cpp)
set(TESTS4069 src/component/Gates.cpp
        units/tests-component4069.cpp)
set(TESTS4071 src/component/Gates.cpp
        units/tests-component4071.cpp)
set(TESTS4081 src/component/Gates.cpp
        units/tests-component4081.cpp)
set(TESTS4514 src/component/Gates.cpp
        src/component/Component4514.cpp
        src/component/ComponentInput.cpp
        units/tests-component4514.cpp)
set(TESTSINPUT src/component/Gates.cpp
        units/tests-componentInput.cpp)
set(TESTSOUTPUT src/component/Gates.cpp
        units/tests-componentInput.cpp
        units/tests-componentOutput.cpp)
set(TESTSCLOCK src/component/Gates.cpp
        units/tests-componentClock.cpp)

add_executable(cpp_nanotekspice ${SOURCE_FILES})
add_executable(test-component4001 src/component/Component.cpp ${TESTS4001})
add_executable(test-component4008 src/component/Component.cpp ${TESTS4008})
add_executable(test-component4011 src/component/Component.cpp ${TESTS4011})
add_executable(test-component4013 src/component/Component.cpp ${TESTS4013})
add_executable(test-component4017 src/component/Component.cpp ${TESTS4017})
add_executable(test-component4030 src/component/Component.cpp ${TESTS4030})
add_executable(test-component4069 src/component/Component.cpp ${TESTS4069})
add_executable(test-component4071 src/component/Component.cpp ${TESTS4071})
add_executable(test-component4081 src/component/Component.cpp ${TESTS4081})
add_executable(test-component4514 src/component/Component.cpp ${TESTS4514})
add_executable(test-componentInput src/component/Component.cpp ${TESTSINPUT})
add_executable(test-componentOutput src/component/Component.cpp ${TESTSOUTPUT})
add_executable(test-componentClock src/component/Component.cpp ${TESTSCLOCK})