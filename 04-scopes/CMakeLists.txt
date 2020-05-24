cmake_minimum_required(VERSION 3.0)
project(Scopes)

set(
        HEADERS
        ${Scopes_SOURCE_DIR}/driver.hh
        ${Scopes_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${Scopes_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${Scopes_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${Scopes_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        Scopes
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
        AbstractSyntaxTree/Expressions/BinaryExpression.cpp
        Visitors/SymbolTreeVisitor.cpp Visitors/SymbolTreeVisitor.h
        SymbolTable/ScopeLayer.cpp
        SymbolTable/ScopeLayer.h
        SymbolTable/ScopeLayerTree.cpp
        SymbolTable/ScopeLayerTree.h
        AbstractSyntaxTree/Statements/ScopeStatementList.cpp
        AbstractSyntaxTree/Statements/ScopeStatementList.h
        SymbolTable/Symbol.cpp
        SymbolTable/Symbol.h
        Objects/Object.h
        Objects/Object.cpp
        Objects/UninitObject.cpp
        Objects/UninitObject.h Objects/Integer.cpp Objects/Integer.h Visitors/TemplateVisitor.h)

target_include_directories(Scopes PRIVATE ${Scopes_SOURCE_DIR})
