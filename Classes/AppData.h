//
//  AppData.h
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#ifndef __Money__AppData__
#define __Money__AppData__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class AppData
{
public:
    static AppData* getInstance();
    
    // お金の画像
    const string MONEY_100 = "money_100.png";
    const string MONEY_500 = "money_500.png";
    const string MONEY_1000 = "money_1000.png";
    const string MONEY_5000 = "money_5000.png";
    const string MONEY_10000 = "money_10000.png";
    
    // お金の出口の画像
    const string MONEY_EXIT = "money_exit.png";
    
    // お金グループのタグ
    const short MONEY_GROUP_TAG = 0;
    
    // 出口のタグ
    const short MONEY_EXIT_TAG = 1;
    
    const string foo = "";
private:
    // 生成やコピーを禁止する
    AppData();
    AppData(const AppData& rhs);
    AppData& operator=(const AppData& rhs);

    static AppData* _data;
};

#endif /* defined(__Money__AppData__) */
