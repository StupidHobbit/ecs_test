#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "GameManager.h"
#include "components/Player.h"


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

void GameManager::step_forward() {
    step++;
    update_controls(registry);
    for (auto system: systems) {
        system->step_forward(step_size);
    }
}

GameManager::~GameManager() {
    for (auto system: systems)
        delete system;
}

int GameManager::get_step() {
    return step;
}

uint32_t GameManager::get_step_size() {
    return step_size;
}

GameManager::GameManager() : step(0), step_size(16) {
    registry.create<Player, Controls>();
}

void GameManager::step_back() {
    step--;
}
