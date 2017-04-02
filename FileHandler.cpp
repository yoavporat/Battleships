//
// Created by Yoav on 02-04-17.
//

#include <bits/shared_ptr.h>
#include "FileHandler.h"

FileHandler::FileHandler(string path) : dir(path) {
    if (this->debug) {
        cout << "FileHandler C'tor using dir: " << this->dir << endl;
    }

    HANDLE hFind;
    WIN32_FIND_DATA data;

    // search .sboard
    string search_path = this->dir + "\\*.sboard";
    hFind = FindFirstFile(search_path.c_str(), &data);

    if (hFind != INVALID_HANDLE_VALUE) {
        // found .sboard
        search_path = this->dir + "\\" + data.cFileName;
        this->boardFile.open(search_path);
        cout << "found sboard file: " << search_path << endl;
    } else {
        // can't find .sboard file
        cout << "Missing board file (*.sboard) looking in path: " << this->dir << endl;
    }

    // look for player moves files
    search_path = this->dir + "\\*.attack-a";
    //hFind = FindFirstFile(search_path.c_str(), &data);

    if (hFind != INVALID_HANDLE_VALUE) {
        // found .attack-a
        search_path = this->dir + "\\" + data.cFileName;
        ifstream a(search_path);
        
        cout << "found attack-a file: " << search_path << endl;
    } else {
        // can't find .attack-a file
        cout << "Missing attack file for player A (*.attack-a) looking in path: " << this->dir << endl;
    }

}