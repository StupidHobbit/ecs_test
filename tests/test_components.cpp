#include <gtest/gtest.h>
#include <fstream>

#include "../Components.h"

using testing::Eq;

bool operator==(const Block a, const Block b) {
    return a.row == b.row and
           a.column == b.column;
}


TEST(FigurePattern, load_from_file_O) {
    FigurePattern figure_pattern;
    figure_pattern.load_from_file("../resources/figures/O");
    ASSERT_EQ(figure_pattern.states.size(), 1);
}

TEST(FigurePattern, load_from_file_I) {
    FigurePattern figure_pattern;
    figure_pattern.load_from_file("../resources/figures/I");
    ASSERT_EQ(figure_pattern.states.size(), 2);
}

TEST(FigureState, load_from_stream_I1) {
    FigureState figure_state;
    std::ifstream fin("../resources/figures/I");
    std::string s;
    std::getline(fin, s);
    figure_state.load_from_stream(fin);
    ASSERT_EQ(figure_state.blocks[0], Block({0, 0}));
    ASSERT_EQ(figure_state.blocks[1], Block({0, 1}));
    ASSERT_EQ(figure_state.blocks[2], Block({0, 2}));
    ASSERT_EQ(figure_state.blocks[3], Block({0, 3}));
}

TEST(FigureState, load_from_stream_I2) {
    FigureState figure_state;
    std::ifstream fin("../resources/figures/I");
    std::string s;
    std::getline(fin, s);
    figure_state.load_from_stream(fin);
    std::getline(fin, s);
    figure_state.load_from_stream(fin);
    ASSERT_EQ(figure_state.blocks[0], Block({0, 1}));
    ASSERT_EQ(figure_state.blocks[1], Block({1, 1}));
    ASSERT_EQ(figure_state.blocks[2], Block({2, 1}));
    ASSERT_EQ(figure_state.blocks[3], Block({3, 1}));
}