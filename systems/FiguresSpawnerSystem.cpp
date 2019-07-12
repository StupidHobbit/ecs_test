#include "FiguresSpawnerSystem.h"
#include "../components/Figure.h"

void FiguresSpawnerSystem::step_forward(int elapsed) {
    if (registry.view<Figure>().size()) return;
    auto entity = registry.create();
    registry.assign<Figure>(entity, Block{0, 0}, get_figure_pattern("O"));
}

void FiguresSpawnerSystem::step_back(int elapsed) {

}

FiguresSpawnerSystem::FiguresSpawnerSystem(entt::registry *registry) : System(registry) {

}
