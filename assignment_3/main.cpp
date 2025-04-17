#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Size.h"
#include <string>

Size size(800, 600);

int rScore = 0;
int lScore = 0;
constexpr int WIN_SCORE = 5;

int main()
{
    //Window setup
    Size size(800, 600);
    sf::RenderWindow window(sf::VideoMode({size.width, size.height}), "Pong");
    window.setVerticalSyncEnabled(true);

    // Shapes
    sf::RectangleShape paddleShape;
    paddleShape.setSize({static_cast<float>(size.paddleSizeX), static_cast<float>(size.paddleSizeY)});
    sf::CircleShape ballShape(15.f);

    // Font and texts
    sf::Font font;
    if (!font.openFromFile("arial.ttf"))
    {
        std::cerr << "Could not load font" << std::endl;
        return EXIT_FAILURE;
    }

    //Initialising text
    sf::Text gameOverText(font, "", 48);
    sf::Text lScoreText(font, "0", 24);
    sf::Text rScoreText(font, "0", 24);
    gameOverText.setFillColor(sf::Color::White);
    lScoreText.setFillColor(sf::Color::White);
    rScoreText.setFillColor(sf::Color::White);
    gameOverText.setPosition(sf::Vector2f(size.midX - 80, size.midY - 80));
    lScoreText.setPosition(sf::Vector2f(50, 50));
    rScoreText.setPosition(sf::Vector2f(size.width - 50, 50));



    Rectangle rightPaddle(size.rightPadPosX, size.paddleStartY, paddleShape, size, window);
    Rectangle leftPaddle(size.leftPadPosX, size.paddleStartY, paddleShape, size, window);
    Circle ball(15.0f, size.midX, size.midY, ballShape, size, window);

    //Hit sound config
    sf::SoundBuffer buffer("oof.mp3");
    sf::Sound oof(buffer);
    oof.setVolume(75);

    //Main game loop
    while (window.isOpen())
    {
        //If "X" clicked or Esc is pressed --> exit
        while (auto optEvt = window.pollEvent()) {
            auto& evt = *optEvt;
            if (evt.is<sf::Event::Closed>() ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }


        //Player input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            leftPaddle.move(1.0f);
        }
        rightPaddle.aiMove(0.9f, ball);
        bool hit = false;

        //Right paddle collision
        if (ball.xPos + ball.getRad() * 2 >= rightPaddle.xPos &&
            ball.xPos <= rightPaddle.xPos + size.paddleSizeX &&
            ball.yPos + ball.getRad() * 2 >= rightPaddle.yPos &&
            ball.yPos <= rightPaddle.yPos + size.paddleSizeY)
        {
            // Reverse direction
            ball.setNX(-ball.getNX());
            float newSpeed = ball.speedIncr();
            ball.setNX(ball.getNX() > 0 ? newSpeed : -newSpeed);
            ball.setNY(ball.getNY() > 0 ? newSpeed : -newSpeed);
            hit = true;
        }

        //Left paddle collision
        if (ball.xPos <= leftPaddle.xPos + size.paddleSizeX &&
            ball.xPos + ball.getRad() * 2 >= leftPaddle.xPos &&
            ball.yPos + ball.getRad() * 2 >= leftPaddle.yPos &&
            ball.yPos <= leftPaddle.yPos + size.paddleSizeY)
        {
            ball.setNX(-ball.getNX());
            float newSpeed = ball.speedIncr();
            ball.setNX(ball.getNX() > 0 ? newSpeed : -newSpeed);
            ball.setNY(ball.getNY() > 0 ? newSpeed : -newSpeed);
            hit = true;
        }

        while (hit)
        {
            oof.play();
            hit = false;
        }

        // Update game state
        int result = ball.move(0.5f);
        if (result == -1) rScore++;
        else if (result == 1) lScore++;

        //Draw everything
        lScoreText.setString(std::to_string(lScore));
        rScoreText.setString(std::to_string(rScore));
        window.clear(sf::Color::Black);
        window.draw(lScoreText);
        window.draw(rScoreText);
        rightPaddle.draw(window);
        leftPaddle.draw(window);
        ball.draw(window);
        window.display();

        if (rScore >= WIN_SCORE || lScore >= WIN_SCORE)break;
    }
    //Game over loop
    gameOverText.setString(rScore > lScore ? "AI wins!" : "Left player wins!");
    gameOverText.setPosition(sf::Vector2f(size.midX - 150, size.midY - 80));
    //Initialising win sound
    sf::SoundBuffer winBuff("win.mp3");
    sf::Sound win(winBuff);
    win.setVolume(75);
    win.play();


    while (window.isOpen())
    {
        while (auto optEvt2 = window.pollEvent())
        {
            auto&evt2 = *optEvt2;
            if (evt2.is<sf::Event::Closed>() ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(gameOverText);
        window.draw(lScoreText);
        window.draw(rScoreText);
        window.display();
    }
    return 0;
}




