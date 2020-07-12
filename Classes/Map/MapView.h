//
// Created by long on 20/05/2020.
//

#ifndef WORM_MAPVIEW_H
#define WORM_MAPVIEW_H

#include <cocos2d.h>
#include <cocos/editor-support/cocostudio/ActionTimeline/CSLoader.h>
#include <cocos/ui/UISlider.h>
#include <Units/UnitPhysic.h>

USING_NS_CC;

class MapView : public Node {
	Node* hud{};
	ui::Slider* powerBar;
	const std::vector<std::vector<u_char>>& map;
	const Size screen;
	std::shared_ptr<UnitPhysic> following = nullptr;
public:
	DrawNode* mainMap{};
	explicit MapView(std::vector<std::vector<u_char>>& map)
			:Node(), map(map), screen(Director::getInstance()->getVisibleSize()) {
	}

	bool init() override {
		Node::init();
		mainMap = DrawNode::create();
		addChild(mainMap);
		hud = CSLoader::createNode("res/GameHUD.csb");
		addChild(hud);
		powerBar = hud->getChildByName("ndPropertyies")->getChildByName<ui::Slider*>("slPower");
		scheduleUpdate();
		return true;
	}

	int getPower() const {
		if (!powerBar) return 100;
		CCLOG("powerBar: %d", powerBar->getPercent());
		return powerBar->getPercent();
	}

	void follow(const std::shared_ptr<UnitPhysic>& unit) {
		following = unit;
		CCLOG("change following");
	}

	void update(float delta) override {
		if (following && !following->isDead) {
			const auto dest = Vec2{-following->getView()->getPositionX() * mainMap->getScale() + screen.width / 2, -following->getView()->getPositionY() * mainMap->getScale() + screen.height / 2};
			const auto curr = mainMap->getPosition();
			if (dest.distanceSquared(curr) < delta * 100) mainMap->setPosition(dest);
			mainMap->setPosition(curr.lerp(dest, 0.1f));
		} else {
			mainMap->setPosition(0, 0);
		}
	}

	void addObject(Node* node) const {
		mainMap->addChild(node);
	}

	~MapView() override {
		CCLOG("DELETED MapView");
	}

	void refreshMap() {
		mainMap->clear();
		for (int y = 0; y < map.size(); ++y) {
			for (int x = 0; x < map[0].size(); ++x) {
				refreshMap(x, y);
			}
		}
	}

	void refreshMap(double x, double y) {
		mainMap->drawSolidRect(Vec2(x, y), Vec2(x + 1, y + 1), Color4F(map[y][x] ? 1 : 0, 0, 0, 1));
	}

	void refreshMap(const Vec2& topLeft, const Vec2& botRight) {
		for (int y = topLeft.y; y < botRight.y; ++y) {
			for (int x = topLeft.x; x < botRight.x; ++x) {
				mainMap->drawSolidRect(Vec2(x, y), Vec2(x + 1, y + 1), Color4F(map[y][x] ? 1 : 0, 0, 0, 1));
			}
		}
	}

	static MapView* create(std::vector<std::vector<u_char>>& map) {
		auto ptr = new(std::nothrow) MapView(map);
		ptr->init();
		ptr->retain();
		return ptr;
	}
};

#endif //WORM_MAPVIEW_H
