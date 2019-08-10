#ifndef TETRIS_GAMEMANAGER_H
#define TETRIS_GAMEMANAGER_H


#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "SystemManager.h"

class GameManager {
    SystemManager sm;
    sf::RenderWindow window;
public:
    GameManager();
    void run();
};


#endif //TETRIS_GAMEMANAGER_H
