#include "MainMenuScene.h"
#include "CircleGameScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace ui;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

bool MainMenu::init()
{
    // 1. super init first
    if ( !Scene::init() )
        return false;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto playButton = Button::create("ui/green_button.png",
                                     "ui/green_button_pressed.png");
    playButton->setTitleText("Play");
    playButton->setTitleFontSize(15);
    playButton->setPosition(Vec2(origin.x + visibleSize.width/2,
                                 origin.y + visibleSize.height/2));
    playButton->addTouchEventListener(CC_CALLBACK_1(MainMenu::playGameCallback, this));

    this->addChild(playButton);
    
    return true;
}


void MainMenu::playGameCallback(Ref* pSender)
{
    auto scene = CircleGame::createScene();
    Director::getInstance()->pushScene(scene);
}
