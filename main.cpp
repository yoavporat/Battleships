//
// Created by Yoav on 02-04-17.
//

#include <iostream>
#include <string>
#include <windows.h>

#include "FileHandler.h"

using namespace std;

bool debug = true;

int main(int argc, char *argv[]) {
    string path;

    if (debug) {
        cout << "debug is ON" << endl << "main started" << endl;
    }

    if (argc == 1) {
        // use CWD
        path = FileHandler::getCwd();
    } else {
        // use given path
        path = argv[1];
    }

    if (debug) {
        cout << "using path: " << path << endl;
    }

    FileHandler fh(path);
    cout << "valid? " << fh.valid << endl;
    /* read from ifstream
    if (fh.bMoves.is_open()) {
        string line;
        while (getline(fh.bMoves,line) ) {
            cout << line << endl;
        }
    }
    */


    return 0;

}