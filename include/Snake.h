#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <deque>

class Snake {
    private:
        std::deque<sf::Vector2i> body;
        sf::Vector2i direction;


    public:
        // Constructor
        Snake();



        // Métodos principales
        void draw(sf::RenderWindow& window, int gridSize) const;
        void update(bool grow);
        bool checkSelfCollision() const;

        // Getters
        sf::Vector2i getDirection() const;
        sf::Vector2i getHead() const;
        std::deque<sf::Vector2i> getBody() const;

        //Setters
        void setDirection(sf::Vector2i direction);
     

};

#endif