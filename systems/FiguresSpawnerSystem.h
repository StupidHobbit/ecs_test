#ifndef TETRIS_FIGURESSPAWNERSYSTEM_H
#define TETRIS_FIGURESSPAWNERSYSTEM_H


#include "System.h"

class FiguresSpawnerSystem : public System {
public:
    void step_forward(int elapsed) override;

    void step_back(int elapsed) override;

    FiguresSpawnerSystem(entt::registry *registry);
};


#endif //TETRIS_FIGURESSPAWNERSYSTEM_H
