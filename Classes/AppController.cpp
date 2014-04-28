//
//  AppController.cpp
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#include "AppController.h"

AppController::~AppController()
{
    
}

bool AppController::init()
{
    if (!Node::init())
    {
        return false;
    }

    AppController::addTouchEvents();
    
    return true;
}

void AppController::addTouchEvents()
{
    auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan = CC_CALLBACK_2(AppController::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(AppController::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(AppController::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(AppController::onTouchCancelled, this);
	
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool AppController::onTouchBegan(Touch* touch, Event* event)
{
    auto touchPoint = this->convertToWorldSpace(this->convertTouchToNodeSpace(touch));
    auto moneyGroup = this->getParent()->getChildByTag(_data->MONEY_GROUP_TAG);
    auto moneyVector = moneyGroup->getChildren();
    
    for (int i = 0; i < moneyVector.size(); i++) {
        auto money = (Sprite *)moneyVector.at(i);

        if (_model->isTapped(touchPoint, money)) {
            _tappedMoney = money;
        }
    }
    
    return true;
}

void AppController::onTouchMoved(Touch* touch, Event* event)
{
    if (!_tappedMoney) { return; }
    
    auto diff = this->convertToWorldSpace(this->convertTouchToNodeSpace(touch)) - touch->getPreviousLocation();
    
    auto newPoint = _tappedMoney->getPosition() + diff;
    
    MoneyScene::moveMoney(newPoint, _tappedMoney);
    
    auto exit = this->getParent()->getChildByTag(_data->MONEY_EXIT_TAG);
    
    if (_model->atExit(_tappedMoney, exit)) {
        MoneyScene::scaleExit(exit, 1.5f);
    } else {
        MoneyScene::scaleExit(exit, 1.0f);
    }
}

void AppController::onTouchEnded(Touch* touch, Event* event)
{
    _tappedMoney = nullptr;
}

void AppController::onTouchCancelled(Touch* touch, Event* event)
{
    _tappedMoney = nullptr;
}