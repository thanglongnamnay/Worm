//
// Created by long on 20/05/2020.
//

#ifndef WORM_MAPVIEW_H
#define WORM_MAPVIEW_H

#include <cocos2d.h>

USING_NS_CC;

class MapView : DrawNode {
    std::vector<std::vector<u_char>> &map;
    void refreshMap() {
        clear();
        for (int y = 0; y < map.size(); ++y) {
            for (int x = 0; x < map[0].size(); ++x) {
                drawSolidRect(Vec2(0, 0), Vec2(img->getWidth(), img->getHeight()), Color4F(1.0f, 0.0f, 0.0f, 0.5f));
            }
        }
    }
};


#endif //WORM_MAPVIEW_H
