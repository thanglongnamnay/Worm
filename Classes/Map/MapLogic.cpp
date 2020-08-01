//
// Created by long on 22/05/2020.
//

#include "MapLogic.h"
#include <GameNetwork.h>

vector<double> MapLogic::perlinNoise1D(const vector<double>& seeds, int octaves, double bias) {
	auto nCount = seeds.size();
	vector<double> output(nCount);
	for (auto x = 0; x < nCount; x++) {
		auto noise = 0.0;
		auto scaleAcc = 0.0;
		auto scale = 1.0;

		for (auto o = 0; o < octaves; o++) {
			auto pitch = nCount >> o;
			auto sample1 = (x / pitch) * pitch;
			auto sample2 = (sample1 + pitch) % nCount;
			auto blend = (double)(x - sample1) / (double)pitch;
			auto sample = (1.0 - blend) * seeds[sample1] + blend * seeds[sample2];
			scaleAcc += scale;
			noise += sample * scale;
			scale = scale / bias;
		}
		output[x] = noise / scaleAcc;
	}
	return output;
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
		}
	}
}
void MapLogic::CircleBresenham(const Vec2& pos, const int r) {
	auto x = 0;
	auto y = r;
	auto p = 3 - 2 * r;
	auto xc = pos.x;
	auto yc = pos.x;
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
	mapView->drawCircle(pos, r);
}
std::vector<std::vector<unsigned char>> MapLogic::createMap(type::Vector<int> mapSize) {
	auto noiseSeeds = std::vector<double>(static_cast<int>(mapSize.x));
	for (int i = 0; i < mapSize.x; i++) {
		noiseSeeds[i] = (double)rand() / RAND_MAX;
	}
	noiseSeeds[0] = 0.5f;
	auto fSurface = perlinNoise1D(noiseSeeds, 10, 1.5 + noiseSeeds.back());
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
	CircleBresenham(unit->position, radius);

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

