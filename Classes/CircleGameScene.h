#ifndef __CircleGame_SCENE_H__
#define __CircleGame_SCENE_H__

#include "cocos2d.h"
#include "Ball.h"
#include <vector>

using namespace std;

class CircleGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(CircleGame);
    vector<Ball*> balls;
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    
    Sprite* circle;
    
    
    void createBall(float dt);
};

#endif // __MainMenu_SCENE_H__
