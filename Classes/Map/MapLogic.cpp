//
// Created by long on 22/05/2020.
//

#include "MapLogic.h"

#include <utility>
#include <GameNetwork.h>

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
}

void MapLogic::handleEvent(int eventName, const Object &data) {
    if (eventName == event::EVENT_EXPLODE) {
        CCLOG("Exploded");
        auto unit = std::any_cast<UnitPhysic*>(data.at("unit"));
        auto respond = std::any_cast<int>(data.at("respond"));
        explode(unit->px, unit->py, respond);
        return;
    }
    if (eventName == event::EVENT_RECEIVE_PACKET) {
        auto cmd = std::any_cast<string>(data.at("cmd"));
        auto params = std::any_cast<std::vector<int>>(data.at("params"));
        handleNetworkCmd(static_cast<CMD>(stoi(cmd))); //ugly as fuck i know
        return;
    }
}

void MapLogic::handleNetworkCmd(CMD cmd) {
    switch (cmd) {
        // TODO: implement this shit
    }
}

