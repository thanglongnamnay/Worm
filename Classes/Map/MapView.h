//
// Created by long on 20/05/2020.
//

#ifndef WORM_MAPVIEW_H
#define WORM_MAPVIEW_H

#include <cocos2d.h>
#include <cocos/editor-support/cocostudio/ActionTimeline/CSLoader.h>
#include <cocos/ui/UISlider.h>
#include <Units/UnitPhysic.h>

USING_NS_CC;

class MapView : public Node {
	Node* hud{};
	ui::Slider* powerBar{};
	const std::vector<std::vector<u_char>>& map;
	const Size screen;
	std::shared_ptr<UnitPhysic> following = nullptr;
	DrawNode* drawNode{};
	Node* background{};
public:
	const Color4F FOREGROUND_COLOR = Color4F(0.6f, 0.3f, 0, 1);
	const Color4F BACKGROUND_COLOR = Color4F(0, 0, 0, 1);
	Node* mainMap{};
	explicit MapView(std::vector<std::vector<u_char>>& map);

	bool init() override;

	int getPower() const;

	void follow(const std::shared_ptr<UnitPhysic>& unit);

	void update(float delta) override;

	void addObject(Node* node) const;

	~MapView() override;

	void refreshMap();

	void refreshMap(double x, double y);

	void refreshMap(const Vec2& topLeft, const Vec2& botRight);

	static MapView* create(std::vector<std::vector<u_char>>& map);
	void drawCircle(const Vec2& pos, double radius);
};

#endif //WORM_MAPVIEW_H
