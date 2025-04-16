#ifndef OBJECTS_H
#define OBJECTS_H
#include <SFML/Graphics.hpp>


//Return codes:\
-1 --- Right side player scored\
0 ---- Program exit\
1 ---- Left side player scored\
2 ---- Shape draw function ran\
3 ---- Shape move function ran\
4 ---- Position updated\
5 ---- Collision\
6 ---- Started\
7 ---- Score updated


class Object {
    public:
    virtual ~Object() = default;

    Object(const float xPos, const float yPos) : xPos(xPos), yPos(yPos) {}

    Object()
    {
        xPos = yPos =  0;
    }

    float xPos, yPos;

    virtual int draw(sf::RenderWindow &window) = 0;
    virtual int move(float coefficient) = 0;
};







#endif //OBJECTS_H
