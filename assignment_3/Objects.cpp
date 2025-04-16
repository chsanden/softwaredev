#include "Objects.h"
#include <SFML/Graphics/Shape.hpp>
#include <random>

Rectangle::Rectangle(const float x, const float y, sf::RectangleShape& name, Size& size,
                     sf::RenderWindow& window)
    :
    x(x), y(y), name(name), window(window), size(size)
{
    name.setSize(sf::Vector2f(x, y));
    name.setFillColor(sf::Color::White);
}
void Rectangle::draw(const float x, const float y)
    {
        name.setPosition(sf::Vector2f(x, y));
        window.draw(name);
    }

void Rectangle::move(const float coefficient)
{
    float nx = 0;
    float ny = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        ny -= speed * coefficient;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        ny += speed * coefficient;
    }
    const sf::Vector2f rectSize = name.getSize();

    if(y + ny < 0)
    {
        ny = -y;
    }
    if(y + ny > static_cast<float>(size.height) - rectSize.y)
    {
        ny = static_cast<float>(size.height) - rectSize.y - y;
    }

    x += nx;
    y += ny;

    draw(x, y);
}

Ball::Ball(const float rad, sf::CircleShape &name, Size &size, sf::RenderWindow &window)
    :
rad(rad), name(name), window(window), size(size)
{
    name.setRadius(rad);
    name.setFillColor(sf::Color::White);
}

void Ball::draw(const float x, const float y)
{
    name.setPosition(sf::Vector2f(x, y));
    window.draw(name);
}

void Ball::move(float coefficient)
{
    if(!isMoving && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)))
    {
        isMoving = true;

        std::random_device rd;
        std::mt19937 rand(rd());
        std::uniform_int_distribution vec(0, 1);
        int start = (vec(rand) == 0) ? 1 : -1;
        nx = static_cast<float>(start) * speed;
        ny = static_cast<float>(start) * speed;
    }

    if(isMoving)
    {
        x += nx * coefficient;
        y += ny * coefficient;

        const float diam = 2 * rad;

        if(y < 0)
        {
            y = 0;
            ny = -ny;
        }
        else if (y > static_cast<float>(size.height) - diam)
        {
            y = static_cast<float>(size.height) - diam;
            ny = -ny;
        }
        if(x - rad < 0 || x + rad > static_cast<float>(size.width))
        {
            if(x - rad < 0)
            {

            }

            //Reset back to centre
            x = (static_cast<float>(size.width) - diam) / 2;
            y = (static_cast<float>(size.height) - diam) / 2;

            isMoving = false;
            nx = 0;
            ny = 0;
        }
    }

    draw(x, y);
}



