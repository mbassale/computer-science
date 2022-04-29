#include "common.h"
#include "rpcalc.h"

int main(void)
{
    printf("Reverse Polish Calculator in Bison\n\n");
    return yyparse();
}