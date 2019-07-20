#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Systems.h"
#include "../Components.h"
#include "../GameManager.h"
#include "../Constants.h"

using testing::Eq;


TEST(System, has_step_forward) {
    &System::step_forward;
}

TEST(System, has_step_back) {
    &System::step_back;
}

class GameManagerNoControlsUpdate : public GameManager {
public:
    void step_forward() override {
        for (auto system: systems)
            system->step_forward(get_step_size());
    }
};

class SystemsTest : public testing::Test {
public:
protected:
    entt::registry registry;
    GameManagerNoControlsUpdate gm;

    void make_n_steps(int n) {
        for (int i = 0; i < n; i++)
            gm.step_forward();
    }
};

TEST_F(SystemsTest, FiguresSpawnerSystem_step_forward) {
    FiguresSpawnerSystem system(&registry);
    auto[entity, figure] = registry.create<Figure>();
    ASSERT_EQ(figure.is_valid, false);
    system.step_forward(16);
    ASSERT_EQ(figure.is_valid, true);
}

class ControlSystemTest : public SystemsTest {
public:
    void set_controls(Controls new_controls) {
        gm.registry.view<Controls>().each([new_controls](auto entity, auto &controls) {
            controls = new_controls;
        });
    }

    void check_pos_after_moving(Controls direction, vec2i expected_shift, Block expected_center) {
        set_controls(direction);
        make_n_steps(steps_to_move);
        auto &figure = gm.registry.get<Figure>(gm.registry.view<Figure>()[0]);
        ASSERT_EQ(figure.shift, expected_shift);
        ASSERT_EQ(figure.center, expected_center);
    }

protected:
    int step_size, steps_to_move, side_shift;

    virtual void SetUp() {
        step_size = gm.get_step_size();
        steps_to_move = ControlSystem::CELL_SIZE / (ControlSystem::SPEED * step_size) + 1;
        side_shift = ControlSystem::SPEED * step_size * steps_to_move - ControlSystem::CELL_SIZE;
        gm.add_system<FiguresSpawnerSystem>();
        gm.add_system<ControlSystem>();
    }

};

TEST_F(ControlSystemTest, step_forward_move_down) {
    check_pos_after_moving(
            Controls{0, 0, 0, 0},
            vec2i{0, side_shift},
            Block{1, 0}
    );
}

TEST_F(ControlSystemTest, step_forward_move_right) {
    check_pos_after_moving(
            Controls{0, 0, 0, 1},
            vec2i{side_shift, side_shift},
            Block{1, 1}
    );
}


TEST_F(ControlSystemTest, step_forward_move_right_then_left) {
    check_pos_after_moving(
            Controls{0, 0, 0, 1},
            vec2i{side_shift, side_shift},
            Block{1, 1}
    );
    check_pos_after_moving(
            Controls{0, 1, 0, 0},
            vec2i{0, side_shift * 2},
            Block{2, 0}
    );
}