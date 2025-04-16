#ifndef OBJECTS_H
#define OBJECTS_H
#include <SFML/Graphics.hpp>
#include "Size.h"


class Rectangle {
    public:
    //Definition
    Rectangle(float x, float y, sf::RectangleShape& name, Size& size, sf::RenderWindow& window);

    //Functions
    void draw(float x, float y);
    void move(float coefficient);

    private:
    //Variables
    const float speed = 400;
    float x;
    float y;

    //Dependencies
    sf::RectangleShape name;
    sf::RenderWindow& window;
    Size& size;
};

class Ball {
    public:
    //Definition
    Ball(float rad, sf::CircleShape& name, Size &size, sf::RenderWindow &window);

    //Functions
    void draw(float x, float y);
    void move(float coefficient);

private:
    //Variables
    const float speed = 400;
    float rad;
    float x = static_cast<float>(size.width) / 2;
    float y = static_cast<float>(size.height) / 2;
    float nx = 0;
    float ny = 0;
    bool isMoving = false;

    //Dependencies
    sf::CircleShape name;
    sf::RenderWindow& window;
    Size& size;
};

#endif //OBJECTS_H
