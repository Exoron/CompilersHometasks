cmake_minimum_required(VERSION 3.0)
project(Visitors)

set(
        HEADERS
        ${Visitors_SOURCE_DIR}/driver.hh
        ${Visitors_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${Visitors_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${Visitors_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${Visitors_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        Visitors
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        AbstractSyntaxTree/Expressions/NumberExpression.cpp
        AbstractSyntaxTree/Expressions/VariableExpression.cpp
        AbstractSyntaxTree/Expressions/AddExpression.cpp
        AbstractSyntaxTree/Expressions/SubExpression.cpp
        AbstractSyntaxTree/Expressions/MulExpression.cpp
        AbstractSyntaxTree/Expressions/DivExpression.cpp
        AbstractSyntaxTree/Statements/StatementList.cpp
        AbstractSyntaxTree/Statements/AssignStatement.cpp
        AbstractSyntaxTree/Statements/DeclarationStatement.cpp
        AbstractSyntaxTree/Statements/PrintStatement.cpp
        AbstractSyntaxTree/Program.cpp
        Visitors/PrintVisitor.cpp
        Visitors/Interpreter.cpp
        Visitors/Visitor.h
        AbstractSyntaxTree/Expressions/BinaryExpression.h
        AbstractSyntaxTree/Expressions/BinaryExpression.cpp)

target_include_directories(Visitors PRIVATE ${Visitors_SOURCE_DIR})
