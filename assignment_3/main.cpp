#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Size.h"


Size size;

int main()
{
    sf::RenderWindow window(sf::VideoMode(({size.width, size.height}), "Pong");
    window.setVerticalSyncEnabled(true);

    sf::CircleShape ball(20.0f);
    ball.setFillColor(sf::Color::White);

    sf::RectangleShape rightPaddle(sf::Vector2f(20.0f, 60.0f));
    sf::RectangleShape leftPaddle(sf::Vector2f(20.0f, 60.0f));




    while (window.isOpen())
        {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        window.draw(ball);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.display();
        }



}
