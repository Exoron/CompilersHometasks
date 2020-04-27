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
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

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
%nterm <int> exp

%printer { yyo << $$; } <*>;

%%
%start unit;
unit: statements {};

statements:
    %empty {}
    | statements statement {};

statement:
    declaration {}
    | "{" statements "}" {}
    | "System" "." "out" "." "println" "(" exp ")" ";" {
    	std::cout << $7 << std::endl;
    }
    | assignment {};

declaration:
    "int" "identifier" ";" {
    	driver.variables[$2] = 0;
    }
    | "int" "identifier" "=" "number" ";" {
    	driver.variables[$2] = $4;
    };

assignment:
    "identifier" "=" exp ";" {
    	driver.variables[$1] = $3;
    };

%left "+" "-";
%left "*" "/";

exp:
    "number"
    | "identifier" {$$ = driver.variables[$1];}
    | exp "+" exp {$$ = $1 + $3; }
    | exp "-" exp {$$ = $1 - $3; }
    | exp "*" exp {$$ = $1 * $3; }
    | exp "/" exp {$$ = $1 / $3; }
    | "(" exp ")" {$$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
