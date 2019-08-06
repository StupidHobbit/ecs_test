#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <SFML/System/Vector2.hpp>
#include <entt/entt.hpp>
#include "Block.h"
#include "FigurePattern.h"

using vec2i = sf::Vector2i;

struct Figure {
    Block center;
    FigurePattern const *figure_pattern;
    bool is_valid;
    size_t current_state;
    vec2i shift;
    entt::entity block_entities[FIGURE_NUMBER_OF_BLOCKS];

    Figure() : is_valid(false) {}

    Figure(const Block &center, FigurePattern const &figurePattern) :
            center(center),
            figure_pattern(&figurePattern),
            current_state(0),
            is_valid(true)
            {}

    std::vector<Block> get_blocks();
};

void remove(entt::registry &registry, Figure &figure);
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
