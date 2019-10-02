#include "base.h"


TEST_F(SystemsTest, FiguresSpawnerSystem_step_forward_not_valid) {
    FiguresSpawnerSystem system(&registry);
    auto[entity, figure] = registry.create<Figure>();
    figure = Figure({1u, 1u}, get_figure_pattern("O"));
    figure.is_valid = false;
    auto expected_center = next_block_position();
    system.step_forward(16);
    ASSERT_TRUE(figure.is_valid);
    ASSERT_EQ(figure.center, expected_center);
}