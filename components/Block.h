#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H


#include <stdint-gcc.h>


struct Block {
    uint8_t row, column;

    Block(uint8_t row, uint8_t column) : row(row), column(column) {}

    bool operator==(const Block b) const {
        return row == b.row and
               column == b.column;
    }

    Block() {}

    Block operator+(const Block b) const {
        return Block(row + b.row, column + b.column);
    }
};


#endif //TETRIS_BLOCK_H
