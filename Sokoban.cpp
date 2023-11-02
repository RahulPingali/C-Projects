// Copyright [2023] [Rahul Pingali]

#include "Sokoban.hpp"
#include <algorithm>
#include <SFML/Audio.hpp>

Sokoban::Sokoban() {
    x = 0;
    y = 0;
    map = nullptr;
    if (map != nullptr) {
        delete[] map;
    }
    map = new char[x*y];
    for (int i = 0; i < x*y; i++) {
        map[i] = ' ';
    }
}

std::istream& operator>>(std::istream& in, Sokoban& s) {
    in >> s.y >> s.x;
    s.map = new char[s.y*s.x];
    for (int i = 0; i < s.y*s.x; i++) {
        s.map[i] = ' ';
    }
    for (int i = 0; i < s.y; i++) {
        for (int j = 0; j < s.x; j++) {
            int index = i*s.x+j;
            in >> s.map[index];
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Sokoban& s) {
    for (int i = 0; i < s.y; i++) {
        for (int j = 0; j < s.x; j++) {
            int index = i*s.x+j;
            out << s.map[index];
        }
        out << std::endl;
    }
    return out;
}

int Sokoban::getX() const {
    return x;
}

int Sokoban::getY() const {
    return y;
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Texture texture;
    if (!texture.loadFromFile("stone.png")) {
        return;
    }

    sf::Sprite sprite(texture);
    sf::Texture texture2;
    if (!texture2.loadFromFile("ground1.png")) {
        return;
    }

    sf::Sprite sprite2(texture2);
    sf::Texture texture3;
    if (!texture3.loadFromFile("red.png")) {
        return;
    }

    sf::Sprite sprite3(texture3);
    sf::Texture texture4;
    if (!texture4.loadFromFile("ground_04.png")) {
        return;
    }
    sf::Sprite sprite4(texture4);

    sf::Texture texture5;
    if (!texture5.loadFromFile("player1.png")) {
        return;
    }
    sf::Sprite sprite5(texture5);
    int sprite_x = 64;
    int sprite_y = 64;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            switch (map[i * x + j]) {
                case '#':
                sprite.setPosition(j * sprite_x, i * sprite_y);
                target.draw(sprite);
                break;

                case '.':
                sprite2.setPosition(j * sprite_x, i * sprite_y);
                target.draw(sprite2);
                break;
                case 'A':
                sprite3.setPosition(j * sprite_x, i * sprite_y);
                target.draw(sprite3);
                break;
                case 'a':
                sprite4.setPosition(j * sprite_x, i * sprite_y);
                target.draw(sprite4);
                break;
                default:
                sprite2.setPosition(j * sprite_x, i * sprite_y);
                sprite5.setPosition(j * sprite_x, i * sprite_y);
                target.draw(sprite2);
                target.draw(sprite5);
                }
             }
         }
     }


Sokoban::~Sokoban() {
    if (map != nullptr) {
        delete[] map;
    }
}

