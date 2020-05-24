%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;

    class Expression;
    class NumberExpression;
    class VariableExpression;
    class AddExpression;
    class SubExpression;
    class MulExpression;
    class DivExpression;

    class Statement;
    class StatementList;
    class DeclarationStatement;
    class AssignStatement;
    class PrintStatement;

    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "AbstractSyntaxTree/Expressions/Expression.h"
    #include "AbstractSyntaxTree/Expressions/NumberExpression.h"
    #include "AbstractSyntaxTree/Expressions/VariableExpression.h"
    #include "AbstractSyntaxTree/Expressions/AddExpression.h"
    #include "AbstractSyntaxTree/Expressions/SubExpression.h"
    #include "AbstractSyntaxTree/Expressions/MulExpression.h"
    #include "AbstractSyntaxTree/Expressions/DivExpression.h"

    #include "AbstractSyntaxTree/Statements/Statement.h"
    #include "AbstractSyntaxTree/Statements/StatementList.h"
    #include "AbstractSyntaxTree/Statements/DeclarationStatement.h"
    #include "AbstractSyntaxTree/Statements/AssignStatement.h"
    #include "AbstractSyntaxTree/Statements/PrintStatement.h"

    #include "AbstractSyntaxTree/Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    SYSTEM "System"
    OUT "out"
    PRINTLN "println"
    DOT "."
    SEMICOLON ";"
    INT "int"
    MOD "%"
    LBRACE "{"
    RBRACE "}"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <Expression*> exp
%nterm <Statement*> statement
%nterm <StatementList*> statements
%nterm <DeclarationStatement*> declaration
%nterm <AssignStatement*> assignment
%nterm <Program*> unit

%printer { yyo << $$; } <*>;

%%
%start unit;

unit: statements {
	$$ = new Program($1);
	driver.program = $$;
  	};

statements:
    %empty { $$ = new StatementList(); }
    | statements statement { $1->AddStatement($2); $$ = $1; };

statement:
    declaration { $$ = $1; }
    | "{" statements "}" { $$ = $2; }
    | "System" "." "out" "." "println" "(" exp ")" ";" {
    	$$ = new PrintStatement($7);
    }
    | assignment { $$ = $1; };

declaration:
    "int" "identifier" ";" {
    	$$ = new DeclarationStatement($2, new NumberExpression(0));
    }
    | "int" "identifier" "=" exp ";" {
    	$$ = new DeclarationStatement($2, $4);
    };

assignment:
    "identifier" "=" exp ";" {
    	$$ = new AssignStatement($1, $3);
    };

%left "+" "-";
%left "*" "/";

exp:
    "number" { $$ = new NumberExpression($1); }
    | "identifier" { $$ = new VariableExpression($1); }
    | exp "+" exp { $$ = new AddExpression($1, $3); }
    | exp "-" exp { $$ = new SubExpression($1, $3); }
    | exp "*" exp { $$ = new MulExpression($1, $3); }
    | exp "/" exp { $$ = new DivExpression($1, $3); }
    | "(" exp ")" { $$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
