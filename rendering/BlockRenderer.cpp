#include <SFML/Graphics/RectangleShape.hpp>
#include "BlockRenderer.h"
#include "../utils/getters.h"
#include "constants.h"
#include "../systems/utils.h"


BlockRenderer::BlockRenderer(entt::registry &registry) :
        registry(registry){
}

void BlockRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    static sf::RectangleShape block_rectangle (sf::Vector2f(CELL_SIZE, CELL_SIZE));
    block_rectangle.setFillColor(sf::Color::Red);
    block_rectangle.setOutlineColor(sf::Color::Black);
    block_rectangle.setOutlineThickness(OUTLINE_SIZE);

    states.transform *= getTransform();

    auto table = get_table_from(registry);
    for (int i = 1; i < table.size(); i++)
        for (int j = 0; j < table[i].size(); j++)
            if (table[i][j]) {
                block_rectangle.setPosition(sf::Vector2f(j, i - 1) * CELL_FULL_SIZE);
                target.draw(block_rectangle, states);
            }
}
