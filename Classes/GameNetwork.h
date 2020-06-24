//
// Created by long on 20/05/2020.
//

#ifndef WORM_GAMENETWORK_H
#define WORM_GAMENETWORK_H

#include <iostream>
#include <type_safe/strong_typedef.hpp>
#include <utility>
#include "network/WebSocket.h"
#include "cocos2d.h"
#include "Packet.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::network;

typedef std::function<void(std::vector<int>)> NetworkCallback;

class GameNetwork : public WebSocket::Delegate {
private:
    unique_ptr<WebSocket> socket;
    string url;
    vector<Packet> pendingMessages;
public:
    static int EVENT_RECEIVE_PACKET;
    explicit GameNetwork(const char url[]);
    ~GameNetwork() override;
    bool send(int cmd, const vector<int>& message);
    bool send(const Packet& packet);
    void onOpen(network::WebSocket* ws) override;
    void onMessage(network::WebSocket* ws, const network::WebSocket::Data& data) override;
    void onClose(network::WebSocket* ws) override;
    void onError(network::WebSocket* ws, const network::WebSocket::ErrorCode& error) override;
};

enum CMD {
    JOIN_ROOM = 69,
    MOVE,
    SHOOT,
};

#endif //WORM_GAMENETWORK_H
