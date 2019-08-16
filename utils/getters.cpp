#include "getters.h"

constexpr std::pair<size_t, size_t> get_field_size(){
    return std::make_pair(30, 20);
}

Block next_block_position() {
    return Block(0, get_field_size().second / 2 - 1);
}

FigurePattern &next_block_pattern() {
    return get_random_figure_pattern();
}
