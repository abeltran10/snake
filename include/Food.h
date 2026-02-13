#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <random>
#include <deque>

class Food {

    private:
        sf::Vector2i position;
        
        // Herramientas para números aleatorios
        std::mt19937 gen;
        std::uniform_int_distribution<> distX;
        std::uniform_int_distribution<> distY;


    public:
        Food(const std::deque<sf::Vector2i> snakeBody);
        
        // Genera una nueva posición aleatoria
        void respawn(const std::deque<sf::Vector2i> snakeBody);
        
        // Dibuja la comida en la ventana
        void draw(sf::RenderWindow& window, int gridSize) const;

        // Getter para saber dónde está la comida
        sf::Vector2i getPosition() const;

};

#endif