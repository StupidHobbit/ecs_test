#include "ControlSystem.h"
#include "../Constants.h"
#include "../Components.h"
#include "../utils/getters.h"
#include "utils.h"

inline int sign(int x) {
    return x > 0 ? 1 : -1;
}

void ControlSystem::step_forward(int elapsed) {
    auto table = get_table_from(registry);
    registry.view<Controls, Figure>().each([elapsed, &table](auto entity, auto &controls, auto &figure) {
        remove(table, figure);

        auto speed = vec2i(controls.d - controls.a, 1) * SPEED;
        figure.shift += speed * elapsed;

        if (figure.shift.y >= CELL_SIZE)
            if (not set_figure_center_if_cell_is_free(
                    figure,
                    figure.center + Block(1, 0),
                    table
            ))
                figure.is_valid = false;
        if (abs(figure.shift.x) >= CELL_SIZE)
            set_figure_center_if_cell_is_free(
                    figure,
                    figure.center + Block(0, sign(figure.shift.x)),
                    table
            );

        figure.shift.x = abs(figure.shift.x) % CELL_SIZE * sign(figure.shift.x);
        figure.shift.y %= CELL_SIZE;

        spawn(table, figure);
    });
}

bool set_figure_center_if_cell_is_free(Figure &figure, Block new_center, Table table) {
    static auto field_size = get_field_size();
    auto old_center = figure.center;
    figure.center = new_center;
    if (figure_collides(figure, table)) {
        figure.center = old_center;
        return false;
    }
    return true;
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

void ControlSystem::step_back(int elapsed) {

}

ControlSystem::ControlSystem(entt::registry *registry) : System(registry) {

}

