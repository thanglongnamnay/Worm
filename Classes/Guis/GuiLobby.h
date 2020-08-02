//
// Created by long on 02/08/2020.
//

#ifndef WORM_GUILOBBY_H
#define WORM_GUILOBBY_H

#include <cocos2d.h>
#include <cocos/editor-support/cocostudio/ActionTimeline/CSLoader.h>
#include <cocos/ui/UITextField.h>
#include <cocos/ui/UIButton.h>
#include <Game.h>

class GuiLobby : public Node {
	Node* hud;
public:
	bool init() override;

	static GuiLobby* create();
};

#endif //WORM_GUILOBBY_H
