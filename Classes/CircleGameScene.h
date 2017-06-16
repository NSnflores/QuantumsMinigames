#ifndef __CircleGame_SCENE_H__
#define __CircleGame_SCENE_H__

#include "cocos2d.h"

class CircleGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(CircleGame);
};

#endif // __MainMenu_SCENE_H__
