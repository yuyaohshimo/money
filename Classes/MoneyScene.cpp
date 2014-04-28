//
//  MoneyScene.cpp
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#include "MoneyScene.h"

MoneyScene::MoneyScene()
{
}

Scene* MoneyScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MoneyScene::create();
    scene->addChild(layer);
    return scene;
}

bool MoneyScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    MoneyScene::drawExit();
    MoneyScene::drawMoney();
    
    auto controller = AppController::create();
    this->addChild(controller);
    
    return true;
}

void MoneyScene::drawExit()
{
    auto exit = Sprite::create(_data->MONEY_EXIT);
    exit->setPosition(_model->getCenterPosition());
    exit->setTag(_data->MONEY_EXIT_TAG);
    
    this->addChild(exit);
}

void MoneyScene::drawMoney()
{
    auto menuContainer = Node::create();
    menuContainer->setTag(_data->MONEY_GROUP_TAG);
    
    auto moneyArray = _model->getMoneyArray();
    
    for (int i = 0; i < moneyArray.size(); i++) {
        auto sprite = Sprite::create(moneyArray[i]);
        sprite->setPosition(_model->getRandomPosition());
        sprite->setScale(0.5f);
        sprite->setRotation(_model->getRandomRotation());
        
        menuContainer->addChild(sprite);
    }
    
    this->addChild(menuContainer);
    
}

void MoneyScene::moveMoney(Point newPoint, Sprite* money)
{
    money->setPosition(newPoint);
}

void MoneyScene::scaleExit(Node* exit, float scale)
{
    exit->setScale(scale);
}