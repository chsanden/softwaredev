#include <optional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Size.h"


Size size;
constexpr int paddleSizeX = 20;
constexpr int paddleSizeY = 80;
const int paddleStartY = (static_cast<int>(size.height) - paddleSizeY) / 2;

int main()
{
    sf::RenderWindow window(sf::VideoMode({size.width, size.height}), "Pong");
    window.clear(sf::Color::Black);
    window.display();
    window.setVerticalSyncEnabled(true);
    sf::RectangleShape Paddle;
    Paddle.setSize(sf::Vector2f(paddleSizeX, paddleSizeY));
    sf::CircleShape gameBall;
    gameBall.setRadius(15);
    Rectangle rightPaddle(static_cast<int>(size.width) - paddleSizeX, paddleStartY, Paddle, size, window );
    Rectangle leftPaddle(paddleSizeX, paddleStartY, Paddle, size, window );
    Circle ball(15, static_cast<int>(size.width) / 2, static_cast<int>(size.height) / 2, gameBall, size, window);

    while (window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            leftPaddle.move(0.05);
            ball.move(0.001);
        }
        ball.move(0.001);


        window.clear(sf::Color::Black);
        rightPaddle.draw(window);
        leftPaddle.draw(window);
        ball.draw(window);
        window.display();
    }

    return 0;

}
