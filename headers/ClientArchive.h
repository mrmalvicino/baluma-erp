#pragma once
#include <cstdio>
#include "Client.h"

class ClientArchive {
    public:
        ClientArchive();
        ClientArchive(std::string path);
        void setPath(std::string path);
        std::string getPath();
        bool write(Client & reg);
        bool overWrite(Client & reg, int index);
        Client read(int index);
        int getIndex(int id);
        int getIndex(std::string description);
        int getAmountOfRegisters();
        void createNewEmptyFile();

    private:
        std::string _path;
};