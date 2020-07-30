//
// Created by long on 22/05/2020.
//

#include "MapLogic.h"
#include <GameNetwork.h>

vector<double> MapLogic::PerlinNoise1D(vector<double> fSeed, int nOctaves, double fBias) {
	auto nCount = fSeed.size();
	vector<double> fOutput(nCount);
	for (auto x = 0; x < nCount; x++) {
		auto fNoise = 0.0f;
		auto fScaleAcc = 0.0f;
		auto fScale = 1.0f;

		for (auto o = 0; o < nOctaves; o++) {
			auto nPitch = nCount >> o;
			auto nSample1 = (x / nPitch) * nPitch;
			auto nSample2 = (nSample1 + nPitch) % nCount;
			auto fBlend = (double)(x - nSample1) / (double)nPitch;
			auto fSample = (1.0f - fBlend) * fSeed[nSample1] + fBlend * fSeed[nSample2];
			fScaleAcc += fScale;
			fNoise += fSample * fScale;
			fScale = fScale / fBias;
		}
		fOutput[x] = fNoise / fScaleAcc;
	}
	return fOutput;
}

MapLogic::MapLogic(type::Vector<int> mapSize)
		:mapSize(mapSize), game::EventListener() {
	seed = time(0);
	srand(seed);
	map = createMap(mapSize);
	mapView = MapView::create(map);
}

void MapLogic::handleEvent(int eventName, const Object& data) {
	if (eventName == event::EVENT_EXPLODE) {
		CCLOG("Exploded");
		auto unit = any_cast<UnitPhysic*>(data.at("unit"));
		auto respond = any_cast<int>(data.at("respond"));
		explode(unit, respond);
		return;
	}
	if (eventName == event::EVENT_RECEIVE_PACKET) {
		auto cmd = any_cast<int>(data.at("cmd"));
		auto params = any_cast<Params>(data.at("params"));
		handleNetworkCmd(static_cast<CMD>(cmd), params);
		return;
	}
}
void MapLogic::recreateMap(int newSeed) {
	if (newSeed == seed) return;
	seed = newSeed;
	srand(seed);
	unitList.clear();
	map = createMap(mapSize);
	const auto& viewParent = mapView->getParent();
	for (const auto& unit : unitList) unit->getView()->removeFromParent();
	mapView->removeFromParent();
	mapView = MapView::create(map);
	viewParent->addChild(mapView);
	for (const auto& unit : unitList) mapView->addChild(unit->getView());
	mapView->refreshMap();
}
void MapLogic::addUnit(const shared_ptr<UnitPhysic>& unitPhysic) {
	unitPhysic->draw();
	mapView->addObject(unitPhysic->getView());
	unitList.push_back(unitPhysic);
}
void MapLogic::removeUnit(const shared_ptr<UnitPhysic>& unitPhysic) {
	unitList.remove_if([&](const std::shared_ptr<UnitPhysic>& o) {
		return o == unitPhysic;
	});
}
void MapLogic::update(double dt) {
	dt *= 10;
	for (auto& p : unitList) {
		if (!p->isDead) {
			p->update(dt, map);
		}
	}

	unitList.remove_if([](const std::shared_ptr<UnitPhysic>& o) { return o->isDead; });
}
void MapLogic::drawLine(const int sx, const int ex, const int ny) {
	if (ny < 0) return;
	for (int i = sx; i < ex; i++) {
		if (ny < mapSize.y && i >= 0 && i < mapSize.x) {
			map[ny][i] = 0;
			mapView->refreshMap(i, ny);
		}
	}
}
void MapLogic::CircleBresenham(int xc, int yc, int r) {
	int x = 0;
	int y = r;
	int p = 3 - 2 * r;
	if (!r) return;

	while (y >= x) {
		// Modified to draw scan-lines instead of edges
		drawLine(xc - x, xc + x, yc - y);
		drawLine(xc - y, xc + y, yc - x);
		drawLine(xc - x, xc + x, yc + y);
		drawLine(xc - y, xc + y, yc + x);
		if (p < 0) p += 4 * x++ + 6;
		else p += 4 * (x++ - y--) + 10;
	}
}
std::vector<std::vector<unsigned char>> MapLogic::createMap(type::Vector<int> mapSize) {
	auto noiseSeeds = std::vector<double>(static_cast<int>(mapSize.x));
	for (int i = 0; i < mapSize.x; i++) {
		noiseSeeds[i] = (double)rand() / RAND_MAX;
	}
	noiseSeeds[0] = 0.5f;
	auto fSurface = PerlinNoise1D(noiseSeeds, 10, 1.5 + noiseSeeds.back());
	std::vector<std::vector<unsigned char>> map(mapSize.y);
	for (auto y = 0; y < mapSize.y; ++y) {
		map[y] = std::vector<unsigned char>(mapSize.x);
		for (auto x = 0; x < mapSize.x; ++x) {
			map[y][x] = y < fSurface[x] * mapSize.y;
		}
	}
	return map;
}
void MapLogic::handleNetworkCmd(CMD cmd, Params& params) {

}
void MapLogic::explode(UnitPhysic* unit, double radius) {
    CircleBresenham(unit->position.x, unit->position.y, radius);

	for (const auto& otherUnit : unitList) {
		if (otherUnit.get() == unit) continue;
		Vec2 delta = otherUnit->position - unit->position;
		double distance = delta.getLength();
		if (distance < epsilon) distance = epsilon;

		if (distance < radius) {
			game::EventManager::emit(EVENT_HIT, (Object){
					{"shooter", unit->playerId},
					{"shot",    otherUnit->playerId},
			});
			otherUnit->velocity = delta / (distance / radius);
			otherUnit->isStable = false;
		}
	}

	// Launch debris proportional to blast size
	for (int i = 0; i < (int)radius; i++)
		addUnit(std::make_shared<Debris>(unit->position));
}

