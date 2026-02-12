#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    window.setFramerateLimit(60);

    // Representamos la cabeza como un rectángulo
    sf::RectangleShape head(sf::Vector2f(20, 20));
    head.setFillColor(sf::Color::Green);
    head.setPosition(400, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // Movimiento simple
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    head.move(0, -5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  head.move(0, 5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  head.move(-5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) head.move(5, 0);

        window.clear();
        window.draw(head);
        window.display();
    }
    return 0;
}