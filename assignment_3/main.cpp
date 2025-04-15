#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

unsigned x = 800;
unsigned y = 600;


int main()
{
    sf::RenderWindow window(sf::VideoMode({x, y}), "Pong");
    window.setVerticalSyncEnabled(true);


    while (window.isOpen())
        {

        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }



        }



}
