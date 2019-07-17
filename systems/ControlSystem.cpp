#include "ControlSystem.h"
#include "../Constants.h"
#include "../Components.h"

void ControlSystem::step_forward(int elapsed) {
    registry.view<Controls, Figure>().each([elapsed](auto entity, auto &controls, auto &figure){
        auto speed = vec2i(controls.d - controls.a, 1) * SPEED;
        figure.shift += speed * elapsed;
        if (figure.shift.y >= CELL_SIZE){
            figure.shift.y -= CELL_SIZE;
            figure.center.row++;
        }
        if (figure.shift.x >= CELL_SIZE){
            figure.shift.x -= CELL_SIZE;
            figure.center.column++;
        }
        if (figure.shift.x <= -CELL_SIZE){
            figure.shift.x += CELL_SIZE;
            figure.center.column--;
        }
    });
}

void ControlSystem::step_back(int elapsed) {

}

ControlSystem::ControlSystem(entt::registry *registry) : System(registry) {

}
