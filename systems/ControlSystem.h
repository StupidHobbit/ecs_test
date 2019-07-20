#ifndef TETRIS_CONTROLSYSTEM_H
#define TETRIS_CONTROLSYSTEM_H


#include "System.h"

class ControlSystem : public System {
public:
    static const int CELL_SIZE = 10000;
    static const int SPEED = 10;    

    void step_forward(int elapsed) override;

    void step_back(int elapsed) override;

    ControlSystem(entt::registry *registry);
};

bool set_figure_center_if_cell_is_free(Figure &figure, Block new_center);


#endif //TETRIS_CONTROLSYSTEM_H
