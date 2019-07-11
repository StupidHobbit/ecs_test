#include <fstream>
#include "FigurePattern.h"

void FigurePattern::load_from_file(std::string filename) {
    std::ifstream fin(filename);
    std::string s;
    while(std::getline(fin, s)){
        FigureState figure_state;
        figure_state.load_from_stream(fin);
        states.push_back(figure_state);
    }
}
