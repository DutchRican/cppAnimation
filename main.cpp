#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AnimatedSprite/AnimatedSprite.hpp"

using namespace std;
using namespace sf;

int main()
{
    // Init
    RenderWindow window(VideoMode(800, 600), "Dragon moves");
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

    dragon.addFrame("walkDown", IntRect(0, 0, 106, 106));
    dragon.addFrame("walkDown", IntRect(107, 0, 106, 106));
    dragon.addFrame("walkDown", IntRect(214, 0, 106, 106));
    dragon.addFrame("walkUp", IntRect(0, 318, 106, 106));
    dragon.addFrame("walkUp", IntRect(107, 318, 106, 106));
    dragon.addFrame("walkUp", IntRect(214, 318, 106, 106));
    dragon.addFrame("walkRight", IntRect(0, 212, 106, 106));
    dragon.addFrame("walkRight", IntRect(107, 212, 106, 106));
    dragon.addFrame("walkRight", IntRect(214, 212, 106, 106));
    dragon.addFrame("walkLeft", IntRect(0, 106, 106, 106));
    dragon.addFrame("walkLeft", IntRect(107, 106, 106, 106));
    dragon.addFrame("walkLeft", IntRect(214, 106, 106, 106));
    dragon.setPosition(sf::Vector2f(100, 100));
    dragon.setFrameTimer(sf::seconds(0.2));

    enum directions
    {
        RIGHT_DIR,
        LEFT_DIR,
        DOWN_DIR,
        UP_DIR
    };

    map<directions, string> dir = {{RIGHT_DIR, "walkRight"}, {LEFT_DIR, "walkLeft"}, {UP_DIR, "walkUp"}, {DOWN_DIR, "walkDown"}};

    auto curDir = RIGHT_DIR;
    bool isMoving = false;
    // Game loop
    while (isRunning)
    {
        Vector2f dragonPos = dragon.getPosition();
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                isRunning = false;

            if (event.type == Event::KeyPressed)
            {
                int keyCode = event.key.code;
                switch (keyCode)
                {
                case Keyboard::S:
                    isMoving = true;
                    curDir = DOWN_DIR;
                    break;
                case Keyboard::W:
                    isMoving = true;
                    curDir = UP_DIR;
                    break;
                case Keyboard::A:
                    isMoving = true;
                    curDir = LEFT_DIR;
                    break;
                case Keyboard::D:
                    isMoving = true;
                    curDir = RIGHT_DIR;
                    break;
                default:
                    curDir = RIGHT_DIR;
                }
            }
            if (event.type == Event::KeyReleased)
            {
                int keyCode = event.key.code;
                switch (keyCode)
                {
                case Keyboard::S:
                case Keyboard::W:
                case Keyboard::A:
                case Keyboard::D:
                    isMoving = false;
                }
            }
            // if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            // {
            //     leftClick = true;
            // }
            // if (event.type == Event::MouseMoved)
            // {
            //     pos = Mouse::getPosition();
            // }
        }
        sf::Time frameTime = frameClock.restart();
        // Logic
        switch (curDir)
        {
        case UP_DIR:
            if (isMoving)
                dragonPos.y -= 5;
            break;
        case DOWN_DIR:
            if (isMoving)
                dragonPos.y += 5;
            break;
        case RIGHT_DIR:
            if (isMoving)
                dragonPos.x += 5;
            break;
        case LEFT_DIR:
            if (isMoving)
                dragonPos.x -= 5;
            break;
        }
        dragon.setCurrentAnimation(dir[curDir]);
        dragon.setPosition(dragonPos);
        dragon.update(frameTime, isMoving);

        // Render
        window.clear();
        window.draw(dragon.getCurrentFrame());
        window.display();
    }
    // Cleanup
    window.close();
    return 0;
}