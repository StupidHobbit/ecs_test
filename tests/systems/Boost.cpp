#include "base.h"


class BoostSystemTest : public SystemsTest {
protected:
    virtual void SetUp() {
        gm.add_system<BoostSystem>();
    }
};

TEST_F(BoostSystemTest, step_forward) {
    auto [entity, figure, controls] = gm.registry.create<Figure, Controls>();

    set_controls(Controls(0, 0, 1, 0));
    make_n_steps(1);
    ASSERT_EQ(figure.speed, FIGURE_MAX_SPEED);

    set_controls(Controls(0, 0, 0, 0));
    make_n_steps(1);
    ASSERT_EQ(figure.speed, FIGURE_STARTING_SPEED);
}

TEST_F(BoostSystemTest, step_back) {
    auto [entity, figure, controls] = gm.registry.create<Figure, Controls>();
    figure = Figure({0u, 0u}, get_figure_pattern("O"));
    set_controls(Controls(0, 0, 1, 0));
    test_step_back();
}