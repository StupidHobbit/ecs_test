#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "SystemManager.h"
#include "components/Player.h"
#include "components/Figure.h"
#include "utils/getters.h"
#include "components/Rotatable.h"


void update_controls(entt::registry &registry) {
    using namespace sf;
    registry.view<Controls>().each([](auto entity, auto &controls) {
        controls = Controls{
                Keyboard::isKeyPressed(Keyboard::W),
                Keyboard::isKeyPressed(Keyboard::A),
                Keyboard::isKeyPressed(Keyboard::S),
                Keyboard::isKeyPressed(Keyboard::D),
        };
    });
}

void SystemManager::step_forward() {
    step++;
    update_controls(registry);
    for (auto system: systems) {
        system->step_forward(step_size);
    }
}

SystemManager::~SystemManager() {
    for (auto system: systems)
        delete system;
}

int SystemManager::get_step() {
    return step;
}

uint32_t SystemManager::get_step_size() {
    return step_size;
}

SystemManager::SystemManager() : step(0), step_size(16) {
    auto[entity, c, figure, p, r] = registry.create<Controls, Figure, Player, Rotatable>();
    figure = Figure(
            next_block_position(),
            next_block_pattern()
    );
}

void SystemManager::step_back() {
    step--;
}
