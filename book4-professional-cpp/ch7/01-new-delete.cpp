//
// Created by Marco Bassaletti on 18-03-21.
//

#include "../catch.hpp"
#include <array>
#include <iostream>

using namespace std;

class Simple {
public:
    Simple() { cout << "Simple constructor called!" << endl; }

    ~Simple() { cout << "Simple destructor called!" << endl; }
};

TEST_CASE("new[] and delete[]") {
    auto *simple_array = new Simple[4];
    delete[] simple_array;
    simple_array = nullptr;
}

TEST_CASE("stack-based multidimensional array") {
    char board[3][3] = {};
    board[0][0] = 'X';
    board[2][1] = '0';
}

TEST_CASE("heap-based multidimensional array") {

    auto allocate_character_board = [](size_t x_dim, size_t y_dim) {
        auto board_array = new char *[x_dim];
        for (auto i = 0; i < y_dim; i++)
            board_array[i] = new char[y_dim];
        return board_array;
    };

    auto release_character_board = [](char **board_array, size_t x_dim) {
        for (auto i = 0; i < x_dim; i++)
            delete[] board_array[i];
        delete[] board_array;
    };

    auto board = allocate_character_board(4, 4);
    REQUIRE(board);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            board[i][j] = '0';
    release_character_board(board, 4);
    board = nullptr;
    REQUIRE_FALSE(board);
}

TEST_CASE("stack array size") {

    auto double_ints = [](int* int_array, size_t size) {
        for (size_t i = 0; i < size; i++)
            int_array[i] *= 2;
    };

    size_t arr_size = 4;
    auto heap_array = new int[arr_size]{ 1, 2, 3, 4 };
    double_ints(heap_array, arr_size);
    delete[] heap_array;
    heap_array = nullptr;

    int stack_array[] = { 5, 6, 7, 8 };
    arr_size = std::size(stack_array);
    double_ints(stack_array, arr_size);
    double_ints(&(stack_array[0]), arr_size);
}
