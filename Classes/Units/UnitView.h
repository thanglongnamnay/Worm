//
// Created by long on 20/05/2020.
//

#ifndef WORM_UNITVIEW_H
#define WORM_UNITVIEW_H

#include <cocos2d.h>

USING_NS_CC;

class UnitView : public Sprite {

public:
    static UnitView* create() {
      auto pRet = new UnitView();
      pRet && pRet->init() && pRet->autorelease();
      return pRet;
    }
};

#endif //WORM_UNITVIEW_H
