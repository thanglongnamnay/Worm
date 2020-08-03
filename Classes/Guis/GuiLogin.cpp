//
// Created by MacBook Pro on 6/30/20.
//

#include "GuiLogin.h"

void GuiLogin::login() {
	auto& name = tfName->getString();
	Game::instance->login(name);
}

bool GuiLogin::init() {
    LayerColor::initWithColor({50, 50, 50, 255});
    auto visibleSize = Director::getInstance()->getVisibleSize();
    hud = CSLoader::createNode("res/Login.csb");
    addChild(hud);
    tfName = hud->getChildByName<ui::TextField*>("tfName");
    tfName->setPosition(visibleSize / 2 + Size{0, 50});
    tfName->setTextVerticalAlignment(TextVAlignment::CENTER);
    tfName->setTextHorizontalAlignment(TextHAlignment::CENTER);
    btnLogin = hud->getChildByName<ui::Button*>("btnLogin");
    btnLogin->setPosition(visibleSize / 2 - Size{0, 50});
    btnLogin->setTitleColor(Color3B::BLACK);
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
