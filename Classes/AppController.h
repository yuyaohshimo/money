//
//  AppController.h
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#ifndef __Money__AppController__
#define __Money__AppController__

#include "cocos2d.h"
#include "AppModel.h"
#include "AppData.h"
#include "MoneyScene.h"

USING_NS_CC;
using namespace std;

class AppController : public Node
{
public:
    ~AppController();
    virtual bool init();
    CREATE_FUNC(AppController);
    
    void addTouchEvents();
    
    // touch events
	bool onTouchBegan(Touch *touch, Event *pEvent);
	void onTouchMoved(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *pTouch, Event *pEvent);
	void onTouchCancelled(Touch *pTouch, Event *pEvent);
private:
    AppData* _data = AppData::getInstance();
    AppModel* _model = AppModel::create();
    Sprite* _tappedMoney;
};

#endif /* defined(__Money__AppController__) */
