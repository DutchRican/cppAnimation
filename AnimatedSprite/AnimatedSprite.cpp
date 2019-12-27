#include <iostream>
#include "./AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite (std::string imgPath) {
    this->imgPath = imgPath;
    currentFrame = 0;
    if (!texture.loadFromFile(imgPath)) {
        throw "Cannot continue, image load failed";
    }
    std::cout << "created!" << std::endl;
}
AnimatedSprite::~AnimatedSprite () {
    std::cout << "destroyed!" << std::endl;
}

sf::Sprite AnimatedSprite::getCurrentFrame(std::string collectionName){
    sf::Sprite frame = frame_collections[collectionName][currentFrame];
    frame.setPosition(position); // updating the position
    return frame;
}

sf::Sprite AnimatedSprite::getCurrentFrame(){
    sf::Sprite frame = currentAnimation[currentFrame];
    frame.setPosition(position); // updating the position
    return frame;
}

void AnimatedSprite::addFrame(std::string collectionName, sf::IntRect rect) {
    sf::Sprite sprite(texture, rect);
    frame_collections[collectionName].push_back(sprite);
}

void AnimatedSprite::setPosition(sf::Vector2f position){
    this->position = position;
}

sf::Vector2f AnimatedSprite::getPosition() {
    return position;
}

void AnimatedSprite::addFrameCollection(std::string collectionName) {
    frame_collections[collectionName] = {};
}

void AnimatedSprite::addFrameCollection(std::string collectionName, std::vector<sf::Sprite> collection ) {
    frame_collections[collectionName] = collection;
}

void AnimatedSprite::play() {
    isPlaying = true;
}

void AnimatedSprite::setFrameTimer(sf::Time seconds) {
    frameTime = seconds;
}

std::vector<sf::Sprite> AnimatedSprite::getCurrentAnimation() {
    return currentAnimation;
}
void AnimatedSprite::setCurrentAnimation(std::string collectionName) {
    currentAnimation = frame_collections[collectionName];
}

void AnimatedSprite::update(sf::Time delta) {
    curTime += delta;
    if (curTime >= frameTime) {
        // resetting the currentTime
        curTime = sf::microseconds(curTime.asMicroseconds() % frameTime.asMicroseconds());
        if (currentFrame + 1 < currentAnimation.size()) currentFrame++;
        else {
            currentFrame = 0;
        }
    }
}

void AnimatedSprite::draw() {

}
