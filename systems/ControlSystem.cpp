#include "ControlSystem.h"
#include "../Constants.h"
#include "../Components.h"
#include "../utils/getters.h"

int sign(int x){
    return x > 0 ? 1 : -1;
}

void ControlSystem::step_forward(int elapsed) {
    registry.view<Controls, Figure>().each([elapsed](auto entity, auto &controls, auto &figure) {
        auto speed = vec2i(controls.d - controls.a, 1) * SPEED;
        figure.shift += speed * elapsed;
        if (figure.shift.y >= CELL_SIZE)
            set_figure_center_if_cell_is_free(figure, figure.center + Block(1, 0));
        if (abs(figure.shift.x) >= CELL_SIZE)
            set_figure_center_if_cell_is_free(figure, {figure.center.row, figure.center.column + sign(figure.shift.x)});
        figure.shift.x = abs(figure.shift.x) % CELL_SIZE * sign(figure.shift.x);
        figure.shift.y %= CELL_SIZE;
    });
}

bool set_figure_center_if_cell_is_free(Figure &figure, Block new_center) {
    auto field_size = get_field_size();
    if (new_center.column >= field_size.x or
        new_center.row >= field_size.y)
        return false;
    figure.center = new_center;
    return true;
}

void ControlSystem::step_back(int elapsed) {

}

ControlSystem::ControlSystem(entt::registry *registry) : System(registry) {

}

