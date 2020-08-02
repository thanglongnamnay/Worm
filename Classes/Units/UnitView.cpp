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
    hpBar = makeBar("Bars/hp.png");
	hpBar->setPositionY(22);
    addChild(hpBar);
    mpBar = makeBar("Bars/mp.png");
	mpBar->setPositionY(16);
    addChild(mpBar);
	lbName = Label::createWithSystemFont("fdsafdsa", "Arial", 12);
    lbName->setPositionY(32);
	addChild(lbName, 100);

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
ProgressTimer* WormView::makeBar(const std::string& sprPath) {
	auto sp1 = Sprite::create(sprPath);
	sp1->setContentSize({118, 20});
	auto bar = ProgressTimer::create(sp1);
	bar->setType(ProgressTimer::Type::BAR);
	bar->setMidpoint({0, 0});
	bar->setBarChangeRate({1, 0});
	bar->setScale(0.3f);
	bar->setPercentage(100);
	return bar;
}
void WormView::flip(bool v) {
	view->setFlippedX(v);
}
