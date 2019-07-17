#ifndef TETRIS_SYSTEM_H
#define TETRIS_SYSTEM_H

#include <iostream>

#include "entt/entt.hpp"

#include "../components/Controls.h"
#include "../components/Figure.h"

class System {
public:
    virtual void step_forward(int elapsed) = 0;

    virtual void step_back(int elapsed) = 0;

    entt::registry &registry;

    System(entt::registry *registry) : registry(*registry) {};
};

class TestSystem : public System {
public:
    TestSystem(entt::registry *registry) : System(registry) {}

    void step_forward(int elapsed) override {
        registry.view<Figure>().each([](auto entity, auto &figure) {
            std::cout << (int)figure.center.row << ' '
                      << (int)figure.center.column << ' '
                      << figure.shift.x << ' '
                      << figure.shift.y << ' '
                      << std::endl;
        });
    }

    void step_back(int elapsed) override {

    }
};

#endif //TETRIS_SYSTEM_H
