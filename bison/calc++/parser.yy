%skeleton "lalr1.cc"
%require "3.8.1"
%header

%define api.token.raw
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include <string>
  class driver;
}

%param { driver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
#include "driver.hh"
}

%define api.token.prefix {TOK_}
%token
  NEWLINE "\n"
  ASSIGN  "="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> exp

%printer { yyo << $$; } <*>;

%%
%start input;
input: 
  %empty 
  | input statement 
  ;

statement: 
  NEWLINE 
  | exp NEWLINE { std::cout << $1 << std::endl; } 
  | assignment
  | error NEWLINE { yyerrok; }
  ;

assignment:
  "identifier" "=" exp NEWLINE { drv.variables[$1] = $3; };

%left "+" "-";
%left "*" "/";

exp:
  "number"
  | "identifier"  { $$ = drv.variables[$1]; }
  | exp "+" exp   { $$ = $1 + $3; }
  | exp "-" exp   { $$ = $1 - $3; }
  | exp "*" exp   { $$ = $1 * $3; }
  | exp "/" exp   { $$ = $1 / $3; }
  | "(" exp ")"   { $$ = $2; }
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}