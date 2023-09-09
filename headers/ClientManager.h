/**
 * @file ClientManager.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the client module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include "Terminal.h"
#include "Client.h"
#include "ClientArchive.h"
#include "ClientCSV.h"

class ClientManager {
    public:

    /**
     * @brief Constructs a new Client Manager object with default settings.
     */
    ClientManager();

    /**
     * @brief Displays the clients menu.
     */
    void displayMenu();

    /**
     * @brief Adds a new client to the client archive by prompting the user for inputs to collect various details of the client, such as description, legal ID, address, phone, email, and category.
     * @return (bool) Returns true if the new client record is successfully added and otherwise, returns false.
     */
    bool addClient();

    /**
     * @brief Allows editing an existing client's details interactively.
     * @return (bool) Returns true if the new client record is successfully edited and otherwise, returns false.
     */
    bool editClient();

    /**
     * @brief Allows searching for a client with an interactive menu based on different criteria, including client ID and client name.
     */
    void searchClient();

    /**
     * @brief Displays a list of all clients stored in the client archive.
     */
    void listClients();

    /**
     * @brief Prints detailed information about a client for a given index in the archive.
     * @param index (int) The index of the client record to print.
     */
    void printClient(int index);

    /**
     * @brief Prompts the user to enter the name of a client.
     * @param client (Client &) A reference to the Client object where the data will be stored.
     */
    void cinClientDescription(Client & client);

    /**
     * @brief Prompts the user to enter the ID card number of a client.
     * @param client (Client &) A reference to the Client object where the data will be stored.
     */
    void cinClientLegalId(Client & client);

    /**
     * @brief Prompts the user to enter the adress of a client.
     * @param client (Client &) A reference to the Client object where the data will be stored.
     */
    void cinClientAdress(Client & client);

    /**
     * @brief Prompts the user to enter the phone of a client.
     * @param client (Client &) A reference to the Client object where the data will be stored.
     */
    void cinClientPhone(Client & client);

    /**
     * @brief Prompts the user to enter the email of a client.
     * @param client (Client &) A reference to the Client object where the data will be stored.
     */
    void cinClientEmail(Client & client);

    /**
     * @brief Prompts the user to enter the status of a client.
     * @param client (Client &) A reference to the Client object where the data will be stored.
     */
    void cinClientIsActive(Client & client);

    /**
     * @brief Prompts the user to enter the category of a client.
     * @param client (Client &) A reference to the Client object where the data will be stored.
     */
    void cinClientCategory(Client & client);

    /**
     * @brief Generates a unique client ID based on the current number of client records.
     * @return (int) The generated unique client ID.
     */
    int generateClientId();

    /**
     * @brief Searches for a client by their unique ID and displays their details.
     */
    void searchClientById();

    /**
     * @brief Searches for a client by their name and displays their details.
     */
    void searchClientByDescription();

    /**
     * @brief Exports a binary file with a buckup copy of the current archive of clients.
     */
    void exportClientsBackup();

    /**
     * @brief Imports a buckup copy by overwriting the current archive of clients.
     */
    void importClientsBackup();

    /**
     * @brief Exports a CSV file with the current archive of clients.
     */
    void exportClientsCSV();

    /**
     * @brief Imports a CSV file by overwriting the current archive of clients.
     */
    void importClientsCSV();

    private:

    Terminal _terminal; // Terminal object with default settings.
    Client _client; // Client object with default settings.
    ClientArchive _client_archive; // Client Archive object with default path.
    ClientArchive _client_backup; // Client Archive object with custom path.
    ClientCSV _client_csv; // Client CSV object with default settings.
};