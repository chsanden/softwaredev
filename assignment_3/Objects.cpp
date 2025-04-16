#include "Objects.h"
#include "Rectangle.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <thread>

#include "Size.h"

Size temp(800, 400);


Rectangle::Rectangle(const float xPos, const float yPos, sf::RectangleShape name, Size& size,
                     sf::RenderWindow& window)
    :
    Object(xPos, yPos), name(name), window(window), size(size)
{
    name.setSize(sf::Vector2f(temp.paddleSizeX, temp.paddleSizeY));
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

void Rectangle::aiMove(const float coefficient, const Circle &ball)
{
    float deltaY = 0.0f;

    if (ball.yPos > yPos)
    {
        deltaY += ySpeed * coefficient;
    }
    if (ball.yPos < yPos)
    {
        deltaY -= ySpeed * coefficient;
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

    //Boundary checks -- copy from aiMove
    const sf::Vector2f rectSize = name.getSize();
    if(yPos + deltaY < 0)
    {
        deltaY = -yPos;
    }
    if(yPos + deltaY > static_cast<float>(size.height) - rectSize.y)
    {
        deltaY = static_cast<float>(size.height) - rectSize.y - yPos;
    }

    //Update and draw position -- copy from asiMove
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

int Circle::draw(sf::RenderWindow &window) {
    // Call your own draw function using the current position.
    return draw(xPos, yPos);
}

int Circle::move(float coefficient)
{
    if(!isMoving)
    {
        isMoving = true;
        //Random initial direction
        std::random_device rd;
        std::mt19937 rand(rd());
        std::uniform_real_distribution<float> angleDistribution(-45.0f, 45.0f);
        std::uniform_int_distribution<int> directionDistribution(0, 1);

        const float angle = angleDistribution(rand) * 3.14159f / 180.0f;
        const float direction = directionDistribution(rand) == 0 ? -1.0f : 1.0f;

        constexpr float minXSpeed = 4.0f;
        nx = direction * speed * std::cos(angle);
        nx = (std::abs(nx) < minXSpeed) ? minXSpeed * direction : nx;
        ny = speed * std::sin(angle);
        return 6;
    }


    xPos += nx * coefficient;
    yPos += ny * coefficient;

    const float diam = 2 * rad;

    //Roof and floor collisions
    if (yPos + diam < 0)
    {
        yPos = 0;
        ny = -ny;
        coefficient += (coefficient * 10)/100;
        return 5;
    }
    if (yPos + diam > static_cast<float>(size.height))
    {
        yPos = static_cast<float>(size.height) - diam;
        ny = -ny;
        coefficient += (coefficient * 10)/100;
        return 5;
    }

    //Collisions with right and left "walls" --> scoring
    if (xPos + diam < 0)
    {
        resetCircle();
        return -1;
    }

    // Right side (scoring for left player)
    if (xPos > static_cast<float>(size.width))
    {
        resetCircle();
        return 1;
    }

    draw(xPos, yPos);
    return 7;
}

void Circle::resetCircle()
{
    // Reset back to center
    xPos = static_cast<float>(size.width) / 2;
    yPos = static_cast<float>(size.height) / 2;
    isMoving = false;
    nx = 0;
    ny = 0;
    speed = 4.0f;
}

int Circle::getRad() const
{
    return rad;
}

float Circle::getNX() const
{
    return nx;
}

float Circle::getNY() const
{
    return ny;
}

float Circle::setNX(float nx)
{
    return this->nx = nx;
}

float Circle::setNY(float ny)
{
    return this->ny = ny;
}

float Circle::getSpeed() const
{
    return speed;
}

float Circle::speedIncr()
{
    this->speed += 0.25f;
    return this->speed;
}
