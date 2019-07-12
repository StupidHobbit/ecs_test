#ifndef TETRIS_FIGUREPATTERN_H
#define TETRIS_FIGUREPATTERN_H


#include <string>
#include <vector>
#include <bits/unordered_map.h>
#include "FigureState.h"

struct FigurePattern{
    std::string name;
    std::vector<FigureState> states;
    void load_from_file(std::string const &path);
};

FigurePattern &get_figure_pattern(std::string const &name);

#endif //TETRIS_FIGUREPATTERN_H
