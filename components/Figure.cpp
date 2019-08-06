#include "Figure.h"

void remove(entt::registry &registry, Figure &figure) {
    for (auto entity: figure.block_entities)
        registry.destroy(entity);
}

void spawn(entt::registry &registry, Figure &figure) {
    auto blocks = figure.get_blocks();
    for (int i = 0; i < FIGURE_NUMBER_OF_BLOCKS; i++){
        auto [entity, block] = registry.create<Block>();
        figure.block_entities[i] = entity;
        block = blocks[i];
    }
}

std::vector<Block> Figure::get_blocks() {
    std::vector<Block> blocks;
    for (auto &block: figure_pattern->states[current_state].blocks)
        blocks.push_back(block + center);
    return std::move(blocks);
}