void Sokoban::movePlayer(Direction d) {
    auto playerIt = std::find(map, map + x * y, '@');
    int p_index = playerIt - map;
    switch (d) {
    case UP:
         if (p_index - x >= 0 && map[p_index - x] != '#') {
                if (map[p_index - x] == 'A') {
                    if (p_index - 2 * x >= 0 && map[p_index - 2 * x] != '#' && map[p_index - 2 * x] != 'A') { // NOLINT
                        if (map[p_index - 2 * x] == 'a') {
                            map[p_index - 2 * x] = 'A';
                        } else {
                            map[p_index - 2 * x] = 'A';
                        }
                        if (map[p_index - x] == 'a') {
                            map[p_index] = 'a';
                        } else {
                            map[p_index] = '.';
                        }
                        map[p_index - x] = '@';
                    }
                } else if (map[p_index - x] == 'a') {
                    map[p_index - x] = '@';
                    map[p_index] = 'a';
                } else if (map[p_index - x] != 'a') {
                    map[p_index - x] = '@';
                    if (map[p_index] == 'a') {
                        map[p_index] = 'a';
                    } else {
                        map[p_index] = '.';
                    }
                }
            }
    sf::sleep(sf::milliseconds(100));
    break;
        case DOWN:
            if (p_index + x < x * y && map[p_index + x] != '#') {
                if (map[p_index + x] == 'A') {
                    if (map[p_index + 2 * x] != '#') {
                        if (map[p_index + 2 * x] == 'a') {
                            map[p_index + 2 * x] = 'A';
                            map[p_index + x] = '@';
                            map[p_index] = '.';
                        } else {
                            map[p_index + 2 * x] = 'A';
                            map[p_index + x] = '@';
                            map[p_index] = '.';
                        }
                    }
                } else if (map[p_index + x] == 'a') {
                    map[p_index + x] = '@';
                    map[p_index] = '.';
                } else {
                    map[p_index + x] = '@';
                    map[p_index] = '.';
                }
            }
            sf::sleep(sf::milliseconds(100));
            break;
        case LEFT:
            if (p_index % x > 0 && map[p_index - 1] != '#') {
                if (map[p_index - 1] == 'A') {
                    if (map[p_index - 2] != '#') {
                        if (map[p_index - 2] == 'a') {
                            map[p_index - 2] = 'A';
                            map[p_index - 1] = '@';
                            map[p_index] = '.';
                        } else {
                            map[p_index - 2] = 'A';
                            map[p_index - 1] = '@';
                            map[p_index] = '.';
                        }
                    }
                } else if (map[p_index - 1] == 'a') {
                    map[p_index - 1] = '@';
                    map[p_index] = '.';
                } else {
                    map[p_index - 1] = '@';
                    map[p_index] = '.';
                }
            }
            sf::sleep(sf::milliseconds(100));
            break;
        case RIGHT:
        if (p_index % x < x-1 && map[p_index + 1] != '#') {
            if (map[p_index + 1] == 'A') {
                if (map[p_index + 2] != '#') {
                    if (map[p_index + 2] == 'a') {
                        map[p_index + 2] = 'A';
                        map[p_index + 1] = '@';
                        map[p_index] = '.';
                    } else {
                        map[p_index + 2] = 'A';
                        map[p_index + 1] = '@';
                        map[p_index] = '.';
                    }
                }
            } else if (map[p_index + 1] == 'a') {
                map[p_index + 1] = '@';
                map[p_index] = '.';
            } else {
                map[p_index + 1] = '@';
                map[p_index] = '.';
            }
            sf::sleep(sf::milliseconds(100));
        }
    }
}

const bool Sokoban::isWon() const {
    int numBoxesOnTargets = 0;
    int numTargets = 0;
    std::for_each(map, map + x * y, [&](const char& c) {
        if (c == 'A' && (std::find(map, map + x * y, 'a') - map) ==
        (std::find(map, map + x * y, 'A') - map + 1)) {
            numBoxesOnTargets++;
        }
        if (c == 'a') {
            numTargets++;
        }
    });
    return numBoxesOnTargets == numTargets;
}

void Sokoban::reset(Sokoban &s) {
    s.x = x;
    s.y = y;
    s.map = new char[x * y];
    for (int i = 0; i < x * y; i++) {
        s.map[i] = map[i];
    }
}

Sokoban::Sokoban(const Sokoban &s) {
    x = s.x;
    y = s.y;
    map = new char[x * y];
    for (int i = 0; i < x * y; i++) {
        map[i] = s.map[i];
    }
}

Sokoban& Sokoban::operator=(const Sokoban &s) {
    if (this != &s) {
        x = s.x;
        y = s.y;
        delete[] map;
        map = new char[x * y];
        for (int i = 0; i < x * y; i++) {
            map[i] = s.map[i];
        }
    }
    return *this;
}


