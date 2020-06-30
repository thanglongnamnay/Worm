//
// Created by long on 20/05/2020.
//

#ifndef WORM_MAPVIEW_H
#define WORM_MAPVIEW_H

#include <cocos2d.h>
#include <cocos/editor-support/cocostudio/ActionTimeline/CSLoader.h>

USING_NS_CC;

class MapView : public Node {
    DrawNode *mainMap{};
    Node *hud{};
    const std::vector<std::vector<u_char>> &map;
public:
    explicit MapView(std::vector<std::vector<u_char>> &map)
            : Node(), map(map) {
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
        for (int y = 0; y < map.size(); ++y) {
            for (int x = 0; x < map[0].size(); ++x) {
                refreshMap(x, y);
            }
        }
    }

    void refreshMap(double x, double y) {
        mainMap->drawSolidRect(Vec2(x, y), Vec2(x + 1, y + 1), Color4F(map[y][x] ? 1 : 0, 0, 0, 1));
    }

    void refreshMap(const Vec2 &topLeft, const Vec2 &botRight) {
        for (int y = topLeft.y; y < botRight.y; ++y) {
            for (int x = topLeft.x; x < botRight.x; ++x) {
                mainMap->drawSolidRect(Vec2(x, y), Vec2(x + 1, y + 1), Color4F(map[y][x] ? 1 : 0, 0, 0, 1));
            }
        }
    }

    static MapView *create(std::vector<std::vector<u_char>> &map) {
        auto ptr = new(std::nothrow) MapView(map);
        ptr->init();
        ptr->autorelease();
        return ptr;
    }
};

#endif //WORM_MAPVIEW_H
