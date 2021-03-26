//
// Created by Marco Bassaletti on 25-03-21.
//

#include <utility>
#include <iostream>
#include "Spreadsheet.h"

#define print_trace() (cout << typeid(this).name() << "::" << __FUNCTION__ << endl)

namespace Chapter9 {
    using namespace std;

    void swap(Spreadsheet& first, Spreadsheet& second) noexcept
    {
        using std::swap;
        swap(first.width, second.width);
        swap(first.height, second.height);
        swap(first.cells, second.cells);
    }

    Spreadsheet::Spreadsheet(size_t width, size_t height)
            :id{++spreadsheet_counter}, app{SpreadsheetApplication::get_instance()}, width{width}, height{height}
    {
        print_trace();
        allocate_cells();
    }

    Spreadsheet::Spreadsheet(const Spreadsheet& src)
            :Spreadsheet{src.width, src.height}
    {
        print_trace();
        copy_cells(src);
    }

    Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
            :id{src.id}, app{SpreadsheetApplication::get_instance()}
    {
        print_trace();
        swap(*this, src);
    }

    Spreadsheet::~Spreadsheet()
    {
        print_trace();
        cleanup();
    }

    Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
    {
        print_trace();
        if (this == &rhs) return *this;
        Spreadsheet temp{rhs};
        swap(*this, temp);
        return *this;
    }

    Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
    {
        print_trace();
        Spreadsheet temp(std::move(rhs));
        swap(*this, temp);
        return *this;
    }

    size_t Spreadsheet::get_id() const
    {
        return id;
    }

    void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
    {
        verify_coordinate(x, y);
        cells[x][y] = cell;
    }

    SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
    {
        return const_cast<SpreadsheetCell&>(std::as_const(*this).getCellAt(x, y));
    }

    const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
    {
        verify_coordinate(x, y);
        return cells[x][y];
    }

    void Spreadsheet::verify_coordinate(size_t x, size_t y) const
    {
        if (x >= width || y >= height)
            throw std::out_of_range("");
    }

    void Spreadsheet::allocate_cells()
    {
        cells = new SpreadsheetCell* [width];
        for (size_t i = 0; i < width; i++)
            cells[i] = new SpreadsheetCell[height];
    }

    void Spreadsheet::copy_cells(const Spreadsheet& src)
    {
        for (size_t i = 0; i < width; i++)
            for (size_t j = 0; j < height; j++)
                cells[i][j] = src.cells[i][j];
    }

    void Spreadsheet::cleanup() noexcept
    {
        for (size_t i = 0; i < width; i++)
            delete[] cells[i];
        delete[] cells;
        cells = nullptr;
        width = height = 0;
    }

}
