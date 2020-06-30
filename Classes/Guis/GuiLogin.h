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

class GuiLogin : public Node {
public:
    Node* hud = nullptr;
    ui::TextField* tfName = nullptr;
    ui::Button* btnLogin = nullptr;

    bool init() override {
        Node::init();
        hud = CSLoader::createNode("res/Login.csb");
        addChild(hud);
        tfName = dynamic_cast<ui::TextField *>(hud->getChildByName("tfName"));
        btnLogin = dynamic_cast<ui::Button *>(hud->getChildByName("btnLogin"));
        return true;
    }

    void login() {
        auto& name = tfName->getString();
        Game::instance->login(name);
    }

    static GuiLogin *create() {
        auto ptr = new(std::nothrow) GuiLogin();
        ptr->init();
        ptr->autorelease();
        return ptr;
    }
};

#endif //WORM_GUILOGIN_H
