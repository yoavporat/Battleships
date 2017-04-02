//
// Created by Yoav on 02-04-17.
//

#include "FileHandler.h"

/* C'tor
 * search for sboard, attack-a and attack-b files at the working directory
 * assign the first match of each file type to the relevant field
 * sets valid=true iff all the file type exists at the working directory
 * otherwise, sets valid=false and print errors
 * */
FileHandler::FileHandler(string path) : dir(path) {
    if (this->debug) {
        cout << "FileHandler C'tor using dir: " << this->dir << endl;
    }

    HANDLE hFind;
    WIN32_FIND_DATA data;
    stringstream errors;

    // search .sboard
    string search_path = this->dir + "\\*.sboard";
    hFind = FindFirstFile(search_path.c_str(), &data);

    if (hFind != INVALID_HANDLE_VALUE) {
        // found .sboard
        search_path = this->dir + "\\" + data.cFileName;
        this->boardFile.open(search_path);

        if (this->debug) {
            cout << "found sboard file: " << search_path << endl;
        }

    } else {
        // can't find .sboard file
        errors << "Missing board file (*.sboard) looking in path: " << this->dir << '\n';
    }

    // look for player A moves file
    search_path = this->dir + "\\*.attack-a";
    hFind = FindFirstFile(search_path.c_str(), &data);

    if (hFind != INVALID_HANDLE_VALUE) {
        // found .attack-a
        search_path = this->dir + "\\" + data.cFileName;
        this->aMoves.open(search_path);

        if (this->debug) {
            cout << "found attack-a file: " << search_path << endl;
        }

    } else {
        // can't find .attack-a file
        errors << "Missing attack file for player A (*.attack-a) looking in path: " << this->dir << '\n';
    }

    // look for player A moves file
    search_path = this->dir + "\\*.attack-b";
    hFind = FindFirstFile(search_path.c_str(), &data);

    if (hFind != INVALID_HANDLE_VALUE) {
        // found .attack-b
        search_path = this->dir + "\\" + data.cFileName;
        this->bMoves.open(search_path);

        if (this->debug) {
            cout << "found attack-a file: " << search_path << endl;
        }

    } else {
        // can't find .attack-a file
        errors << "Missing attack file for player B (*.attack-b) looking in path: " << this->dir << '\n';
    }

    // validate
    if (errors.str().size() > 0) {
        cout << errors.str() << endl;
    } else {
        this->valid = true;
    }
}

/*
 * based on http://stackoverflow.com/questions/875249/how-to-get-current-directory snippet
 * returns the CWD as a string
 * */
string FileHandler::getCwd() {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    string::size_type pos = string(buffer).find_last_of("\\/");
    return string(buffer).substr(0, pos);
}