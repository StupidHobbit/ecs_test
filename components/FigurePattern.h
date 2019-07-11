#ifndef TETRIS_FIGUREPATTERN_H
#define TETRIS_FIGUREPATTERN_H


#include <string>
#include <vector>
#include "FigureState.h"

struct FigurePattern{
    std::vector<FigureState> states;
    void load_from_file(std::string filename);
};

#endif //TETRIS_FIGUREPATTERN_H
