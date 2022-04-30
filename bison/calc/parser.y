/* Calc Bison Example */

%{
  // Forward Declarations
  #include "common.h"
  #include "lexer.h"

  // Error Reporting Function
  void yyerror(char const *);
%}

// Generate a header with definitions
%header

// Token Value Type
%define api.value.type {double}

// Token Type
%token NUM

// Precedence Rules
%left '-' '+'
%left '*' '/'
%precedence NEG
%right '^'

%% // Calc Infix Grammar

input: 
  %empty 
  | input line 
  ;

line: '\n' 
  | exp '\n' { printf("%.10g\n", $1); } 
  | error '\n' { yyerrok; }
  ;

exp: 
  NUM
  // binary operators
  | exp '+' exp { $$ = $1 + $3; }
  | exp '-' exp { $$ = $1 - $3; }
  | exp '*' exp { $$ = $1 * $3; }
  | exp '/' exp { $$ = $1 / $3; }
  // unary negation
  | '-' exp %prec NEG { $$ = -$2; }
  | exp '^' exp { $$ = pow ($1, $3); }
  // grouping
  | '(' exp ')' { $$ = $2; }
  ;
%%

void yyerror(char const *s) {
    fprintf(stderr, "%s\n", s);
}
