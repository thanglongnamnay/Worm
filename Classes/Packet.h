//
// Created by long on 30/05/2020.
//

#ifndef WORM_PACKET_H
#define WORM_PACKET_H

#include <vector>
#include "network/WebSocket.h"
#include "cocos2d.h"

struct Packet {
    int cmd;
    std::vector<int> params;
    explicit Packet(const cocos2d::network::WebSocket::Data& data) {
      auto pInt = (int*)data.bytes;
      auto size = pInt+data.len/(sizeof(int)/sizeof(char));
      std::vector<int> list{pInt, size};
      cmd = list[0];
      params = std::vector<int>{pInt+1, size-1};
    }
    Packet(const int cmd, std::vector<int> params)
        :cmd(cmd), params(std::move(params)) { }
    std::vector<int> toSocketData() const {
      std::vector<int> list;
      list.push_back(cmd);
      list.insert(list.end(), params.begin(), params.end());
      return list;
    }
};

#endif //WORM_PACKET_H
