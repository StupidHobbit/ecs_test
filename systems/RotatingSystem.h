#ifndef TETRIS_ROTATINGSYSTEM_H
#define TETRIS_ROTATINGSYSTEM_H


#include "System.h"
#include "utils.h"

class RotatingSystem : public System {
public:
    static const int SPEED = 2;
    static const int TURN_ANGLE = 1000;

    void step_forward(int elapsed) override;

    void step_back(int elapsed) override;

    RotatingSystem(entt::registry *registry);
};

void rotate_if_possible(Figure &figure, Table &table);

#endif //TETRIS_ROTATINGSYSTEM_H
