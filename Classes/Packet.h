//
// Created by long on 30/05/2020.
//

#ifndef WORM_PACKET_H
#define WORM_PACKET_H

#include <vector>
#include "network/WebSocket.h"
#include "cocos2d.h"
#include "GameEvent.h"
#include "GameNetwork.h"

namespace ts = type_safe;

struct CmdCode : ts::strong_typedef<CmdCode, int>,
                 ts::strong_typedef_op::equality_comparison<CmdCode> {
    using strong_typedef::strong_typedef;
};

struct Packet {
    CmdCode cmd;
    std::vector<int> params;

    explicit Packet(const cocos2d::network::WebSocket::Data &data) {
        auto pInt = (int *) data.bytes;
        auto size = pInt + data.len / (sizeof(int) / sizeof(char));
        std::vector<int> list{pInt, size};
        cmd = CmdCode(list[0]);
        params = std::vector<int>{pInt + 1, size - 1};
    }

    Packet(const int cmd, std::vector<int> params)
            : cmd(cmd), params(std::move(params)) {}

    [[nodiscard]] std::vector<int> toSocketData() const {
        std::vector<int> list;
        list.push_back(static_cast<int>(cmd));
        list.insert(list.end(), params.begin(), params.end());
        return list;
    }

    explicit operator Object() const {
        Object obj{
                {"cmd",    cmd},
                {"params", params},
        };
    }
};

#endif //WORM_PACKET_H
