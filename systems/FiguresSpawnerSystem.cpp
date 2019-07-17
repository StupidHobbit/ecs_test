#include "FiguresSpawnerSystem.h"
#include "../components/Figure.h"
#include "../components/Player.h"

void FiguresSpawnerSystem::step_forward(int elapsed) {
    registry.view<Figure>().each([](auto entity, auto &figure){
        if (figure.is_valid) return;
        figure = Figure(Block{0, 0}, get_figure_pattern("O"));
    });
}

void FiguresSpawnerSystem::step_back(int elapsed) {

}

FiguresSpawnerSystem::FiguresSpawnerSystem(entt::registry *registry) : System(registry) {

}
