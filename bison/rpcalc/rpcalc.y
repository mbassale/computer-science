/* RPCalc Bison Example */

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

%% // RPCalc Grammar

input: %empty | input line ;

line: '\n' | exp '\n' { printf("%.10g\n", $1); } ;

exp: 
    NUM
    | exp exp '+' { $$ = $1 + $2; }
    | exp exp '-' { $$ = $1 - $2; }
    | exp exp '*' { $$ = $1 * $2; }
    | exp exp '/' { $$ = $1 / $2; }
    | exp exp '^' { $$ = pow ($1, $2); }
    | exp 'n' { $$ = -$1; } // unary minus
;
%%

void yyerror(char const *s) {
    fprintf(stderr, "%s\n", s);
}
