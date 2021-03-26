//
// Created by Marco Bassaletti on 25-03-21.
//

#ifndef BOOK4_PROFESSIONAL_CPP_SPREADSHEET_H
#define BOOK4_PROFESSIONAL_CPP_SPREADSHEET_H

#include <utility>
#include "../ch8/SpreadsheetCell.h"
#include "SpreadsheetApplication.h"

namespace Chapter9 {
    class Spreadsheet {
    public:
        Spreadsheet(size_t width, size_t height);

        Spreadsheet(const Spreadsheet& src);

        Spreadsheet(Spreadsheet&& src) noexcept;

        ~Spreadsheet();

        Spreadsheet& operator=(const Spreadsheet& rhs);

        Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

        [[nodiscard]] size_t get_id() const;

        SpreadsheetCell& getCellAt(size_t x, size_t y);

        [[nodiscard]] const SpreadsheetCell& getCellAt(size_t x, size_t y) const;

        void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);

        friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

    private:
        Spreadsheet()
                :id{++spreadsheet_counter}, app{SpreadsheetApplication::get_instance()} { };

        void verify_coordinate(size_t x, size_t y) const;

        SpreadsheetApplication& app;
        static inline size_t spreadsheet_counter;
        const size_t id;
        size_t width = 0;
        size_t height = 0;
        SpreadsheetCell** cells = nullptr;

        void allocate_cells();

        void cleanup() noexcept;

        void copy_cells(const Spreadsheet& src);
    };
}

#endif //BOOK4_PROFESSIONAL_CPP_SPREADSHEET_H
