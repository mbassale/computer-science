#include "lexer.h"

int yylex(void)
{
    int c = getchar();
    // skip whitespace
    while (c == ' ' || c == '\t')
    {
        c = getchar();
        ++yylloc.last_column;
    }

    yylloc.first_line = yylloc.last_line;
    yylloc.first_column = yylloc.last_column;

    if (c == '.' || isdigit(c))
    {
        ++yylloc.last_column;
        ungetc(c, stdin);
        if (scanf("%lf", &yylval) != 1)
        {
            abort();
        }
        return NUM;
    }

    if (c == EOF)
    {
        return YYEOF;
    }

    if (c == '\n')
    {
        ++yylloc.last_line;
        yylloc.last_column = 0;
    }
    else
    {
        ++yylloc.last_column;
    }

    return c;
}