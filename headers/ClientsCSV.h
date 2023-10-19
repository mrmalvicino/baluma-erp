/**
 * @file ClientsCSV.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages a client archive file, allowing storage and retrieval of client records in a CSV file.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Client.h"
#include "ClientsArchive.h"

class ClientsCSV {
    public:

    /**
     * @brief Constructs a new ClientsCSV object with default settings.
     */
    ClientsCSV();

    /**
     * @brief Constructs a new ClientsCSV object.
     * @param path (std::string) Path where the file will be saved.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    ClientsCSV(std::string path, char delimiter);

    /**
     * @brief Sets the _path attribute.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(std::string path);

    /**
     * @brief Gets the _path attribute.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath();

    /**
     * @brief Sets the _delimiter attribute.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    void setDelimiter(char delimiter);

    /**
     * @brief Gets the _delimiter attribute.
     * @return (char) Character that is used to delimit columns.
     */
    char getDelimiter();

    /**
     * @brief Exports client records to a CSV file.
     * @param client (Client) The client object used to write each register.
     * @param clients_archive (ClientsArchive) The _clients_archive containing the client records to export.
     */
    void writeClientsCSV(Client & client, ClientsArchive & clients_archive);

    /**
     * @brief Imports client records from a CSV file.
     * @param client (Client) The client object used to read each register.
     * @param clients_archive (ClientsArchive) The _clients_archive where the client records are going to be imported to.
     */
    void readClientsCSV(Client & client, ClientsArchive & clients_archive);

    private:

    /**
     * @brief Path where the file will be saved.
     */
    std::string _path;

    /**
     * @brief Character that is used to delimit columns.
     */
    char _delimiter;

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;
};