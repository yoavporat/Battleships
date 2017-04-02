//
// Created by Yoav on 02-04-17.
//

#include <iostream>
#include <string>
#include <windows.h>

#include "FileHandler.h"

using namespace std;
string getCwd();
bool debug = true;

int main(int argc, char *argv[]) {
    string path;

    if (debug) {
        cout << "debug is ON" << endl << "main started" << endl;
    }

    if (argc == 1) {
        // use CWD
        path = getCwd();
    } else {
        // use given path
        path = argv[1];
    }

    if (debug) {
        cout << "using path: " << path << endl;
    }

    FileHandler fh(path);

    if (fh.boardFile.is_open()) {
        string line;
        while (getline(fh.boardFile,line) ) {
            cout << line << endl;
        }
    }


    return 0;

}

string getCwd() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}