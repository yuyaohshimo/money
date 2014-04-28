//
//  AppModel.cpp
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#include "AppModel.h"

AppModel::~AppModel()
{
    
}

bool AppModel::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

Point AppModel::getCenterPosition()
{
    auto winSize = Director::getInstance()->getWinSize();
    auto centerPosition = Point(winSize.width / 2, winSize.height / 2);

    return centerPosition;
}

Point AppModel::getRandomPosition()
{
    auto winSize = Director::getInstance()->getWinSize();
    
    int randomX = arc4random() % (int)winSize.width;
    int randomY = arc4random() % (int)winSize.height;
    
    auto randomPosition = Point(randomX, randomY);
    
    return randomPosition;
}

float AppModel::getRandomRotation()
{
    return arc4random() % 360;
}

array<string, 5> AppModel::getMoneyArray()
{
    auto data = AppData::getInstance();
    
    array<string, 5> moneyArray = {
        data->MONEY_100,
        data->MONEY_500,
        data->MONEY_1000,
        data->MONEY_5000,
        data->MONEY_10000
    };
    
    return moneyArray;
}

bool AppModel::isTapped(Point touchPoint, Sprite* sprite)
{
    auto rect = sprite->getBoundingBox();
    
    bool tapped = rect.containsPoint(touchPoint);
    if (tapped) {
        return true;
    }
    
    return false;
}

bool AppModel::atExit(Sprite* sprite, Node* exit)
{
    
    auto exitRect = exit->getBoundingBox();
    
    log("%f", exitRect.size.width);
    log("%f", exitRect.size.height);
    
    log("%f", exitRect.origin.x);
    
    auto spriteRect = sprite->getBoundingBox();
    
    if (exitRect.intersectsRect(spriteRect)) {
        return true;
    }
    
    return false;
}