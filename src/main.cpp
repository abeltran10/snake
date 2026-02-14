#include <SFML/Graphics.hpp>

#include "../include/Snake.h"
#include "../include/Food.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 800), "Snake");
    window.setFramerateLimit(60);

    sf::Clock clock;
    float timer = 0, delay = 0.1;

    Snake snake;
    Food food(snake.getBody());

    bool isPaused = false;
    
    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            // Detectar si se pulsó el Espacio
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    isPaused = !isPaused; // Invierte el valor: si era true pasa a false y viceversa
                }
            }
        }

        if (!isPaused) {
            // Obtenemos cuánto duró esta vuelta del bucle (ej: 0.016s)
            float time = clock.getElapsedTime().asSeconds();
            clock.restart(); // Ponemos el cronómetro a cero para la siguiente vuelta
            timer += time;


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
            
                // ¿Hay colisión con la comida?
                if (snake.getHead() == food.getPosition()) {
                    snake.update(true); // Crece
                    food.respawn(snake.getBody());     // Nueva comida
                } else {
                    snake.update(false); // Movimiento normal
                }

                // Comprobar colisión con los bordes
                if (snake.getHead().x < 0 || snake.getHead().x >= 30 || snake.getHead().y < 0 || snake.getHead().y >= 40) {
                    window.close(); // Esto cierra la aplicación
                }

                // Comprobar que no colisiona con ella misma
                if (snake.checkSelfCollision()) {
                    window.close();
                }

                // Vaciamos para volver a empezar
                timer = 0;
            }
        } else {
            // Si está pausado, debemos reiniciar el reloj constantemente 
            // para que cuando quitemos la pausa, el 'timer' no dé un salto gigante.
            clock.restart();
        }

        window.clear();
        snake.draw(window, 20);
        food.draw(window, 20);
        window.display();
    }

    return 0;
}