#ifndef TETRIS_TESTS_BASE_H
#define TETRIS_TESTS_BASE_H

#include "gtest/gtest.h"

#include "../../Systems.h"
#include "../../Components.h"
#include "../../SystemManager.h"
#include "../../Constants.h"
#include "../../utils/getters.h"
#include "../utils.h"
#include "../../systems/utils.h"

using testing::Eq;

uint64_t hash(entt::entity, entt::registry &);
template <class T>
uint64_t get_component_hash(entt::entity, entt::registry &);
uint64_t hash(Figure figure);
uint64_t hash(entt::registry &registry);

class GameManagerNoControlsUpdate : public SystemManager {
public:
    void step_forward() override {
        for (auto system: systems)
            system->step_forward(get_step_size());
    }
};

class SystemsTest : public testing::Test {
protected:
    int step_size;
    entt::registry registry;
    GameManagerNoControlsUpdate gm;
    entt::entity entity1, entity2;

    void set_controls(Controls new_controls) {
        gm.registry.view<Controls>().each([new_controls](auto entity, auto &controls) {
            controls = new_controls;
        });
    }

    virtual void SetUp() {
        entity1 = registry.create();
        entity2 = registry.create();
        step_size = gm.get_step_size();
    }

    void make_n_steps(int n) {
        for (int i = 0; i < n; i++)
            gm.step_forward();
    }

    void test_step_back() {
        auto old_hash = hash(gm.registry);
        gm.step_forward();
        gm.step_back();
        auto new_hash = hash(gm.registry);
        ASSERT_EQ(old_hash, new_hash);
    }

};


#endif
