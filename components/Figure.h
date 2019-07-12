#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include "Block.h"
#include "FigurePattern.h"

struct Figure {
    Block center;
    FigurePattern const *figure_pattern;

    size_t current_state;

    Figure(const Block &center, FigurePattern const &figurePattern) :
            center(center),
            figure_pattern(&figurePattern),
            current_state(0) {}
};

#endif //TETRIS_FIGURE_H
