// Copyright [2023] [Rahul Pingali]

#include "Sokoban.hpp"
#include <SFML/Audio.hpp>

int main(int argc, char* argv[]) {
    std::ifstream map_level(argv[1]);
    if (!map_level) {
        std::cout << "File not found" << std::endl;
        return 0;
    }
    Sokoban s;
    map_level >> s;
    sf::RenderWindow window(sf::VideoMode(s.getX()*64, s.getY()*64), "Sokoban");
    Sokoban temp = s;
    while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::R) {
                s = temp;
                s.reset(temp);
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    }

    if (!s.isWon()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            s.movePlayer(LEFT);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            s.movePlayer(RIGHT);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            s.movePlayer(UP);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            s.movePlayer(DOWN);
        }
    }

    window.clear();
    window.draw(s);

    if (s.isWon()) {
        sf::Font font;
        if (!font.loadFromFile("Roboto-Bold.ttf")) {
            return EXIT_FAILURE;
        }
        sf::Text text("You Win!", font, 50);
        text.setFillColor(sf::Color::Red);
        sf::FloatRect textRect = text.getLocalBounds();

        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        text.setPosition(sf::Vector2f(s.getX()*32, s.getY()*32));
        window.draw(text);
        window.display();
    }

    window.display();
}
}
