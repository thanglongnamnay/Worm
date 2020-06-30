//
// Created by long on 20/05/2020.
//

#include "GameNetwork.h"

bool GameNetwork::send(const int cmd, const vector<string> &message) {
    return send(Packet(cmd, message));
}

bool GameNetwork::send(int cmd, const vector<int> &message) {
    vector<string> msg{};
    for (auto& m : message) msg.push_back(to_string(m));
    return send(Packet(cmd, msg));
}

bool GameNetwork::send(const Packet &packet) {
    try {
        CCLOG("Sending...");
        if (socket != nullptr) {
            if (socket->getReadyState() == network::WebSocket::State::OPEN) {
                const string &socketData = packet.toSocketData();
                socket->send(socketData);
            } else if (socket->getReadyState() == network::WebSocket::State::CONNECTING) {
                pendingMessages.push_back(packet);
            }
        }

        return true;
    }
    catch (const std::exception &) {
        CCLOG("Send fail. Resending...");
        send(packet);
    }

    return false;
}

void GameNetwork::onOpen(network::WebSocket *ws) {
    if (!pendingMessages.empty()) {
        for (const auto &message : pendingMessages) {
            send(message);
        }

        pendingMessages.clear();
    }
}

void GameNetwork::onMessage(network::WebSocket *ws, const network::WebSocket::Data &data) {
//    const string msg = string(data.bytes, data.len);
//    CCLOG(msg.c_str());

    const Packet packet(data);
    game::EventManager::emit(event::EVENT_RECEIVE_PACKET, static_cast<Object>(packet));
}

void GameNetwork::onClose(network::WebSocket *ws) {
    CCLOG("Socket closed.");
}

void GameNetwork::onError(network::WebSocket *ws, const network::WebSocket::ErrorCode &error) {
    CCLOG("Socket error %d", error);
}

GameNetwork::GameNetwork(const char *url)
        : socket(new WebSocket()), url(url), pendingMessages() {
    socket->init(*this, url);
}

GameNetwork::~GameNetwork() {
    socket->close();
}
