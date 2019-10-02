#include "base.h"


class ControlSystemTest : public SystemsTest {
public:
    void check_pos_after_moving(Controls direction, vec2i expected_shift, Block expected_center_shift) {
        set_controls(direction);
        expected_center_shift = expected_center_shift + next_block_position();
        make_n_steps(steps_to_move);
        auto &figure = gm.registry.get<Figure>(gm.registry.view<Figure>()[0]);
        ASSERT_EQ(figure.shift, expected_shift);
        ASSERT_EQ(figure.center, expected_center_shift);
    }

protected:
    int steps_to_move, side_shift;

    virtual void SetUp() {
        SystemsTest::SetUp();
        steps_to_move = ControlSystem::CELL_SIZE / (FIGURE_STARTING_SPEED * step_size) + 1;
        side_shift = FIGURE_STARTING_SPEED * step_size * steps_to_move - ControlSystem::CELL_SIZE;
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
    auto &obstacle = gm.registry.assign<Block>(entity1, 2u, 1u);
    obstacle = obstacle + next_block_position();

    auto &figure = gm.registry.get<Figure>(gm.registry.view<Figure>()[0]);
    figure.pattern = &get_figure_pattern("O");

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