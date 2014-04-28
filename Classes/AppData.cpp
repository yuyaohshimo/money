//
//  AppData.cpp
//  Money
//
//  Created by 大下 優弥 on 2014/04/28.
//
//

#include "AppData.h"

AppData* AppData::_data = NULL;

AppData::AppData()
{
    
}

AppData* AppData::getInstance()
{
    if (NULL == _data)
    {
        _data = new AppData();
    }
    return _data;
}
