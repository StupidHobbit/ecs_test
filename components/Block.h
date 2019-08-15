#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H


#include <stdint-gcc.h>

using uint = unsigned int;

struct Block {
    uint row, column;

    Block(uint row, uint column) : row(row), column(column) {}

    bool operator==(const Block b) const {
        return row == b.row and
               column == b.column;
    }

    Block() {}

    Block operator+(const Block b) const {
        return Block(row + b.row, column + b.column);
    }

    Block operator-(const Block b) const {
        return Block(row - b.row, column - b.column);
    }

    Block &operator+=(const Block b) {
        row += b.row;
        column += b.column;
        return *this;
    }

    Block &operator-=(const Block b) {
        row -= b.row;
        column -= b.column;
        return *this;
    }
};


#endif //TETRIS_BLOCK_H
