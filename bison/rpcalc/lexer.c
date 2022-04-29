#include "lexer.h"

int yylex(void)
{
    int c = getchar();
    // skip whitespace
    while (c == ' ' || c == '\t')
    {
        c = getchar();
    }
    if (c == '.' || isdigit(c))
    {
        ungetc(c, stdin);
        if (scanf("%lf", &yylval) != 1)
        {
            abort();
        }
        return NUM;
    }
    else if (c == EOF)
    {
        return YYEOF;
    }
    else
    {
        return c;
    }
}