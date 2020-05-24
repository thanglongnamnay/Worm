//
// Created by long on 20/05/2020.
//

#ifndef WORM_MAPVIEW_H
#define WORM_MAPVIEW_H

#include <cocos2d.h>

class MapView : public cocos2d::DrawNode {
    const std::vector<std::vector<u_char>> &map;
public:
    explicit MapView(std::vector<std::vector<u_char>> &map) : cocos2d::DrawNode(), map(map) {}
    ~MapView() override {
        CCLOG("DELETED MapView");
    }
    void refreshMap() {
        clear();
        USING_NS_CC;
        for (int y = 0; y < map.size(); ++y) {
            std::string line;
            for (int x = 0; x < map[0].size(); ++x) {
                drawSolidRect(Vec2(x, y), Vec2(x+1, y+1), Color4F(map[y][x] ? 0 : 1, 0, 0, .5));
            }
        }
    }

    static MapView* create(std::vector<std::vector<u_char>> &map) {
        auto ptr = new(std::nothrow) MapView(map);
        ptr->init();
        ptr->autorelease();
        return ptr;
    }
};


#endif //WORM_MAPVIEW_H
