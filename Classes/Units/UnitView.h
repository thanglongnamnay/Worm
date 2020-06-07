//
// Created by long on 20/05/2020.
//

#ifndef WORM_UNITVIEW_H
#define WORM_UNITVIEW_H

#include <cocos2d.h>

#include <utility>

USING_NS_CC;

class UnitView : public Node {
};

class WormView : public UnitView {
    DrawNode *indicator;
    Sprite *view;
public:
    bool init(const std::string& name) {
        if (!Node::init()) return false;
        view = Sprite::createWithSpriteFrameName(name);
        addChild(view);
        indicator = DrawNode::create();
        addChild(indicator);

        Vector<SpriteFrame *> animFrames;
        const int numberSprite = 15;
        animFrames.reserve(numberSprite);
        for (auto i = 0; i < numberSprite; ++i) {
            if (i < 10) {
                animFrames.pushBack(
                        SpriteFrameCache::getInstance()->getSpriteFrameByName("tile00" + std::to_string(i) + ".png"));
            } else {
                animFrames.pushBack(
                        SpriteFrameCache::getInstance()->getSpriteFrameByName("tile0" + std::to_string(i) + ".png"));
            }
        }

        Animation *animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
        Animate *animate = Animate::create(animation);

        view->runAction(RepeatForever::create(animate));

        return true;
    }
    void indicate(double angle) {
        indicator->clear();
        indicator->drawLine(Vec2::ZERO, (new Vec2(25, 0))->rotateByAngle(Vec2::ZERO, angle), Color4F(1, 1, 1, 1));
    }
    static UnitView* create(const std::string& name) {
        auto p = new (std::nothrow) WormView();
        if (p && p->init(name)) {
            p->autorelease();
            return p;
        }
        return nullptr;
    }
};

#endif //WORM_UNITVIEW_H
