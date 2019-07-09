#include "gtest/gtest.h"

#include "../GameManager.h"
#include "../Systems.h"

using testing::Eq;

class GameManagerTest : public testing::Test, protected GameManager{
protected:
};

TEST_F(GameManagerTest, add_system){
    auto initial_len = systems.size();
    this->add_system<TestSystem>();
    ASSERT_EQ(systems.size(), initial_len + 1);
}

TEST_F(GameManagerTest, step_forward_step_increases){
    auto initial_step = get_step();
    step_forward();
    ASSERT_EQ(get_step(), initial_step + 1);
}

TEST_F(GameManagerTest, step_forward_step_decreases){
    auto initial_step = get_step();
    step_back();
    ASSERT_EQ(get_step(), initial_step - 1);
}

TEST(update_controlsTest, without_buttons){
    entt::registry registry;
    auto [entity, _] = registry.create<Controls>();
    update_controls(registry);
    auto controls = registry.get<Controls>(entity);
    ASSERT_EQ(controls.w, false);
    ASSERT_EQ(controls.a, false);
    ASSERT_EQ(controls.s, false);
    ASSERT_EQ(controls.d, false);
}