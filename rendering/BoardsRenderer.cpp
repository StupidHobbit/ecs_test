#include "BoardsRenderer.h"
#include "../utils/getters.h"
#include "constants.h"

void BoardsRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(boards, states);
}

BoardsRenderer::BoardsRenderer() : boards(sf::LineStrip, 5) {
    auto field_size = get_field_size();
    size.y = (field_size.first - 1) * CELL_FULL_SIZE;
    size.x = (field_size.second) * CELL_FULL_SIZE;
    boards[0].position = sf::Vector2f(-OUTLINE_SIZE, -OUTLINE_SIZE);
    boards[1].position = sf::Vector2f(size.x, -OUTLINE_SIZE);
    boards[2].position = sf::Vector2f(size.x, size.y);
    boards[3].position = sf::Vector2f(-OUTLINE_SIZE, size.y);
    boards[4].position = boards[0].position;

    for (int i = 0 ; i < 5; i ++)
        boards[i].color = sf::Color::Black;
}
