#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Client.h"
#include "ClientArchive.h"

class ClientCSV {
    public:
        ClientCSV();
        ClientCSV(std::string path, char delimiter);
        void setPath(std::string path);
        std::string getPath();
        void setDelimiter(char delimiter);
        char getDelimiter();
        void writeClientsCSV(Client & client, ClientArchive & client_archive);
        void readClientsCSV(Client & client, ClientArchive & client_archive);

    private:
        char _delimiter;
        std::string _path;
        Terminal _terminal;
};