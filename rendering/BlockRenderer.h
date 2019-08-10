#ifndef TETRIS_BLOCKRENDERER_H
#define TETRIS_BLOCKRENDERER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <entt/entity/registry.hpp>

class BlockRenderer : public sf::Drawable, public sf::Transformable {
    entt::registry &registry;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
    BlockRenderer(entt::registry &registry);
};


#endif //TETRIS_BLOCKRENDERER_H
