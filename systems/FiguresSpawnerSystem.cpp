#include "FiguresSpawnerSystem.h"
#include "../components/Figure.h"
#include "../components/Player.h"
#include "../utils/getters.h"

void FiguresSpawnerSystem::step_forward(int elapsed) {
    for (auto entity: registry.view<Figure>()) {
        auto &figure = registry.get<Figure>(entity);
        if (figure.is_valid) return;
        spawn(registry, figure);
        figure = Figure(
                next_block_position(),
                next_block_pattern()
        );
    }
}

void FiguresSpawnerSystem::step_back(int elapsed) {

}

FiguresSpawnerSystem::FiguresSpawnerSystem(entt::registry *registry) : System(registry) {

}
