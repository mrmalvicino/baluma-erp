#pragma once
#include <iostream>
#include "Terminal.h"
#include "Client.h"
#include "ClientArchive.h"

class ClientManager {
    public:
        void displayMenu();
        bool addClient();
        bool editClient();
        void deleteClient();
        void searchClient();
        void listClients();
        void printClient(int index);
        void getUserInputForDescription(Client & client);
        void getUserInputForLegalId(Client & client);
        void getUserInputForAdress(Client & client);
        void getUserInputForPhone(Client & client);
        void getUserInputForEmail(Client & client);

    private:
        Terminal _terminal;
        Client _client;
        ClientArchive _client_archive;
};