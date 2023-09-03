#pragma once
#include <iostream>
#include "Terminal.h"
#include "Client.h"
#include "ClientArchive.h"

class ClientManager {
    public:
        void openClientMenu();
        bool addClient();
        //bool editClient();
        //Client searchClient();
        void listClients();
        // Agregar métodos de escritura por parámetro

    private:
        Terminal _terminal;
        Client _client;
        ClientArchive _client_archive;
};