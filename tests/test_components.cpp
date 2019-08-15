#include <gtest/gtest.h>
#include <fstream>

#include "../Components.h"
#include "../Systems.h"
#include "utils.h"

using testing::Eq;


TEST(FigurePattern, load_from_file_O) {
    FigurePattern figure_pattern;
    figure_pattern.load_from_file("../resources/figures/O");
    ASSERT_EQ(figure_pattern.states.size(), 1);
    ASSERT_EQ(figure_pattern.name, "O");
}

TEST(FigurePattern, load_from_file_I) {
    FigurePattern figure_pattern;
    figure_pattern.load_from_file("../resources/figures/I");
    ASSERT_EQ(figure_pattern.states.size(), 2);
    ASSERT_EQ(figure_pattern.name, "I");
}

TEST(FigurePattern, get_figure_pattern_I) {
    FigurePattern &figure_pattern = get_figure_pattern("I");
    ASSERT_EQ(figure_pattern.states.size(), 2);
    ASSERT_EQ(figure_pattern.name, "I");
}

TEST(FigureState, load_from_stream_I1) {
    FigureState figure_state;
    std::ifstream fin("../resources/figures/I");
    std::string s;
    std::getline(fin, s);
    figure_state.load_from_stream(fin);
    ASSERT_EQ(figure_state.blocks[0], Block({0, -1u}));
    ASSERT_EQ(figure_state.blocks[1], Block({0, 0}));
    ASSERT_EQ(figure_state.blocks[2], Block({0, 1}));
    ASSERT_EQ(figure_state.blocks[3], Block({0, 2}));
}

TEST(FigureState, load_from_stream_I2) {
    FigureState figure_state;
    std::ifstream fin("../resources/figures/I");
    std::string s;
    std::getline(fin, s);
    figure_state.load_from_stream(fin);
    std::getline(fin, s);
    figure_state.load_from_stream(fin);
    ASSERT_EQ(figure_state.blocks[0], Block({-1u, 0}));
    ASSERT_EQ(figure_state.blocks[1], Block({0, 0}));
    ASSERT_EQ(figure_state.blocks[2], Block({1, 0}));
    ASSERT_EQ(figure_state.blocks[3], Block({2, 0}));
}

class FigureTest : public testing::Test {
public:
protected:
    virtual void SetUp() {
        figure = Figure({0u, 0u}, get_figure_pattern("O"));
        entity1 = registry.create();
        entity2 = registry.create();
    }

    Figure figure;
    entt::registry registry;
    entt::entity entity1, entity2;
};

TEST_F(FigureTest, spawn) {
    spawn(registry, figure);
    auto table = get_table_from(registry);
    ASSERT_EQ(count_blocks(table), FIGURE_NUMBER_OF_BLOCKS);
    ASSERT_TRUE(table[0][0]);
    ASSERT_TRUE(table[0][1]);
    ASSERT_TRUE(table[1][0]);
    ASSERT_TRUE(table[1][1]);
}
