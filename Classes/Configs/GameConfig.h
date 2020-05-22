//
// Created by long on 20/05/2020.
//

#ifndef WORM_GAMECONFIG_H
#define WORM_GAMECONFIG_H

struct NetWorkConfig {
    char serverAddr[50] = "127.0.0.1";
    int serverPort = 8000;
};

struct GameConfig {
    NetWorkConfig netWorkConfig;
};

#endif //WORM_GAMECONFIG_H
