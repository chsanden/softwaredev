#include "Objects.h"
#include "Rectangle.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <random>



Rectangle::Rectangle(const float xPos, const float yPos, sf::RectangleShape name, Size& size,
                     sf::RenderWindow& window)
    :
    Object(xPos, yPos), name(name), window(window), size(size)
{
    name.setSize(sf::Vector2f(xPos, yPos));
    name.setFillColor(sf::Color::White);
    name.setPosition(sf::Vector2f(xPos, yPos));
}
int Rectangle::draw(const float x, const float y)
{
    name.setPosition(sf::Vector2f(x, y));
    window.draw(name);
    return 2;
}

int Rectangle::draw(sf::RenderWindow &window) {
    // Call your own draw function using the current position.
    return draw(xPos, yPos);
}


int Rectangle::move(const float coefficient)
{
    float deltaY = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        deltaY -= ySpeed * coefficient;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        deltaY += ySpeed * coefficient;
    }

    //Boundary checks
    const sf::Vector2f rectSize = name.getSize();
    if(yPos + deltaY < 0)
    {
        deltaY = -yPos;
    }
    if(yPos + deltaY > static_cast<float>(size.height) - rectSize.y)
    {
        deltaY = static_cast<float>(size.height) - rectSize.y - yPos;
    }

    //Update and draw position
    yPos += deltaY;
    draw(xPos, yPos);
    return 4;
}

Circle::Circle(float rad, float xPos, float yPos, sf::CircleShape name, Size &size, sf::RenderWindow &window)
    :
    Object(xPos, yPos), rad(rad), name(name), window(window), size(size)
{
    name.setRadius(rad);
    name.setFillColor(sf::Color::White);
    name.setPosition(sf::Vector2f(xPos, yPos));
}

int Circle::draw(const float x, const float y)
{
    name.setPosition(sf::Vector2f(x, y));
    window.draw(name);
    return 2;
}

int Circle::move(float coefficient)
{
    if(!isMoving && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)))
    {
        isMoving = true;
        //Random initial direction
        std::random_device rd;
        std::mt19937 rand(rd());
        std::uniform_int_distribution vec(0, 1);
        int start = (vec(rand) == 0) ? 1 : -1;
        nx = static_cast<float>(start) * speed;
        ny = static_cast<float>(start) * speed;
        return 6;
    }

    if(isMoving)
    {
        xPos += nx * coefficient;
        yPos += ny * coefficient;

        const float diam = 2 * rad;

        //Roof and floor collisions
        if(xPos < rad || xPos + rad > static_cast<float>(size.width))
        {
            yPos = 0;
            ny = -ny;
            return 5;
        }
        if (yPos < rad || yPos > static_cast<float>(size.height) - rad)
        {
            yPos = static_cast<float>(size.height) - diam;
            ny = -ny;
            return 5;
        }

        //Collisions with right and left "walls" --> scoring
        if(xPos < rad || xPos + rad > static_cast<float>(size.width))
        {
            //Left player scores
            if(xPos < rad)
            {
                resetCircle();
                return -1;
            }
            //Right player scores
            if(xPos > static_cast<float>(size.width) - rad)
            {
                resetCircle();
                return 1;
            }

            //Resetting movement flag and variables
            isMoving = false;
            nx = 0;
            ny = 0;
            return 7;
        }
        return 4;
    }
    draw(xPos, yPos);
    return 3;
}

int Circle::draw(sf::RenderWindow &window) {
    // Call your own draw function using the current position.
    return draw(xPos, yPos);
}


void Circle::resetCircle()
{
    // Reset back to center
    xPos = static_cast<float>(size.width) / 2;
    yPos = static_cast<float>(size.height) / 2;
    isMoving = false;
    nx = 0;
    ny = 0;
}




