//
//  AppModel.h
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#ifndef __Money__AppModel__
#define __Money__AppModel__

#include <array>
#include "cocos2d.h"
#include "AppData.h"

USING_NS_CC;
using namespace std;

class AppModel : public Node
{
public:
    ~AppModel();
    virtual bool init();
    CREATE_FUNC(AppModel);
    
    Point getCenterPosition();
    Point getRandomPosition();
    float getRandomRotation();
    array<string, 5> getMoneyArray();
    bool isTapped(Point touchPoint, Sprite* sprite);
    bool atExit(Sprite* sprite, Node* exit);
};

#endif /* defined(__Money__AppModel__) */
