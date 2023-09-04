#pragma once
#include "Terminal.h"
#include "ClientManager.h"
#include "SupplierManager.h"

class Baluma {
    public:
        void run();
        void about();
    
    private:
        Terminal _terminal;
        ClientManager _client_manager;
        SupplierManager _supplier_manager;
};