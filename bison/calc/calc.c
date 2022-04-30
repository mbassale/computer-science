#include "common.h"
#include "parser.h"

int main()
{
    yylloc.first_line = yylloc.last_line = 1;
    yylloc.first_column = yylloc.last_column = 0;
    return yyparse();
}