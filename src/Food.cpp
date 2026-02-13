#include "../include/Food.h"

Food::Food(const std::deque<sf::Vector2i> snakeBody) : gen(std::random_device{}()), distX(0, 29), distY(0, 39) {
    // El constructor inicializa el generador y coloca la primera comida
    respawn(snakeBody);
}

void Food::respawn(const std::deque<sf::Vector2i> snakeBody) {
    bool collision = true;
    while (collision) {
        position.x = distX(gen);
        position.y = distY(gen);
        collision = false;

        // Comprobamos contra TODO el cuerpo (incluida la cabeza)
        for (size_t i = 0; i < snakeBody.size(); ++i) {
            if (snakeBody[i] == position) {
                collision = true;
                break;
            }
        }
    }
}

void Food::draw(sf::RenderWindow& window, int gridSize) const {
    sf::RectangleShape shape(sf::Vector2f(gridSize - 1, gridSize - 1));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position.x * gridSize, position.y * gridSize);
    window.draw(shape);
}

sf::Vector2i Food::getPosition() const {
    return position;
}