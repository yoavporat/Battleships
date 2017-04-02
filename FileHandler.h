//
// Created by Yoav on 02-04-17.
//

#ifndef PROJECT_FILEHANDLER_H
#define PROJECT_FILEHANDLER_H

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

using namespace std;

class FileHandler {
    bool debug = true;
    string dir;

public:
    ifstream boardFile;
    vector<ifstream> playerMoves;

    FileHandler(string path);
};

#endif //PROJECT_FILEHANDLER_H
