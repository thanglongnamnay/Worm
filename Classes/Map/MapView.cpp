//
// Created by long on 20/05/2020.
//

#include "MapView.h"

MapView::MapView(std::vector<std::vector<u_char>>& map)
		:Node(), map(map), screen(Director::getInstance()->getVisibleSize()) {
}
bool MapView::init() {
	Node::init();
	background = Node::create();
	TextureCache* textureCache = Director::getInstance()->getTextureCache();
	auto backgroundTexture = textureCache->addImage("ground.png");
	for (auto y = 0; y < map.size(); y += 120) {
		for (auto x = 0; x < map[0].size(); x += 120) {
			auto sprite = Sprite::createWithTexture(backgroundTexture);
			sprite->setPosition(x, y);
			background->addChild(sprite);
		}
	}
	drawNode = DrawNode::create();
	drawNode->retain();
//	clippingNode->addChild(drawNode);
	mainMap = Node::create();
	mainMap->addChild(drawNode);
	addChild(mainMap);
	hud = CSLoader::createNode("res/GameHUD.csb");
	addChild(hud);
	const auto ndProperties = hud->getChildByName("ndPropertyies");
	hpBar = dynamic_cast<ui::LoadingBar*>(ndProperties->getChildByName("barHp"));
	hpBar->setColor(Color3B::GREEN);
	mpBar = dynamic_cast<ui::LoadingBar*>(ndProperties->getChildByName("barMana"));
	mpBar->setColor(Color3B::BLUE);
	powerBar = hud->getChildByName("ndPropertyies")->getChildByName<ui::Slider*>("slPower");
	scheduleUpdate();
	return true;
}
int MapView::getPower() const {
	if (!powerBar) return 100;
	CCLOG("powerBar: %d", powerBar->getPercent());
	return powerBar->getPercent();
}
void MapView::follow(const std::shared_ptr<UnitPhysic>& unit) {
	following = unit;
	CCLOG("change following");
}
void MapView::update(float delta) {
	if (following && !following->isDead) {
		const auto dest = Vec2{-following->getView()->getPositionX() * mainMap->getScale() + screen.width / 2, -following->getView()->getPositionY() * mainMap->getScale() + screen.height / 2};
		const auto curr = mainMap->getPosition();
		if (dest.distanceSquared(curr) < delta * 100) mainMap->setPosition(dest);
		mainMap->setPosition(curr.lerp(dest, 0.1f));
	} else {
		mainMap->setPosition(0, 0);
	}
}
void MapView::addObject(Node* node) const {
	mainMap->addChild(node);
}
MapView::~MapView() {
	CCLOG("DELETED MapView");
}
void MapView::refreshMap() {
	drawNode->clear();
	for (int y = 0; y < map.size(); ++y) {
		for (int x = 0; x < map[0].size(); ++x) {
			refreshMap(x, y);
		}
	}
}
void MapView::refreshMap(double x, double y) {
	drawNode->drawSolidRect(Vec2(x, y), Vec2(x + 1, y + 1), map[y][x] ? FOREGROUND_COLOR : BACKGROUND_COLOR);
}
void MapView::refreshMap(const Vec2& topLeft, const Vec2& botRight) {
	for (int y = topLeft.y; y < botRight.y; ++y) {
		for (int x = topLeft.x; x < botRight.x; ++x) {
			refreshMap(x, y);
		}
	}
}
MapView* MapView::create(std::vector<std::vector<u_char>>& map) {
	auto ptr = new(std::nothrow) MapView(map);
	ptr->init();
	ptr->retain();
	return ptr;
}
void MapView::drawCircle(const Vec2& pos, double radius) {
	drawNode->drawSolidCircle(pos, radius, 3.14 * 2, 50, BACKGROUND_COLOR);
}
void MapView::refreshGui(const HP& hp, const MP& mp) {
	hpBar->setPercent(static_cast<int>(hp));
	mpBar->setPercent(static_cast<int>(mp));
}
