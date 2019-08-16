#ifndef TETRIS_ROWSCLEANINGSYSTEM_H
#define TETRIS_ROWSCLEANINGSYSTEM_H


#include "System.h"

class RowsCleaningSystem : public System {
public:
    void step_forward(int elapsed) override;

    void step_back(int elapsed) override;

    RowsCleaningSystem(entt::registry *registry);
};


#endif //TETRIS_ROWSCLEANINGSYSTEM_H
