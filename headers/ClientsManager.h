/**
 * @file ClientsManager.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the client module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include "Terminal.h"
#include "Client.h"
#include "ClientsArchive.h"
#include "ClientsCSV.h"

class ClientsManager {
    public:

    /**
     * @brief Constructs a new ClientsManager object with default settings.
     */
    ClientsManager();

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
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchClient();

    /**
     * @brief Searches for a client by their unique ID and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchClientById();

    /**
     * @brief Searches for a client by their name and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchClientByDescription();

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
     * @brief Exports a binary file with a buckup copy of the current _clients_archive.
     */
    void exportClientsBackup();

    /**
     * @brief Imports a buckup copy by overwriting the current _clients_archive.
     */
    void importClientsBackup();

    /**
     * @brief Exports a CSV file with the current _clients_archive.
     */
    void exportClientsCSV();

    /**
     * @brief Imports a CSV file by overwriting the current _clients_archive.
     */
    void importClientsCSV();

    private:

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;

    /**
     * @brief Client object with default settings.
     */
    Client _client;

    /**
     * @brief ClientsArchive object with default path.
     */
    ClientsArchive _clients_archive;

    /**
     * @brief ClientsArchive object with custom path.
     */
    ClientsArchive _clients_backup;

    /**
     * @brief ClientsCSV object with default settings.
     */
    ClientsCSV _clients_csv;
};