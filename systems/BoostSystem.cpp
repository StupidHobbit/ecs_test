#include "BoostSystem.h"

void BoostSystem::step_forward(int elapsed) {
    registry.view<Controls, Figure>().each([](auto entity, auto &controls, auto &figure) {
        figure.speed = controls.s ? FIGURE_MAX_SPEED : FIGURE_STARTING_SPEED;
    });
}

void BoostSystem::step_back(int elapsed) {

}

BoostSystem::BoostSystem(entt::registry *registry) : System(registry) {

}

