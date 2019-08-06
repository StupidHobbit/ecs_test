#include "FiguresSpawnerSystem.h"
#include "../components/Figure.h"
#include "../components/Player.h"

void FiguresSpawnerSystem::step_forward(int elapsed) {
    for (auto entity: registry.view<Figure>()){
        auto &figure = registry.get<Figure>(entity);
        if (figure.is_valid) return;
        spawn(registry, figure);
        figure = Figure(Block{0, 0}, get_figure_pattern("O"));
    }
}

void FiguresSpawnerSystem::step_back(int elapsed) {

}

FiguresSpawnerSystem::FiguresSpawnerSystem(entt::registry *registry) : System(registry) {

}
