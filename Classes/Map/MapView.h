//
// Created by long on 20/05/2020.
//

#ifndef WORM_MAPVIEW_H
#define WORM_MAPVIEW_H

#include <cocos2d.h>
#include <cocos/editor-support/cocostudio/ActionTimeline/CSLoader.h>

USING_NS_CC;

class MapView : public Node {
	DrawNode* mainMap{};
	Node* hud{};
	const std::vector<std::vector<u_char>>& map;
public:
	explicit MapView(std::vector<std::vector<u_char>>& map)
			:Node(), map(map) {
	}

	bool init() override {
		Node::init();
		mainMap = DrawNode::create();
		addChild(mainMap);
		hud = CSLoader::createNode("res/GameHUD.csb");
		addChild(hud);
		return true;
	}

	~MapView() override {
		CCLOG("DELETED MapView");
	}

	void refreshMap() {
		mainMap->clear();
		USING_NS_CC;
		for (int y = 0; y<map.size(); ++y) {
			for (int x = 0; x<map[0].size(); ++x) {
				mainMap->drawSolidRect(Vec2(x, y), Vec2(x+1, y+1), Color4F(map[y][x] ? 1 : 0, 0, 0, .5));
			}
		}
	}
	void refreshMap(int px, int py) {
		USING_NS_CC;
		mainMap->drawSolidRect(Vec2(px, py), Vec2(px+1, py+1), Color4F(map[py][px] ? 1 : 0, 0, 0, .5));
	}

	static MapView* create(std::vector<std::vector<u_char>>& map) {
		auto ptr = new(std::nothrow) MapView(map);
		ptr->init();
		ptr->autorelease();
		return ptr;
	}
};

#endif //WORM_MAPVIEW_H
