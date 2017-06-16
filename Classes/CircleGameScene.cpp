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
    
    return true;
}
