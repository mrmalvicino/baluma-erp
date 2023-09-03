#pragma once
#include "Terminal.h"
#include "ClientManager.h"

class Baluma {
    public:
        void run();
        void about();
    
    private:
        Terminal _terminal;
        ClientManager _client_manager;
};