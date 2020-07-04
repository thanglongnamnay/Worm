//
// Created by long on 04/07/2020.
//

#ifndef WORM_GUIENDGAME_H
#define WORM_GUIENDGAME_H

#include <cocos2d.h>
#include <cocos/editor-support/cocostudio/ActionTimeline/CSLoader.h>
#include <cocos/ui/UITextField.h>
#include <cocos/ui/UIButton.h>
#include <Game.h>

#include <utility>

class GuiEndGame : public Node {
public:
	string name;
	bool draw;
	explicit GuiEndGame(string name) : Node(), name(std::move(name)), draw(false) {}
	explicit GuiEndGame() : Node(), name(), draw(true) {}
	bool init() override {
		Node::init();
		auto visibleSize = Director::getInstance()->getVisibleSize();
		auto lbVictory = Label::create();
		lbVictory->setBMFontSize(48);
		lbVictory->setSystemFontSize(48);
		lbVictory->setString(draw ? "Draw" : "Player " + name + " won");
		lbVictory->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		addChild(lbVictory);

		auto lbBtnBack = Label::create();
		lbBtnBack->setBMFontSize(48);
		lbBtnBack->setSystemFontSize(48);
		lbBtnBack->setString("Back to lobby");

		auto btnBack = ui::Button::create();
		btnBack->setTitleLabel(lbBtnBack);
		btnBack->setPosition({visibleSize.width / 2, visibleSize.height / 2 - 100});
		btnBack->addClickEventListener([](Ref* sender) {
			Game::instance->showLoginScene();
		});
		addChild(btnBack);
		return true;
	}
	static GuiEndGame* create() {
		auto ptr = new(std::nothrow) GuiEndGame();
		ptr->init();
		ptr->autorelease();
		return ptr;
	}
	static GuiEndGame* create(const string& name) {
		auto ptr = new(std::nothrow) GuiEndGame(name);
		ptr->init();
		ptr->autorelease();
		return ptr;
	}
};

#endif //WORM_GUIENDGAME_H
