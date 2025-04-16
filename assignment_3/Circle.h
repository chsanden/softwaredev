#ifndef CIRCLE_H
#define CIRCLE_H
#include "Size.h"
#include <SFML/Graphics.hpp>
#include "Objects.h"

class Circle : public Object {
public:
    //Definition
    Circle(float rad, float xPos,  float yPos, sf::CircleShape name, Size& size, sf::RenderWindow &window);

    //Functions
    int draw(float x, float y);
    int draw(sf::RenderWindow &window) override;
    int move(float coefficient) override;

private:
    //Reset function declaration
    void resetCircle();

    //Variables
    const float speed = 400.0f;
    float rad;
    float nx = 0;
    float ny = 0;
    bool isMoving = false;

    //Dependencies
    sf::CircleShape name;
    sf::RenderWindow& window;
    Size& size;
};




#endif //CIRCLE_H
