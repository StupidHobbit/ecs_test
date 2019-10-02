#include "base.h"


class RotatingSystemTest : public SystemsTest {
public:
    void check_pos_after_moving(Controls direction, int expected_angle, int expected_state) {
        set_controls(direction);
        auto[figure, rotatable] = gm.registry.get<Figure, Rotatable>(gm.registry.view<Figure>()[0]);
        figure.center = Block(1, 1);
        figure.pattern = &get_figure_pattern("I");
        make_n_steps(steps_to_rotate);
        ASSERT_EQ(rotatable.angle, expected_angle);
        ASSERT_EQ(figure.current_state, expected_state);
    }

protected:
    int steps_to_rotate, angle_shift;

    virtual void SetUp() {
        step_size = gm.get_step_size();
        steps_to_rotate = RotatingSystem::TURN_ANGLE / (RotatingSystem::SPEED * step_size) + 1;
        angle_shift = RotatingSystem::SPEED * step_size * steps_to_rotate - RotatingSystem::TURN_ANGLE;
        gm.add_system<FiguresSpawnerSystem>();
        gm.add_system<RotatingSystem>();
    }
};

TEST_F(RotatingSystemTest, step_forward_no_rotation) {
    check_pos_after_moving(
            Controls(0, 0, 0, 0),
            0,
            0
    );
}

TEST_F(RotatingSystemTest, step_forward_simple) {
    check_pos_after_moving(
            Controls(1, 0, 0, 0),
            angle_shift,
            1
    );
}

TEST_F(RotatingSystemTest, step_forward_with_obstacle) {
    auto &obstacle = gm.registry.assign<Block>(entity1, 2u, 1u);
    check_pos_after_moving(
            Controls(1, 0, 0, 0),
            angle_shift,
            0
    );
}

TEST_F(RotatingSystemTest, step_back) {
    test_step_back();
}