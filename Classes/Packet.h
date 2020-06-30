//
// Created by long on 30/05/2020.
//

#ifndef WORM_PACKET_H
#define WORM_PACKET_H

#include <vector>
#include "network/WebSocket.h"
#include "cocos2d.h"
#include "GameEvent.h"
#include "Helper.h"
#include <type_safe/strong_typedef.hpp>

namespace ts = type_safe;

struct Packet {
    constexpr const static char delim[] = "|";
    int cmd = 0;
    std::vector<std::string> params;

    explicit Packet(const cocos2d::network::WebSocket::Data &data) {
        std::string msg = std::string(data.bytes, data.len);
        params = Helper::split(msg, '|');
        cmd = std::stoi(params[0]);
        params.erase(params.begin());
    }

    Packet(const int cmd, std::vector<std::string> params)
            : cmd(cmd), params(std::move(params)) {}

    [[nodiscard]] std::string toSocketData() const {
        std::string msg{std::to_string(cmd)};
        for (const auto& param : params) msg += delim + param;
        return msg;
    }

    explicit operator Object() const {
        Object obj{
                {"cmd",    cmd},
                {"params", params},
        };
    }
};

#endif //WORM_PACKET_H
