cmake_minimum_required(VERSION 3.0)
project(AST)

set(
        HEADERS
        ${AST_SOURCE_DIR}/driver.hh
        ${AST_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${AST_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${AST_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${AST_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        AST
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        AbstractSyntaxTree/AST.cpp
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
)

target_include_directories(AST PRIVATE ${AST_SOURCE_DIR})
