#ifndef TETRIS_COMMON_H
#define TETRIS_COMMON_H

#include <experimental/random>
#include <queue>
#include "getters.h"


template<class T>
auto &choice(T &container) {
    auto index = std::experimental::randint(0ul, container.size() - 1);
    for (auto &element:container)
        if (not index--)
            return element;
}

template <class T>
class History : public std::queue<T>{
    size_t max_size;
public:
    History(): max_size(get_history_max_size()){}
};

#endif //TETRIS_COMMON_H
