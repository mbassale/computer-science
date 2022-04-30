#ifndef __driver_hh_included
#define __driver_hh_included

#include "common.hh"
#include "parser.hh"

#define YY_DECL yy::parser::symbol_type yylex(driver &drv)

YY_DECL;

class driver
{
public:
    driver();
    std::map<std::string, int> variables;
    int result;

    int parse(const std::string &f);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;

    yy::location location;
};

#endif // __driver_hh_included