#ifndef TETRIS_SYSTEMMANAGER_H
#define TETRIS_SYSTEMMANAGER_H

#include <vector>

#include "entt/entt.hpp"

#include "Systems.h"


class  SystemManager {
private:
    uint32_t step_size;
protected:
    std::vector<System*> systems;
public:
    entt::registry registry;
    int step;
    SystemManager();
    ~SystemManager();
    template<class SystemT>
    void add_system() {
        auto system = new SystemT(&registry);
        systems.push_back(dynamic_cast<System*>(system));
    }

    virtual void step_forward();
    void step_back();
    int get_step();
    uint32_t get_step_size();

};


void update_controls(entt::registry&);

#endif //TETRIS_SYSTEMMANAGER_H
