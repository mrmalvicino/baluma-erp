#pragma once
#include <iostream>
#include "Terminal.h"
#include "Client.h"
#include "ClientArchive.h"
#include "ClientCSV.h"

class ClientManager {
    public:
        ClientManager();
        void displayMenu();
        bool addClient();
        bool editClient();
        void searchClient();
        void listClients();
        void printClient(int index);
        void cinClientDescription(Client & client);
        void cinClientLegalId(Client & client);
        void cinClientAdress(Client & client);
        void cinClientPhone(Client & client);
        void cinClientEmail(Client & client);
        void cinClientIsActive(Client & client);
        void cinClientCategory(Client & client);
        int generateClientId();
        void searchClientById();
        void searchClientByDescription();
        void exportClientsBackup();
        void importClientsBackup();
        void exportClientsCSV();
        void importClientsCSV();

    private:
        Terminal _terminal;
        Client _client;
        ClientArchive _client_archive;
        ClientArchive _client_archive_backup;
        ClientCSV _client_csv;
};