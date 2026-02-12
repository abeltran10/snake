#include <SFML/Graphics.hpp>

#include "../include/Snake.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 800), "Snake");
    window.setFramerateLimit(60);

    sf::Clock clock;
    float timer = 0, delay = 0.1;

    Snake snake;
    
    while (window.isOpen()) {
        // Obtenemos cuánto duró esta vuelta del bucle (ej: 0.016s)
        float time = clock.getElapsedTime().asSeconds();
        clock.restart(); // Ponemos el cronómetro a cero para la siguiente vuelta
        timer += time;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // Movimiento simple
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getDirection().y != 1) {
            snake.setDirection({0, -1});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getDirection().y != -1) {
            snake.setDirection({0, 1});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getDirection().x != 1) {
            snake.setDirection({-1, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getDirection().x != -1) {
            snake.setDirection({1, 0});
        }

        // Ha pasado el tiempo suficiente (ej: 0.1s)
        if (timer > delay) {
            
            snake.update(false); // Por ahora no crece

            // Comprobar colisión con los bordes
            if (snake.getHead().x < 0 || snake.getHead().x >= 30 || snake.getHead().y < 0 || snake.getHead().y >= 40) {
                window.close(); // Esto cierra la aplicación
            }

            // Vaciamos para volver a empezar
            timer = 0;
        }

        window.clear();
        snake.draw(window, 20);
        window.display();
    }
    return 0;
}