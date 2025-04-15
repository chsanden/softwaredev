#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

unsigned xWindow = 800;
unsigned yWindow = 600;


int main()
{
    sf::RenderWindow window(sf::VideoMode({xWindow, yWindow}), "Pong");
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

        }



}
