#include <SFML/Graphics/RectangleShape.hpp>
#include "Renderer.h"
#include "Systems.h"

float CELL_SIZE = 10;

Renderer::Renderer(sf::RenderWindow &window, entt::registry &registry) :
        window(window),
        registry(registry) {}

void Renderer::render() {
    window.clear(sf::Color::White);

    static sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineColor(sf::Color::Black);

    auto table = get_table_from(registry);
    for (int i = 0; i < table.size(); i++)
        for (int j = 0; j < table[i].size(); j++)
            if (table[i][j]){
                rectangle.setPosition(sf::Vector2f(j, i) * CELL_SIZE);
                window.draw(rectangle);
            }

    window.display();
}
