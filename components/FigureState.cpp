#include "FigureState.h"


void FigureState::load_from_stream(std::istream &fin) {
    uint8_t row = 0;
    uint8_t block_number = 0;
    std::string s;
    while (block_number < FIGURE_NUMBER_OF_BLOCKS){
        std::getline(fin, s);
        uint8_t column = 0;
        for (auto c: s){
            if (c != ' ')
                blocks[block_number++] = Block{row, column};
            column++;
        }
        row++;
    }
}
