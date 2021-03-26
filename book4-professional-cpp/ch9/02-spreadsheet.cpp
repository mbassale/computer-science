//
// Created by Marco Bassaletti on 25-03-21.
//

#include <vector>
#include "../catch.hpp"
#include "Spreadsheet.h"

namespace Chapter9 {
    using namespace std;

    TEST_CASE("Spreadsheet - constructor/destructor", "[chapter 9]")
    {
        for (size_t i = 1; i <= 3; i++) {
            auto spreadsheet = new Spreadsheet{i, i};
            delete spreadsheet;
        }
    }

    TEST_CASE("Spreadsheet - double free", "[chapter 9]")
    {
        Spreadsheet spreadsheet1{4, 4};
        {
            Spreadsheet spreadsheet2{spreadsheet1};
        }
        Spreadsheet spreadsheet3{4, 4};
        spreadsheet3 = spreadsheet1;
        for (size_t i = 0; i < 4; i++)
            for (size_t j = 0; j < 4; j++)
                REQUIRE(spreadsheet1.getCellAt(i, j).get_value() >= 0);
    }

    TEST_CASE("Spreadsheet - move constructor and move assignment", "[chapter 9]")
    {
        vector<Spreadsheet> vec;
        for (int i = 0; i < 2; ++i)
            vec.push_back(Spreadsheet(100, 100));

        Spreadsheet s(2, 3);
        Spreadsheet s2(5, 6);
        s2 = s;
    }

}
