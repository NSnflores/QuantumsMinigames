#include "cocos2d.h"

#ifndef Ball_h
#define Ball_h

USING_NS_CC;

class Ball
{
public:
    Ball(Node* scene);
    Sprite* sprite;
    bool isCentered(float radius, Vec2 centerPosition);
    void removeSelf();
    
    Size visibleSize;
    Vec2 origin;
    Vec2 center;
private:
    Node* scene;
    void runAnimation();
};

#endif /* Ball_hpp */
