#ifndef TETRIS_RENDERER_H
#define TETRIS_RENDERER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <entt/entity/registry.hpp>

class Renderer {
    sf::RenderWindow &window;
    entt::registry &registry;
public:
    Renderer(sf::RenderWindow &window, entt::registry &registry);
    void render();
};


#endif //TETRIS_RENDERER_H
