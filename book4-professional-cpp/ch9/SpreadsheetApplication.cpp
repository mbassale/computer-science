//
// Created by Marco Bassaletti on 26-03-21.
//

#include "SpreadsheetApplication.h"

namespace Chapter9 {
    SpreadsheetApplication& SpreadsheetApplication::get_instance()
    {
        static SpreadsheetApplication app{};
        return app;
    }
}
