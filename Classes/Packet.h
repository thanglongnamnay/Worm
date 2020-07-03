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

class Params {
	vector<string>::iterator p;
	vector<string> params;
public:
	Params(vector<string> params) : params(params), p(params.begin()) {}
	int getInt() {
		if (p == params.end()) p = params.begin();
		return stoi(*p++);
	}
	bool getBool() {
		if (p == params.end()) p = params.begin();
		return *p++ == "1";
	}
	string getString() {
		if (p == params.end()) p = params.begin();
		return *p++;
	}
};

struct Packet {
    constexpr const static char delim[] = "|";
    int cmd = 0;
    vector<string> params;

    explicit Packet(const cocos2d::network::WebSocket::Data &data) {
        string msg = string(data.bytes, data.len);
        params = Helper::split(msg, '|');
        cmd = stoi(params[0]);
        params.erase(params.begin());
    }

    Packet(const int cmd, vector<string> params)
            : cmd(cmd), params(move(params)) {}

    [[nodiscard]] string toSocketData() const {
        string msg{to_string(cmd)};
        for (const auto& param : params) msg += delim + param;
        return msg;
    }

    explicit operator Object() const {
        Object obj{
                {"cmd",    cmd},
                {"params", Params{params}},
        };
        return obj;
    }
};

#endif //WORM_PACKET_H
