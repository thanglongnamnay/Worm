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
public:
	~UnitView() override {
		if (this->getParent()) {
			this->removeFromParent();
		}
	}
};

class DebrisView : public UnitView {
	DrawNode* view{};
public:
	bool init() override {
		Node::init();
		view = DrawNode::create();
		view->drawDot(Vec2::ZERO, 4, Color4F::RED);
		addChild(view);
		return true;
	}
	static std::shared_ptr<DebrisView> create() {
		auto p = std::make_shared<DebrisView>();
		if (p && p->init()) {
			return p;
		}
		return nullptr;
	}
};

class MissileView : public UnitView {
	DrawNode* view{};
public:
	bool init() override {
		Node::init();
		view = DrawNode::create();
		view->drawDot(Vec2::ZERO, 5, Color4F::BLUE);
		addChild(view);
		return true;
	}
	static std::shared_ptr<MissileView> create() {
		auto p = std::make_shared<MissileView>();
		if (p && p->init()) {
			return p;
		}
		return nullptr;
	}
};

class WormView : public UnitView {
	Sprite* view{};
	ProgressTimer* hpBar{};
	ProgressTimer* mpBar{};
public:
	DrawNode* indicator{};
	bool init() override {
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
	void changeHp(int hp) {
		hpBar->setPercentage(hp);
	}
	void changeMp(int mp) {
		mpBar->setPercentage(mp);
	}
	void indicate(Angle angle) const {
		indicator->clear();
		indicator->drawLine(Vec2::ZERO,
				(new Vec2(25, 0))->rotateByAngle(Vec2::ZERO, static_cast<double>(angle) * 3.14 / 180),
				Color4F(1, 1, 1, 1));
	}
	static std::shared_ptr<WormView> create() {
		auto p = std::make_shared<WormView>();
		if (p && p->init()) {
			return p;
		}
		return nullptr;
	}
};

#endif //WORM_UNITVIEW_H
