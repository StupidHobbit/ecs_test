#include "RotatingSystem.h"
#include "../Systems.h"
#include "../components/Rotatable.h"
#include "utils.h"

void RotatingSystem::step_forward(int elapsed) {
    auto table = get_table_from(registry);
    registry.view<Controls, Figure, Rotatable>().each(
            [elapsed, &table](auto entity, auto &controls, auto &figure, auto &rotatable) {
                if (not controls.w)
                    return;

                remove(table, figure);

                rotatable.angle += SPEED * elapsed;
                if (rotatable.angle > TURN_ANGLE){
                    rotatable.angle -= TURN_ANGLE;
                    rotate_if_possible(figure, table);
                }

                spawn(table, figure);
            });
}

void rotate_if_possible(Figure &figure, Table &table){
    figure.rotate_right();
    if (figure_collides(figure, table))
        figure.rotate_left();
}

void RotatingSystem::step_back(int elapsed) {

}

RotatingSystem::RotatingSystem(entt::registry *registry) : System(registry) {

}
