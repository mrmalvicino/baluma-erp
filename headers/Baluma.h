/**
 * @file Baluma.h
 * @authors Franco Baez, Lucio Luque, Maximiliano Raúl Malvicino
 * @brief Generic enterprise resource planning software.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Terminal.h"
#include "ClientsManager.h"
#include "SuppliersManager.h"
#include "InventoryManager.h"
#include "WarehousesManager.h"
#include "AccountsManager.h"

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

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;

    /**
     * @brief ClientsManager object with default settings.
     */
    ClientsManager _clients_manager;

    /**
     * @brief SuppliersManager object with default settings.
     */
    SuppliersManager _suppliers_manager;

    /**
     * @brief InventoryManager object with default settings.
     */
    InventoryManager _inventory_manager;
};