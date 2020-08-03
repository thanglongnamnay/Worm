//
// Created by MacBook Pro on 6/30/20.
//

#ifndef WORM_GUILOGIN_H
#define WORM_GUILOGIN_H

#include <cocos2d.h>
#include <cocos/editor-support/cocostudio/ActionTimeline/CSLoader.h>
#include <cocos/ui/UITextField.h>
#include <cocos/ui/UIButton.h>
#include <Game.h>

USING_NS_CC;

class GuiLogin : public LayerColor {
public:
	Node* hud = nullptr;
	ui::TextField* tfName = nullptr;
	ui::Button* btnLogin = nullptr;

	bool init() override;

	void login();

	static GuiLogin* create();
};

#endif //WORM_GUILOGIN_H
