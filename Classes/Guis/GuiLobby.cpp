//
// Created by long on 02/08/2020.
//

#include "GuiLobby.h"

bool GuiLobby::init() {
	if (!Node::init()) return false;
	hud = CSLoader::createNode("res/Lobby.csb");
	hud->setScale(0.5f);
	addChild(hud);
	return true;
}
GuiLobby *GuiLobby::create() {
	auto ptr = new(std::nothrow) GuiLobby();
	ptr->init();
	ptr->autorelease();
	return ptr;
}

