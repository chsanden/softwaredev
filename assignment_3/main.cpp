#include <iostream>
#include <optional>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Size.h"
int rScore = 0;
int lScore = 0;


int main()
{
    Size size(800, 600);

    sf::RenderWindow window(sf::VideoMode({size.width, size.height}), "Pong");
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape paddleShape;
    paddleShape.setSize(sf::Vector2f(static_cast<float>(size.paddleSizeX), static_cast<float>(size.paddleSizeY)));
    sf::CircleShape ballShape;
    ballShape.setRadius(15.0f);

    sf::Font font;
    if (!font.openFromFile("arial.ttf"))
    {
        std::cerr << "Could not load font" << std::endl;
        EXIT_FAILURE;
    }
    sf::Text gameOver(font, "", 30);
    sf::Text lScoreText(font, "", 22);
    sf::Text rScoreText(font, "", 22);
    gameOver.setFillColor(sf::Color::White);
    lScoreText.setFillColor(sf::Color::White);
    rScoreText.setFillColor(sf::Color::White);

    Rectangle rightPaddle(size.rightPadPosX, size.paddleStartY, paddleShape, size, window);
    Rectangle leftPaddle(size.leftPadPosX, size.paddleStartY, paddleShape, size, window);
    Circle ball(15.0f, size.midX, size.midY, ballShape, size, window);

    while (window.isOpen())
    {
        //If "X" clicked or Esc is pressed --> exit
        while(const auto event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>() ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }

        //Calling ball.move and returning code if scored
        int moveResult = ball.move(0.5);
        if (moveResult == -1)rScore++;
        else if (moveResult == 1)lScore++;

        //Game over loop
        if (rScore >= 5 || lScore >= 5)
        {
            gameOver.setString(rScore > lScore ? "AI wins!" : "Left player wins!");
            lScoreText.setString(std::to_string(lScore));
            rScoreText.setString(std::to_string(rScore));
            gameOver.setPosition(sf::Vector2f(size.midX - 80, size.midY - 80));
            lScoreText.setPosition(sf::Vector2f(50, 50));
            rScoreText.setPosition(sf::Vector2f(size.width - 50, 50));
            window.clear(sf::Color::Black);
            window.draw(gameOver);
            window.draw(lScoreText);
            window.draw(rScoreText);
            window.display();
            break;
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            leftPaddle.move(1.0f);
        }
        ball.move(0.5);
        rightPaddle.aiMove(0.09f, ball);

        //Right paddle collision
        if (ball.xPos + ball.getRad() * 2 >= rightPaddle.xPos &&
            ball.xPos <= rightPaddle.xPos + size.paddleSizeX &&
            ball.yPos + ball.getRad() * 2 >= rightPaddle.yPos &&
            ball.yPos <= rightPaddle.yPos + size.paddleSizeY)
        {
            ball.setNX(-ball.getNX()); // Reverse X direction
            float newSpeed = ball.speedIncr();
            ball.setNX(ball.getNX() > 0 ? newSpeed : -newSpeed);
            ball.setNY(ball.getNY() > 0 ? newSpeed : -newSpeed);
        }

        //Left paddle collision
        if (ball.xPos <= leftPaddle.xPos + size.paddleSizeX &&
            ball.xPos + ball.getRad() * 2 >= leftPaddle.xPos &&
            ball.yPos + ball.getRad() * 2 >= leftPaddle.yPos &&
            ball.yPos <= leftPaddle.yPos + size.paddleSizeY)
        {
            ball.setNX(-ball.getNX()); // Reverse X direction
            float newSpeed = ball.speedIncr();
            ball.setNX(ball.getNX() > 0 ? newSpeed : -newSpeed);
            ball.setNY(ball.getNY() > 0 ? newSpeed : -newSpeed);
        }

        //Draw everything
        window.clear(sf::Color::Black);
        rightPaddle.draw(window);
        leftPaddle.draw(window);
        ball.draw(window);
        window.display();
    }

    while(const auto event = window.pollEvent())
    {
        if(event->is<sf::Event::Closed>() ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }
    }
}

