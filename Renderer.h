#ifndef TETRIS_RENDERER_H
#define TETRIS_RENDERER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <entt/entity/registry.hpp>

class Renderer {
    sf::RenderWindow &window;
    entt::registry &registry;

    sf::RectangleShape block_rectangle;
    void draw_blocks();

    sf::VertexArray boards;
    void draw_boards();
public:
    Renderer(sf::RenderWindow &window, entt::registry &registry);
    void render();
};


#endif //TETRIS_RENDERER_H
