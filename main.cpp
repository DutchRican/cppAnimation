#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AnimatedSprite/AnimatedSprite.hpp"

using namespace std;
using namespace sf;

int main()
{
    // Init
    RenderWindow window(VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Clock frameClock;

    int numClicks = 0;
    bool leftClick = false;
    Vector2i pos;
    // Events
    Event event;
    bool isRunning = true;

    // Load Image

    AnimatedSprite dragon("assets/images/dragon.png");
    dragon.addFrameCollection("walkDown");
    dragon.addFrameCollection("walkRight");

    dragon.addFrame("walkDown", IntRect(0,0,106, 106));
    dragon.addFrame("walkDown", IntRect(107,0,106, 106));
    dragon.addFrame("walkDown", IntRect(214,0,106, 106));
    dragon.addFrame("walkRight", IntRect(0,212,106, 106));
    dragon.addFrame("walkRight", IntRect(107,212,106, 106));
    dragon.addFrame("walkRight", IntRect(214,212,106, 106));
    dragon.setPosition(sf::Vector2f(100, 100));
    dragon.setCurrentAnimation("walkDown");
    dragon.setFrameTimer(sf::seconds(0.2));

    // Game loop
    while (isRunning)
    {

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                isRunning = false;

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                leftClick = true;
            }
            if (event.type == Event::MouseMoved)
            {
                pos = Mouse::getPosition();
            }
        }
        sf::Time frameTime = frameClock.restart();
        // Logic
        dragon.update(frameTime);

        // Render
        window.clear();
        window.draw(dragon.getCurrentFrame());
        window.display();
    }
    // Cleanup
    window.close();
    return 0;
}