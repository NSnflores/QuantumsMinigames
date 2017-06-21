#include "Ball.h"

Ball::Ball(Node* scene)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    center = Vec2(origin.x + visibleSize.width/2,
                       origin.y + visibleSize.height/2);
    this->scene = scene;
    
    sprite = Sprite::create("sprites/circle_white.png");
    sprite->setScale(0.5);
    sprite->setPosition(Vec2(visibleSize.width + sprite->getContentSize().width,
                             center.y));
    scene->addChild(sprite);
    
    runAnimation();
}

bool Ball::isCentered(float radius, Vec2 centerPosition)
{
    float h2 = (sprite->getPosition().x - centerPosition.x) * (sprite->getPosition().x - centerPosition.x) +
               (sprite->getPosition().y - centerPosition.y) * (sprite->getPosition().y - centerPosition.y);
    return radius*radius > h2;
}

//Needs to implement random animations
void Ball::runAnimation()
{
    sprite->runAction(MoveTo::create(2.f, Vec2(-sprite->getContentSize().width,sprite->getPosition().y)));
}

void Ball::removeSelf()
{
    FadeOut* fadeOut = FadeOut::create(0.1);
    TintTo* tint = TintTo::create(0.05, 0, 255, 255);
    Spawn* spawn = Spawn::create(fadeOut, tint, NULL);
    Sequence* sequence = Sequence::create(spawn, RemoveSelf::create(true), NULL);
    sprite->runAction(sequence);
}
