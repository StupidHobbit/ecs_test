#ifndef TETRIS_BOARDSRENDERER_H
#define TETRIS_BOARDSRENDERER_H


#include <SFML/Graphics.hpp>

class BoardsRenderer : public sf::Drawable, public sf::Transformable {
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::VertexArray boards;
    sf::Vector2f size;
public:
    sf::Vector2f get_size(){
        return size;
    }
    BoardsRenderer();
};


#endif //TETRIS_BOARDSRENDERER_H
