//
// Created by long on 20/05/2020.
//

#include "GameNetwork.h"

bool GameNetwork::send(const string &message) {
    try {
        CCLOG("Sending...");
        if (socket != nullptr) {
            if (socket->getReadyState() == network::WebSocket::State::OPEN)
                socket->send(message);
            else if (socket->getReadyState() == network::WebSocket::State::CONNECTING)
                pendingMessages.push_back(message);
        }

        return true;
    } catch (const std::exception&) {
        throw;
    }

    return false;
}

void GameNetwork::onOpen(network::WebSocket *ws) {
    if (!pendingMessages.empty()) {
        for (const auto& message : pendingMessages)
            send(message);

        pendingMessages.clear();
    }
}

void GameNetwork::onMessage(network::WebSocket *ws, const network::WebSocket::Data &data) {
    const string msg = string(data.bytes, data.len);
    CCLOG(msg.c_str());
}

void GameNetwork::onClose(network::WebSocket *ws) {
    CCLOG("Socket closed.");
}

void GameNetwork::onError(network::WebSocket *ws, const network::WebSocket::ErrorCode &error) {
    CCLOG("Socket error %d", error);
}

GameNetwork::GameNetwork(const char *url)
        : socket(new WebSocket())
        , url(url)
        , pendingMessages() {
    socket->init(*this, url);
}

GameNetwork::~GameNetwork() {
    socket->close();
}
