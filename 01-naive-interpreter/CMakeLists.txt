cmake_minimum_required(VERSION 3.0)
project(Interpreter)

set(
        HEADERS
        ${Interpreter_SOURCE_DIR}/driver.hh
        ${Interpreter_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${Interpreter_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${Interpreter_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${Interpreter_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        Interpreter
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
)

target_include_directories(Interpreter PRIVATE ${Interpreter_SOURCE_DIR})