#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "GameManager.h"

int main() {
    GameManager gm;
    gm.add_system<TestSystem>();
    auto step_size = gm.get_step_size();

    sf::Clock clock;
    sf::Window window(sf::VideoMode(1280, 1024), "Tetris");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        auto current_step = clock.getElapsedTime().asMilliseconds() /
                            step_size;
        if (current_step >= gm.get_step())
            gm.step_forward();
    }

    return 0;
}