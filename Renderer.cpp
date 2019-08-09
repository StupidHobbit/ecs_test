#include <SFML/Graphics/RectangleShape.hpp>
#include "Renderer.h"
#include "Systems.h"
#include "utils/getters.h"

const float CELL_SIZE = 10;
const float OUTLINE_SIZE = 2;
const float CELL_FULL_SIZE = CELL_SIZE + OUTLINE_SIZE;

Renderer::Renderer(sf::RenderWindow &window, entt::registry &registry) :
        window(window),
        registry(registry),
        block_rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE)),
        boards(sf::LineStrip, 4){
    block_rectangle.setFillColor(sf::Color::Red);
    block_rectangle.setOutlineColor(sf::Color::Black);
    block_rectangle.setOutlineThickness(OUTLINE_SIZE);

    auto field_size = get_field_size();
    field_size.first = (field_size.first - 1) * CELL_FULL_SIZE;
    field_size.second = (field_size.second - 1) * CELL_FULL_SIZE;
    boards[0].position = sf::Vector2f(-OUTLINE_SIZE, -OUTLINE_SIZE);
    boards[1].position = sf::Vector2f(field_size.second, -OUTLINE_SIZE);
    boards[2].position = sf::Vector2f(field_size.second, field_size.first);
    boards[3].position = sf::Vector2f(-OUTLINE_SIZE, field_size.first);

    boards[0].color = sf::Color::Black;
    boards[1].color = sf::Color::Black;
    boards[2].color = sf::Color::Black;
    boards[3].color = sf::Color::Black;
}

void Renderer::render() {
    window.clear(sf::Color::White);

    draw_blocks();
    draw_boards();

    window.display();
}

void Renderer::draw_blocks() {
    auto table = get_table_from(registry);
    for (int i = 1; i < table.size(); i++)
        for (int j = 0; j < table[i].size(); j++)
            if (table[i][j]) {
                block_rectangle.setPosition(sf::Vector2f(j, i - 1) * CELL_FULL_SIZE);
                window.draw(block_rectangle);
            }
}

void Renderer::draw_boards() {
    window.draw(boards);
}
