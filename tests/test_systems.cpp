#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Systems.h"
#include "../Components.h"
#include "../SystemManager.h"
#include "../Constants.h"
#include "../utils/getters.h"
#include "utils.h"

using testing::Eq;


TEST(System, has_step_forward) {
    &System::step_forward;
}

TEST(System, has_step_back) {
    &System::step_back;
}

class GameManagerNoControlsUpdate : public SystemManager {
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
    entt::entity entity1, entity2;

protected:
    virtual void SetUp() {
        entity1 = registry.create();
        entity2 = registry.create();
    }

    void make_n_steps(int n) {
        for (int i = 0; i < n; i++)
            gm.step_forward();
    }

};

TEST_F(SystemsTest, FiguresSpawnerSystem_step_forward_not_valid) {
    FiguresSpawnerSystem system(&registry);
    auto[entity, figure] = registry.create<Figure>();
    figure = Figure({1u, 1u}, get_figure_pattern("O"));
    figure.is_valid = false;
    system.step_forward(16);
    ASSERT_TRUE(figure.is_valid);
    ASSERT_EQ(figure.center, Block(0, 0));
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

TEST_F(ControlSystemTest, step_forward_move_down_to_bottom) {
    make_n_steps(1);
    auto table = get_table_from(gm.registry);
    ASSERT_EQ(count_blocks(table), FIGURE_NUMBER_OF_BLOCKS);

    make_n_steps(steps_to_move * get_field_size().first - 1);
    table = get_table_from(gm.registry);
    ASSERT_EQ(count_blocks(table), 2 * FIGURE_NUMBER_OF_BLOCKS);
}

TEST_F(ControlSystemTest, step_forward_move_down_with_obstacle) {
    gm.registry.assign<Block>(entity1, 2u, 0u);
    check_pos_after_moving(
            Controls{0, 0, 0, 0},
            vec2i{0, side_shift},
            Block{0, 0}
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

TEST_F(SystemsTest, get_table_from) {
    registry.assign<Block>(entity1, 0, 0);
    registry.assign<Block>(entity2, 1, 1);
    auto table = get_table_from(registry);
    ASSERT_TRUE(table[0][0]);
    ASSERT_TRUE(table[1][1]);
    ASSERT_FALSE(table[0][1]);
    ASSERT_FALSE(table[1][0]);
}

TEST_F(SystemsTest, get_table_from_with_figure) {
    registry.assign<Figure>(entity1, Block{0u, 0u}, get_figure_pattern("O"));
    auto table = get_table_from(registry);
    ASSERT_TRUE(table[0][0]);
    ASSERT_TRUE(table[1][1]);
    ASSERT_TRUE(table[0][1]);
    ASSERT_TRUE(table[1][0]);
}