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
    
    circle = Sprite::create("sprites/circle_white.png");
    circle->setPosition(center);
    this->addChild(circle);
    
    
    ScaleTo* makeBigger = ScaleTo::create(0.25, 0.95f);
    ScaleTo* makeSmaller = ScaleTo::create(0.25, 0.85f);
    EaseSineInOut* easeBigger = EaseSineInOut::create(makeBigger);
    EaseSineInOut* easeSmaller = EaseSineInOut::create(makeSmaller);
    Sequence* sequenceAnimation = Sequence::create(easeBigger,easeSmaller, NULL);
    RepeatForever* repeatAnimation = RepeatForever::create(sequenceAnimation);
    circle->runAction(repeatAnimation);
    
    TintTo* toGreen = TintTo::create(0.35, 150, 255, 150);
    TintTo* toBlue = TintTo::create(0.35, 150, 150, 255);
    TintTo* toRed = TintTo::create(0.35, 255, 150, 150);
    Sequence* colorAnimation = Sequence::create(toGreen,toRed,toBlue, NULL);
    RepeatForever* repeatColor = RepeatForever::create(colorAnimation);
    circle->runAction(repeatColor);
    
    schedule(schedule_selector(CircleGame::createBall), 0.5f);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(CircleGame::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

void CircleGame::createBall(float dt)
{
    balls.push_back(new Ball(this));
}

bool CircleGame::onTouchBegan(Touch* touch, Event* event)
{
    for(int i = 0; i< balls.size(); i++){
        if(balls.at(i)->isCentered(circle->getContentSize().width*0.75f))
        {
            balls.at(i)->sprite->runAction(RemoveSelf::create(true));
            balls.erase(balls.begin()+i);
            i--;
        }
    }
    return true;
}
