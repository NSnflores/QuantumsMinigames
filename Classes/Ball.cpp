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

bool Ball::isCentered(float radius)
{
    float x2 = (sprite->getPosition().x - center.x) * (sprite->getPosition().x - center.x) +
               (sprite->getPosition().y - center.y) * (sprite->getPosition().y - center.y);
    return radius*radius > x2;
}

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
