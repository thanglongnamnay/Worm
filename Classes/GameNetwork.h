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
	static GameNetwork* instance;
    explicit GameNetwork(const char url[]);
    ~GameNetwork() override;
    bool send(int cmd);
    bool send(int cmd, const vector<string>& message);
    bool send(int cmd, const vector<int>& message);
    bool send(const Packet& packet);
    void onOpen(network::WebSocket* ws) override;
    void onMessage(network::WebSocket* ws, const network::WebSocket::Data& data) override;
    void onClose(network::WebSocket* ws) override;
    void onError(network::WebSocket* ws, const network::WebSocket::ErrorCode& error) override;
};

enum class CMD {
	LOGIN = 1,
	JOIN_ROOM = 2,
	LEAVE_ROOM = 3,
	GAME_ACTION = 4,
	START = 5,
	YOUR_ID = 6,
	NEXT_TURN = 7,
	SYNC_PLAYER = 8,
	END_GAME = 9,
    MOVE,
    SHOOT,
};

enum class GAME_ACTION {
	SHOOT = 1,
	CHANGE_ANGLE,
	MOVE,
};

#endif //WORM_GAMENETWORK_H
