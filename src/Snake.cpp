#include "../include/Snake.h"

// El Constructor: Aquí es donde inicializamos los datos
Snake::Snake() {
    // 1. Inicializamos la dirección hacia arriba
    direction = sf::Vector2i(0, -1);

    // 2. Inicializamos el cuerpo con 3 segmentos iniciales
    // Usamos coordenadas de "rejilla" (casillas), no píxeles.
    body.push_back(sf::Vector2i(10, 10)); // Cabeza
    body.push_back(sf::Vector2i(9, 10));  // Cuerpo
    body.push_back(sf::Vector2i(8, 10));  // Cola
}

void Snake::draw(sf::RenderWindow& window, int gridSize) const {
    for (size_t i = 0; i < body.size(); ++i) {
        sf::RectangleShape shape(sf::Vector2f(gridSize - 1, gridSize - 1));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(body[i].x * gridSize, body[i].y * gridSize);
        window.draw(shape);
    }
}

void Snake::update(bool grow) {
    // Calculamos la posición de la nueva cabeza
    sf::Vector2i newHead = body.front() + direction;
    
    // Insertamos la nueva cabeza siempre
    body.push_front(newHead);
    
    // Si NO ha comido, eliminamos el último segmento para mantener el tamaño
    if (!grow) {
        body.pop_back();
    }
    // Si ha comido (grow == true), no hacemos pop_back y así la serpiente crece
}

sf::Vector2i Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(sf::Vector2i dir) {
    direction = dir;
}
