#include "utils.h"
#include "../utils/getters.h"

bool figure_collides(Figure &figure, Table &table) {
    static auto field_size = get_field_size();
    for (auto block: figure.get_blocks())
        if (block.column >= field_size.second or
            block.row >= field_size.first or
            table[block.row][block.column]) {
            return true;
        }
    return false;
}
