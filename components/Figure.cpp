#include "Figure.h"

void spawn(entt::registry &registry, Figure &figure) {
    auto blocks = figure.get_blocks();
    for (int i = 0; i < FIGURE_NUMBER_OF_BLOCKS; i++){
        auto [entity, block] = registry.create<Block>();
        block = blocks[i];
    }
}

std::vector<Block> Figure::get_blocks() {
    std::vector<Block> blocks;
    for (auto &block: figure_pattern->states[current_state].blocks)
        blocks.push_back(block + center);
    return std::move(blocks);
}

void Figure::rotate_right() {
    current_state = (current_state + 1) % figure_pattern->size();
}

void Figure::rotate_left() {
    current_state = (current_state - 1) % figure_pattern->size();
}
