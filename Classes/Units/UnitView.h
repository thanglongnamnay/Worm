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
    Label *lbName{};
    static ProgressTimer* makeBar(const std::string& sprPath);
public:
	DrawNode* indicator{};
	bool init() override;
	void changeHp(int hp);
	void changeMp(int mp);
	void setPlayerName(const std::string& name);
	void indicate(Angle angle) const;
	void flip(bool v);
	static std::shared_ptr<WormView> create();
};

#endif //WORM_UNITVIEW_H
