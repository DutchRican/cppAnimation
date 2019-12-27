#include <SFML/Graphics.hpp>
#include <map>

class AnimatedSprite {
    public:
        AnimatedSprite(std::string imagePath);
        ~AnimatedSprite();
        void addFrame(std::string collectionName, sf::IntRect rect);
        sf::Sprite getCurrentFrame(std::string collectionName);
        sf::Sprite getCurrentFrame();
        sf::Vector2f getPosition();
        std::vector<sf::Sprite> getCurrentAnimation();
        void setCurrentAnimation(std::string collectionName);
        void setFrameTimer(sf::Time seconds);
        void setPosition(sf::Vector2f pos);
        void addFrameCollection(std::string collectionName);
        void addFrameCollection(std::string collectionName, std::vector<sf::Sprite> collection);
        void play();
        void update(sf::Time delta);
        void draw();
    private:
        std::string _imgPath;
        sf::Texture _texture;
        std::map<std::string, std::vector<sf::Sprite> > _frame_collections;
        std::vector<sf::Sprite> _currentAnimation;
        int _currentFrame;
        sf::Vector2f _position;
        sf::Time _frameTime;
        sf::Time _curTime;
        bool _isPlaying;
};
