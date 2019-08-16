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

Table get_table_from(entt::registry &registry) {
    static auto size = get_field_size();
    Table table(size.first, std::vector<char>(size.second, 0));
    registry.view<Block>().each([&table](auto entity, auto &block) {
        table[block.row][block.column] = 1;
    });
    registry.view<Figure>().each([&table](auto entity, auto &figure) {
        spawn(table, figure);
    });
    return std::move(table);
}