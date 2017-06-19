//
//  Ball.cpp
//  QuantumMinigames
//
//  Created by Noé Flores on 6/19/17.
//
//

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

//Not implemented
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
