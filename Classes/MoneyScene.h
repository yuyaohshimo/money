//
//  MoneyScene.h
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#ifndef __Money__MoneyScene__
#define __Money__MoneyScene__

#include <array>
#include "cocos2d.h"
#include "AppController.h"
#include "AppModel.h"
#include "AppData.h"

USING_NS_CC;
using namespace std;

class MoneyScene : public Layer
{
public:
    static Scene* createScene();
    MoneyScene();
    
    virtual bool init();
    CREATE_FUNC(MoneyScene);
    
    void drawExit();
    void drawMoney();
    static void moveMoney(Point newPoint, Sprite* money);
    static void scaleExit(Node* exit, float scale);
private:
    AppData* _data = AppData::getInstance();
    AppModel* _model = AppModel::create();
};

#endif /* defined(__Money__MoneyScene__) */
