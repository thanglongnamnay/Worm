//
// Created by MacBook Pro on 6/30/20.
//

#include "GuiLogin.h"

void GuiLogin::login() {
	auto& name = tfName->getString();
	Game::instance->login(name);
}
