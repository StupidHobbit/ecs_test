#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <SFML/System/Vector2.hpp>
#include "Block.h"
#include "FigurePattern.h"

using vec2i = sf::Vector2i;

struct Figure {
    Block center;
    FigurePattern const *figure_pattern;
    bool is_valid;
    size_t current_state;
    vec2i shift;

    Figure() : is_valid(false) {}

    Figure(const Block &center, FigurePattern const &figurePattern) :
            center(center),
            figure_pattern(&figurePattern),
            current_state(0),
            is_valid(true)
            {}
};

#endif //TETRIS_FIGURE_H
