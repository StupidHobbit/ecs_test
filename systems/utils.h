#ifndef TETRIS_UTILS_H
#define TETRIS_UTILS_H


#include <vector>
#include <entt/entity/registry.hpp>
#include "../components/Figure.h"

using Table = std::vector<std::vector<char>>;

bool figure_collides(Figure &figure, Table &table);

Table get_table_from(entt::registry &registry);
#endif //TETRIS_UTILS_H
