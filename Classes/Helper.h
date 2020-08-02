//
// Created by long on 20/05/2020.
//

#ifndef WORM_HELPER_H
#define WORM_HELPER_H

#include <string>

USING_NS_CC;
using namespace std;

class Helper {
public:
    static string getSocketAddr(char host[], int port) {
        return string(host) + ":" + to_string(port);
    }

    static vector<string> split(const string &s, char delim = '|') {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static void showText(const string &s) {
        auto scene = Director::getInstance()->getRunningScene();
        if (scene) {
			auto text = Label::createWithSystemFont(s, "Arial", 64);
			text->setPosition(scene->getContentSize().width / 2, scene->getContentSize().height / 2);
			text->runAction(Sequence::create({EaseIn::create(MoveBy::create(1, {0, 100}), 2), RemoveSelf::create()}));
			scene->addChild(text);
		}
    }
};

#endif //WORM_HELPER_H
