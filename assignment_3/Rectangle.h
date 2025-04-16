#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Size.h"
#include <SFML/Graphics.hpp>
#include "Objects.h"

class Rectangle : public Object {
public:
    //Definition
    Rectangle(float xPos, float yPos, sf::RectangleShape name, Size& size, sf::RenderWindow &window);

    //Functions
    int draw(float x, float y);
    int draw(sf::RenderWindow &window) override;
    int move(float coefficient) override;

private:
    //Constant
    const float ySpeed = 400.0f;

    //Dependencies
    sf::RectangleShape name;
    sf::RenderWindow& window;
    Size& size;
};



#endif //RECTANGLE_H
