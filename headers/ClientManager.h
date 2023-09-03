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
        // Corregir tipo de dato legal_id de clientes y proevdores

    private:
        Terminal _terminal;
        Client _client;
        ClientArchive _client_archive;
};