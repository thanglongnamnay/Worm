//
// Created by long on 20/05/2020.
//

#ifndef WORM_UNITVIEW_H
#define WORM_UNITVIEW_H

#include <cocos2d.h>

#include <utility>
#include <Types/Angle.h>

USING_NS_CC;

class UnitView : public Node {
};

class DebrisView : public UnitView {
    DrawNode *view{};
public:
    bool init() override {
        Node::init();
        view = DrawNode::create();
        view->drawDot(Vec2::ZERO, 4, Color4F::RED);
        addChild(view);
        return true;
    }
    static DebrisView* create() {
        auto p = new (std::nothrow) DebrisView();
        if (p && p->init()) {
            p->autorelease();
            return p;
        }
        return nullptr;
    }
};

class MissileView : public UnitView {
    DrawNode *view{};
public:
    bool init() override {
        Node::init();
        view = DrawNode::create();
        view->drawDot(Vec2::ZERO, 5, Color4F::BLUE);
        addChild(view);
        return true;
    }
    static MissileView* create() {
        auto p = new (std::nothrow) MissileView();
        if (p && p->init()) {
            p->autorelease();
            return p;
        }
        return nullptr;
    }
};

class WormView : public UnitView {
    DrawNode *indicator{};
    Sprite *view{};
public:
    bool init() override {
        if (!Node::init()) return false;
        view = Sprite::createWithSpriteFrameName("tile000.png");
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
    void indicate(Angle angle) {
        indicator->clear();
        indicator->drawLine(Vec2::ZERO, (new Vec2(25, 0))->rotateByAngle(Vec2::ZERO, static_cast<double>(angle) * 3.14 / 180 ), Color4F(1, 1, 1, 1));
    }
    static WormView* create() {
        auto p = new (std::nothrow) WormView();
        if (p && p->init()) {
            p->autorelease();
            return p;
        }
        return nullptr;
    }
};

#endif //WORM_UNITVIEW_H
