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
  | exp '/' exp { 
    if ($3) {
      $$ = $1 / $3; 
    } else {
      $$ = 1;
      fprintf(stderr, "%d.%d-%d.%d: division by zero\n",
        @3.first_line, @3.first_column,
        @3.last_line, @3.last_column);
    }
  }
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
