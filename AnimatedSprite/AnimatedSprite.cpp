#include <iostream>
#include "./AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite (std::string imagePath) {
    _imgPath = imagePath;
    _currentFrame = 0;
    if (!_texture.loadFromFile(_imgPath)) {
        throw "Cannot continue, image load failed";
    }
    std::cout << "created!" << std::endl;
}
AnimatedSprite::~AnimatedSprite () {
    std::cout << "destroyed!" << std::endl;
}

sf::Sprite AnimatedSprite::getCurrentFrame(std::string collectionName){
    _frame_collections[collectionName][_currentFrame].setPosition(_position); // updating the position
    return _frame_collections[collectionName][_currentFrame];
}

sf::Sprite AnimatedSprite::getCurrentFrame(){
    _currentAnimation[_currentFrame].setPosition(_position); // updating the position
    return _currentAnimation[_currentFrame];
}

void AnimatedSprite::addFrame(std::string collectionName, sf::IntRect rect) {
    sf::Sprite sprite(_texture, rect);
    _frame_collections[collectionName].push_back(sprite);
}

void AnimatedSprite::setPosition(sf::Vector2f pos){
    _position = pos;
}

sf::Vector2f AnimatedSprite::getPosition() {
    return _position;
}

void AnimatedSprite::addFrameCollection(std::string collectionName) {
    _frame_collections[collectionName] = {};
}

void AnimatedSprite::addFrameCollection(std::string collectionName, std::vector<sf::Sprite> collection ) {
    _frame_collections[collectionName] = collection;
}

void AnimatedSprite::play() {
    _isPlaying = true;
}

void AnimatedSprite::setFrameTimer(sf::Time seconds) {
    _frameTime = seconds;
}

std::vector<sf::Sprite> AnimatedSprite::getCurrentAnimation() {
    return _currentAnimation;
}
void AnimatedSprite::setCurrentAnimation(std::string collectionName) {
    _currentAnimation = _frame_collections[collectionName];
}

void AnimatedSprite::update(sf::Time delta) {
    _curTime += delta;
    if (_curTime >= _frameTime) {
        // resetting the currentTime
        _curTime = sf::microseconds(_curTime.asMicroseconds() % _frameTime.asMicroseconds());
        if (_currentFrame + 1 < _currentAnimation.size()) _currentFrame++;
        else {
            _currentFrame = 0;
        }
    }
}

void AnimatedSprite::draw() {

}
