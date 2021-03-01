#include <iostream>
#include "SFML/Graphics.hpp"
#include "Includes/Player.h"
#include "Includes/GameObject.h"
#include "Includes/StaticObject.h"
#include <vector>

static const float WINDOW_HEIGHT = 768.0f;
static const float WINDOW_WIDTH = 1280.0f;

int main(void)
{
    sf::RenderWindow window(sf::VideoMode((int)WINDOW_WIDTH, (int)WINDOW_HEIGHT, 32), "Bulanci", sf::Style::Close);

    sf::Texture tilesetTexture;
    if(!tilesetTexture.loadFromFile("Resources/256x128.jpg")) {
        throw std::runtime_error("File not found - texture could not be loaded");
    }

    float deltaTime = 0.0f;
    sf::Clock deltaClock;

    Player player1({126.0f, 126.0f}, {
        sf::Keyboard::Key::W,
        sf::Keyboard::Key::S,
        sf::Keyboard::Key::A,
        sf::Keyboard::Key::D,
        sf::Keyboard::Key::Space
    }, &tilesetTexture);

    StaticObject object({128.0f, 128.0f}, { 512.0f, 512.0f }, &tilesetTexture);

    while(window.isOpen())
    {
        /** Delta */
        deltaTime = deltaClock.restart().asSeconds();
        /** If FPS drops below 30 fps, se delta time to equivalent of 30 fps */
        if(deltaTime > 1.0f / 30)
            deltaTime = 1.0f / 30;
        /** Window events */
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        /** Update players */
        player1.Update(deltaTime);

        /** Collision */

        /** Prepare view and screen */
        window.clear(sf::Color(0, 0, 0));

        /** Render */
        player1.Draw(window);
        object.Draw(window);

        /** Display window */
        window.display();
    }
    return EXIT_SUCCESS;
}