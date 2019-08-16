#ifndef TEST_UTILS_H
#define TEST_UTILS_H

int count_blocks(auto &table){
    int result = 0;
    for (auto &row: table)
        for (auto &cell: row)
            result += cell;
    return result;
}

#endif //TEST_UTILS_H
