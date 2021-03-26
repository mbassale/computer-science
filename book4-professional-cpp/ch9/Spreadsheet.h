//
// Created by Marco Bassaletti on 25-03-21.
//

#ifndef BOOK4_PROFESSIONAL_CPP_SPREADSHEET_H
#define BOOK4_PROFESSIONAL_CPP_SPREADSHEET_H

#include <utility>
#include "../ch8/SpreadsheetCell.h"

namespace Chapter9 {
    class Spreadsheet {
    public:
        Spreadsheet(size_t width, size_t height);

        Spreadsheet(const Spreadsheet& src);

        Spreadsheet(Spreadsheet&& src) noexcept;

        ~Spreadsheet();

        Spreadsheet& operator=(const Spreadsheet& rhs);

        Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

        void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);

        SpreadsheetCell& getCellAt(size_t x, size_t y);

        friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

    private:
        Spreadsheet() = default;

        void verify_coordinate(size_t x, size_t y) const;

        size_t width = 0;
        size_t height = 0;
        SpreadsheetCell** cells = nullptr;

        void allocate_cells();

        void cleanup() noexcept;

        void copy_cells(const Spreadsheet& src);
    };
}

#endif //BOOK4_PROFESSIONAL_CPP_SPREADSHEET_H
