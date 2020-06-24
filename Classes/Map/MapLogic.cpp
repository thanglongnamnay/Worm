//
// Created by long on 22/05/2020.
//

#include "MapLogic.h"

#include <utility>

std::vector<double> MapLogic::PerlinNoise1D(std::vector<double> fSeed, int nOctaves, double fBias) {
	auto nCount = fSeed.size();
	std::vector<double> fOutput(nCount);
	for (auto x = 0; x<nCount; x++) {
		auto fNoise = 0.0f;
		auto fScaleAcc = 0.0f;
		auto fScale = 1.0f;

		for (auto o = 0; o<nOctaves; o++) {
			auto nPitch = nCount >> o;
			auto nSample1 = (x/nPitch)*nPitch;
			auto nSample2 = (nSample1+nPitch)%nCount;
			auto fBlend = (double)(x-nSample1)/(double)nPitch;
			auto fSample = (1.0f-fBlend)*fSeed[nSample1]+fBlend*fSeed[nSample2];
			fScaleAcc += fScale;
			fNoise += fSample*fScale;
			fScale = fScale/fBias;
		}
		fOutput[x] = fNoise/fScaleAcc;
	}
	return fOutput;
}

MapLogic::MapLogic(type::Vector<int> mapSize)
		: mapSize(mapSize), game::EventListener() {
	map = createMap(mapSize);
	mapView = MapView::create(map);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Worm/texture.plist", "Worm/texture.png");
    worm = std::make_shared<Worm>(300, 400);
    addUnit(worm);
	mapView->schedule([=](float dt) {
	  this->update(dt);
	}, 0.0f, "update");


	const auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
        CCLOG("Key pressed");
        if (worm->isStable) {
            switch (keyCode) {
                case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                case EventKeyboard::KeyCode::KEY_A:
                    worm->vy = 20;
                    worm->vx = -10;
                    break;
                case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                case EventKeyboard::KeyCode::KEY_D:
                    worm->vy = 20;
                    worm->vx = 10;
                    break;
                case EventKeyboard::KeyCode::KEY_SPACE:
                    addUnit(worm->make_bullet());
                    break;
                default:
                    break;
            }
        }
    };
    listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
        worm->ay = 0;
        worm->ax = 0;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, worm->view);

}

void MapLogic::handleEvent(int eventName, const Object &data) {
    if (eventName == EVENT_EXPLODE) {
        auto unit = std::any_cast<UnitPhysic*>(data.at("unit"));
        auto respond = std::any_cast<int>(data.at("respond"));
        explode(unit->px, unit->py, respond);
    }
}

