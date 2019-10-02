#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <SFML/System/Vector2.hpp>
#include <entt/entt.hpp>
#include "Block.h"
#include "FigurePattern.h"

const int FIGURE_STARTING_SPEED = 35;
const int FIGURE_MAX_SPEED = 500;

using vec2i = sf::Vector2i;

struct Figure {
    Block center;
    FigurePattern const *pattern;
    bool is_valid;
    size_t current_state;
    vec2i shift;
    int speed;

    Figure() : is_valid(false) {}

    Figure(const Block &center, FigurePattern const &figurePattern) :
            center(center),
            pattern(&figurePattern),
            current_state(0),
            is_valid(true),
            speed(FIGURE_STARTING_SPEED)
            {}

    std::vector<Block> get_blocks();
    void rotate_right();
    void rotate_left();
};

void spawn(entt::registry &registry, Figure &figure);

inline void remove(auto &table, Figure &figure) {
    for (auto block: figure.get_blocks())
        table[block.row][block.column] = 0;
}

inline void spawn(auto &table, Figure &figure) {
    for (auto block: figure.get_blocks())
        table[block.row][block.column] = 1;
}

#endif //TETRIS_FIGURE_H
