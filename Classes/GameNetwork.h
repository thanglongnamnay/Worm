//
// Created by long on 20/05/2020.
//

#ifndef WORM_GAMENETWORK_H
#define WORM_GAMENETWORK_H

#include <iostream>
#include "network/WebSocket.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::network;

class GameNetwork : public WebSocket::Delegate {
private:
    unique_ptr<WebSocket> socket;
    string url;
    vector<string> pendingMessages;
public:
    explicit GameNetwork(const char url[]);
    ~GameNetwork() override;
    bool send(const string& message);
    void onOpen(network::WebSocket* ws) override;
    void onMessage(network::WebSocket* ws, const network::WebSocket::Data& data) override;
    void onClose(network::WebSocket* ws) override;
    void onError(network::WebSocket* ws, const network::WebSocket::ErrorCode& error) override;
};


#endif //WORM_GAMENETWORK_H
