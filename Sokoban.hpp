//// Copyright [2023] [Rahul Pingali]

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum Direction {UP, DOWN, LEFT, RIGHT};
class Sokoban: public sf::Drawable {
 public:
    Sokoban();
    void movePlayer(Direction d);
    friend std::istream& operator>>(std::istream& in, Sokoban& s);
    friend std::ostream& operator<<(std::ostream& out, const Sokoban& s);
    int getX() const;
    int getY() const;
    const bool isWon() const;
    void reset(Sokoban& s);
    Sokoban(const Sokoban& s);
    void loadMap(const std::string& filename, Sokoban& s);
    ~Sokoban();
    Sokoban& operator=(const Sokoban& s);
 private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // NOLINT
    int x;
    int y;
    char *map;
};

