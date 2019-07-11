#ifndef TETRIS_FIGURESTATE_H
#define TETRIS_FIGURESTATE_H


#include <istream>
#include "Block.h"

const int FIGURE_NUMBER_OF_BLOCKS = 4;

struct FigureState {
    Block blocks[FIGURE_NUMBER_OF_BLOCKS];
    void load_from_stream(std::istream&);
};


#endif //TETRIS_FIGUREPATTERN_H
