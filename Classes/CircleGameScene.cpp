#include "CircleGameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* CircleGame::createScene()
{
    return CircleGame::create();
}

bool CircleGame::init()
{
    // 1. super init first
    if ( !Scene::init() )
        return false;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width/2,
                       origin.y + visibleSize.height/2);
    
    Sprite* circle = Sprite::create("sprites/circle_white.png");
    circle->setPosition(center);
    this->addChild(circle);
    
    ScaleTo* makeBigger = ScaleTo::create(0.25, 1.05);
    ScaleTo* makeSmaller = ScaleTo::create(0.25, 0.95);
    EaseSineInOut* easeBigger = EaseSineInOut::create(makeBigger);
    EaseSineInOut* easeSmaller = EaseSineInOut::create(makeSmaller);
    Sequence* sequenceAnimation = Sequence::create(easeBigger,easeSmaller, NULL);
    RepeatForever* repeatAnimation = RepeatForever::create(sequenceAnimation);
    
    circle->runAction(repeatAnimation);

    return true;
}
