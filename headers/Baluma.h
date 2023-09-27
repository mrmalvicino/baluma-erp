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
#include "WarehouseManager.h"

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
     * @brief ClientManager object with default settings.
     */
    ClientManager _client_manager;

    /**
     * @brief SupplierManager object with default settings.
     */
    SupplierManager _supplier_manager;

    /**
     * @brief BudgetManager object with default settings.
     */
    BudgetManager _budget_manager;

    /**
     * @brief ItemManager object with default settings.
     */
    ItemManager _item_manager;

    /**
     * @brief WarehouseManager object with default settings.
     */
    WarehouseManager _warehouse_manager;
};