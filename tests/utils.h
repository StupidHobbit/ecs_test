#ifndef TETRIS_UTILS_H
#define TETRIS_UTILS_H

int count_blocks(auto &table){
    int result = 0;
    for (auto &row: table)
        for (auto &cell: row)
            result += cell;
    return result;
}

#endif //TETRIS_UTILS_H
