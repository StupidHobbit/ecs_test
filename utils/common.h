#ifndef TETRIS_COMMON_H
#define TETRIS_COMMON_H

#include <experimental/random>


template<class T>
auto &choice(T &container) {
    auto index = std::experimental::randint(0ul, container.size() - 1);
    for (auto &element:container)
        if (not index--)
            return element;
}

#endif //TETRIS_COMMON_H
