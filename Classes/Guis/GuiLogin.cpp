//
// Created by MacBook Pro on 6/30/20.
//

#include "GuiLogin.h"

void GuiLogin::login() {
	auto& name = tfName->getString();
	Game::instance->login(name);
}

bool GuiLogin::init() {
    Node::init();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    hud = CSLoader::createNode("res/Login.csb");
    addChild(hud);
    tfName = hud->getChildByName<ui::TextField*>("tfName");
    btnLogin = hud->getChildByName<ui::Button*>("btnLogin");
    btnLogin->addClickEventListener([=](Ref* event) {
        login();
    });
    return true;
}

GuiLogin *GuiLogin::create() {
    auto ptr = new(std::nothrow) GuiLogin();
    ptr->init();
    ptr->autorelease();
    return ptr;
}
