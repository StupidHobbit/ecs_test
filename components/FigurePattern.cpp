#include <fstream>
#include <experimental/filesystem>
#include <unordered_map>
#include "FigurePattern.h"

namespace fs = std::experimental::filesystem;


void FigurePattern::load_from_file(std::string const &path) {
    name = fs::path(path).filename();
    std::ifstream fin(path);
    std::string s;
    while (std::getline(fin, s)) {
        FigureState figure_state;
        figure_state.load_from_stream(fin);
        states.push_back(figure_state);
    }
}


FigurePattern &get_figure_pattern(std::string const &name) {
    static std::unordered_map<std::string, FigurePattern> cache;
    FigurePattern &pattern = cache[name];
    if (not pattern.name.size())
        pattern.load_from_file("../resources/figures/" + name);
    return pattern;
}