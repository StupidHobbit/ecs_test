#include "GameManager.h"

GameManager::GameManager() :
        window(sf::VideoMode(1365, 768), "Tetris"),
        renderer(window, sm.registry){}

void GameManager::run() {
    sm.add_system<FiguresSpawnerSystem>();
    sm.add_system<ControlSystem>();
    sm.add_system<TestSystem>();
    auto step_size = sm.get_step_size();

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        auto current_step = clock.getElapsedTime().asMilliseconds() /
                            step_size;
        if (current_step >= sm.get_step())
            sm.step_forward();

        renderer.render();
    }
}
