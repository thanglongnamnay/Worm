//
// Created by long on 20/05/2020.
//

#include "UnitView.h"

bool WormView::init() {
    if (!Node::init()) return false;
    view = Sprite::createWithSpriteFrameName("tile000.png");
    addChild(view);
    indicator = DrawNode::create();
    addChild(indicator);
    auto sp1 = Sprite::create("Bars/hp.png");
    sp1->setContentSize({118, 20});
    hpBar = ProgressTimer::create(sp1);
    hpBar->setType(ProgressTimer::Type::BAR);
    hpBar->setPositionY(22);
    hpBar->setMidpoint(Vec2(0, 0));
    hpBar->setScale(0.3f);
    hpBar->setPercentage(100);
    addChild(hpBar);
    auto sp = Sprite::create("Bars/mp.png");
    sp->setContentSize({118, 20});
    mpBar = ProgressTimer::create(sp);
    mpBar->setType(ProgressTimer::Type::BAR);
    mpBar->setMidpoint(Vec2(0, 0));
    addChild(mpBar);
    mpBar->setPositionY(16);
    mpBar->setScale(0.3f);
    mpBar->setPercentage(100);
    lbName = Label::create();
    lbName->setString("fdsafdsa");
//    lbName = Label::createWithSystemFont("fdsa", "Arial", 24, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
    lbName->setBMFontSize(24);
    lbName->setSystemFontSize(24);
    lbName->setPosition(0, 30);
    addChild(lbName);

    Vector<SpriteFrame*> animFrames;
    const int numberSprite = 15;
    animFrames.reserve(numberSprite);
    for (auto i = 0; i < numberSprite; ++i) {
        if (i < 10) {
            animFrames.pushBack(
                    SpriteFrameCache::getInstance()->getSpriteFrameByName("tile00" + std::to_string(i) + ".png"));
        }
        else {
            animFrames.pushBack(
                    SpriteFrameCache::getInstance()->getSpriteFrameByName("tile0" + std::to_string(i) + ".png"));
        }
    }

    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    Animate* animate = Animate::create(animation);

    view->runAction(RepeatForever::create(animate));

    return true;
}

void WormView::changeHp(int hp) {
    hpBar->setPercentage(hp);
}

void WormView::changeMp(int mp) {
    mpBar->setPercentage(mp);
}

void WormView::indicate(Angle angle) const {
    indicator->clear();
    indicator->drawLine(Vec2::ZERO,
                        (new Vec2(25, 0))->rotateByAngle(Vec2::ZERO, static_cast<double>(angle) * 3.14 / 180),
                        Color4F(1, 1, 1, 1));
}

std::shared_ptr<WormView> WormView::create() {
    auto p = std::make_shared<WormView>();
    if (p && p->init()) {
        return p;
    }
    return nullptr;
}

void WormView::setPlayerName(const std::string &name) {
    lbName->setString(name);
}
