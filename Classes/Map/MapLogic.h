//
// Created by long on 22/05/2020.
//

#ifndef WORM_MAPLOGIC_H
#define WORM_MAPLOGIC_H

#include <vector>
#include <GameEvent.h>
#include <Units/UnitPhysic.h>
#include <Packet.h>
#include <GameNetwork.h>
#include <Types/Vector.h>
#include "MapView.h"
#include "Player.h"

constexpr const double epsilon = 0.001;

class MapLogic : game::EventListener {
private:
	void handleEvent(int eventName, const Object& data) override;

	int seed;
	type::Vector<int> mapSize;
	std::vector<std::vector<unsigned char>> map;
	std::list<std::shared_ptr<UnitPhysic>> unitList;
public:
	MapView* mapView;
	explicit MapLogic(type::Vector<int> mapSize);
	MapLogic(MapLogic&& rhs) noexcept
			:seed(rhs.seed), mapSize(rhs.mapSize), map(std::move(rhs.map)), mapView(rhs.mapView) {
	}
	void recreateMap(int newSeed);
	void addUnit(const std::shared_ptr<UnitPhysic>& unitPhysic);
	void removeUnit(const std::shared_ptr<UnitPhysic>& unitPhysic);
	void update(double dt);
private:
	void drawLine(const int sx, const int ex, const int ny);
	void CircleBresenham(int xc, int yc, int r);;
	void explode(UnitPhysic* unit, double radius);
	static std::vector<std::vector<unsigned char>> createMap(type::Vector<int> mapSize);
	static std::vector<double> PerlinNoise1D(std::vector<double> fSeed, int nOctaves, double fBias);
	void handleNetworkCmd(CMD cmd, Params& params);
};

#endif //WORM_MAPLOGIC_H
