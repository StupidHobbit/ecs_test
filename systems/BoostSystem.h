#ifndef TETRIS_BOOSTSYSTEM_H
#define TETRIS_BOOSTSYSTEM_H


#include "System.h"

class BoostSystem : public System {
public:
    void step_forward(int elapsed) override;

    void step_back(int elapsed) override;

    BoostSystem(entt::registry *registry);
};



#endif //TETRIS_BOOSTSYSTEM_H
