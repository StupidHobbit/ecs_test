#ifndef TETRIS_GETTERS_H
#define TETRIS_GETTERS_H

#include <utility>
#include <cstdio>
#include "../components/Block.h"
#include "../components/FigurePattern.h"

constexpr std::pair<size_t, size_t> get_field_size();
constexpr size_t get_history_max_size();

Block next_block_position();

FigurePattern &next_block_pattern();


#endif //TETRIS_GETTERS_H
