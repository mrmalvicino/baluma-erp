/**
 * @file Baluma.h
 * @authors Franco Baez, Lucio Luque, Maximiliano Raúl Malvicino
 * @brief Generic enterprise resource planning software.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Terminal.h"
#include "ClientManager.h"
#include "SupplierManager.h"
#include "BudgetManager.h"
#include "ItemManager.h"

class Baluma {
    public:

    /**
     * @brief Displays the main menu of the program.
     */
    void run();

    /**
     * @brief Prints information about the software.
     */
    void about();
    
    private:

    Terminal _terminal; // Terminal object with default settings.
    ClientManager _client_manager; // Client Manager object with default settings.
    SupplierManager _supplier_manager; // Supplier Manager object with default settings.
};