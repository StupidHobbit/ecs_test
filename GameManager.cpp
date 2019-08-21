#include "GameManager.h"
#include "rendering/BlockRenderer.h"
#include "rendering/BoardsRenderer.h"

GameManager::GameManager() :
        window(sf::VideoMode(1365, 768), "Tetris"){}

void GameManager::run() {
    sm.add_system<FiguresSpawnerSystem>();
    sm.add_system<ControlSystem>();
    sm.add_system<RotatingSystem>();
    sm.add_system<RowsCleaningSystem>();
    sm.add_system<BoostSystem>();
    auto step_size = sm.get_step_size();

    sf::Clock clock;
    BlockRenderer block_renderer(sm.registry);
    BoardsRenderer boards_renderer;

    auto view = window.getDefaultView();
    view.setCenter((sf::Vector2f(0, 0) + boards_renderer.get_size()) / 2.f);
    window.setView(view);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        auto current_step = clock.getElapsedTime().asMilliseconds() /
                            step_size;
        std::cout << current_step << std::endl;
        if (current_step >= sm.get_step())
            sm.step_forward();

        window.clear(sf::Color::White);

        window.draw(block_renderer);
        window.draw(boards_renderer);

        window.display();
    }
}
