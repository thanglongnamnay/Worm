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

constexpr const double epsilon = 0.001;

class MapLogic : game::EventListener {
private:
	void handleEvent(int eventName, const Object& data) override;

	int seed;
	type::Vector<int> mapSize;
	vector<vector<unsigned char>> map;
	list<shared_ptr<UnitPhysic>> unitList;
	static minstd_rand0 rand;
public:
	MapView* mapView;
	explicit MapLogic(type::Vector<int> mapSize);
	MapLogic(MapLogic&& rhs) noexcept
			:seed(rhs.seed), mapSize(rhs.mapSize), map(move(rhs.map)), mapView(rhs.mapView) {
	}
	void recreateMap(int newSeed);
	void addUnit(const shared_ptr<UnitPhysic>& unitPhysic);
	void removeUnit(const shared_ptr<UnitPhysic>& unitPhysic);
	void update(double dt);
private:
	void drawLine(int sx, int ex, int ny);
	void CircleBresenham(const Vec2& pos, int r);;
	void explode(UnitPhysic* unit, double radius);
	static vector<vector<unsigned char>> createMap(type::Vector<int> mapSize);
	static vector<double> perlinNoise1D(const vector<double>& seeds, int octaves, double bias);
	void handleNetworkCmd(CMD cmd, Params& params);
};

#endif //WORM_MAPLOGIC_H
