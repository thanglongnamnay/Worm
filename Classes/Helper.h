//
// Created by long on 20/05/2020.
//

#ifndef WORM_HELPER_H
#define WORM_HELPER_H

#include <string>

using namespace std;

class Helper {
public:
    static string getSocketAddr(char host[], int port) {
      return string(host)+":"+to_string(port);
    }
};

#endif //WORM_HELPER_H
