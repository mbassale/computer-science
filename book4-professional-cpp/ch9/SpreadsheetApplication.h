//
// Created by Marco Bassaletti on 26-03-21.
//

#ifndef BOOK4_PROFESSIONAL_CPP_SPREADSHEETAPPLICATION_H
#define BOOK4_PROFESSIONAL_CPP_SPREADSHEETAPPLICATION_H

namespace Chapter9 {
    class SpreadsheetApplication {
    public:
        static SpreadsheetApplication& get_instance();

    private:
        SpreadsheetApplication() = default;
    };
}

#endif //BOOK4_PROFESSIONAL_CPP_SPREADSHEETAPPLICATION_H
