#include <SFML/Graphics.hpp>
#include <map>

class AnimatedSprite {
    public:
        AnimatedSprite(std::string imgPath);
        ~AnimatedSprite();
        void addFrame(std::string collectionName, sf::IntRect rect);
        sf::Sprite getCurrentFrame(std::string collectionName);
        sf::Sprite getCurrentFrame();
        sf::Vector2f getPosition();
        std::vector<sf::Sprite> getCurrentAnimation();
        void setCurrentAnimation(std::string collectionName);
        void setFrameTimer(sf::Time seconds);
        void setPosition(sf::Vector2f position);
        void addFrameCollection(std::string collectionName);
        void addFrameCollection(std::string collectionName, std::vector<sf::Sprite> collection);
        void play();
        void update(sf::Time delta);
        void draw();
    private:
        std::string imgPath;
        sf::Texture texture;
        std::map<std::string, std::vector<sf::Sprite> > frame_collections;
        std::vector<sf::Sprite> currentAnimation;
        int currentFrame;
        sf::Vector2f position;
        sf::Time frameTime;
        sf::Time curTime;
        bool isPlaying;
};
