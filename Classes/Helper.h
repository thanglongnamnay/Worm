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
        return string(host) + ":" + to_string(port);
    }

    static vector<string> split(const string &s, char delim = '|') {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

#endif //WORM_HELPER_H
