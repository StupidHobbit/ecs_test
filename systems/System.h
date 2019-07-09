#ifndef TETRIS_SYSTEM_H
#define TETRIS_SYSTEM_H

#include <iostream>

#include "entt/entt.hpp"

#include "../components/Controls.h"

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
        registry.view<Controls>().each([](auto entity, auto &controls) {
            std::cout << controls.w
                      << controls.a
                      << controls.s
                      << controls.d
                      << std::endl;
        });
    }

    void step_back(int elapsed) override {

    }
};

#endif //TETRIS_SYSTEM_H
