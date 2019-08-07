#ifndef TETRIS_CONTROLSYSTEM_H
#define TETRIS_CONTROLSYSTEM_H


#include "System.h"

class ControlSystem : public System {
public:
    static const int CELL_SIZE = 10000;
    static const int SPEED = 30;

    void step_forward(int elapsed) override;

    void step_back(int elapsed) override;

    ControlSystem(entt::registry *registry);
};

using Table = std::vector<std::vector<char>>;
bool set_figure_center_if_cell_is_free(Figure &figure, Block new_center, Table table);

Table get_table_from(entt::registry &registry);

#endif //TETRIS_CONTROLSYSTEM_H
