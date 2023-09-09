/**
 * @file ClientCSV.h
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
#include "ClientArchive.h"

class ClientCSV {
    public:

    /**
     * @brief Constructs a new Client CSV object with default settings.
     */
    ClientCSV();

    /**
     * @brief Constructs a new Client CSV object.
     * @param path (std::string) Path where the file will be saved.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    ClientCSV(std::string path, char delimiter);

    /**
     * @brief Sets the Path object.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(std::string path);

    /**
     * @brief Gets the Path object.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath();

    /**
     * @brief Sets the Delimiter object.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    void setDelimiter(char delimiter);

    /**
     * @brief Gets the Delimiter object.
     * @return (char) Character that is used to delimit columns.
     */
    char getDelimiter();

    /**
     * @brief Exports client records to a CSV file.
     * @param client (Client) The client object used to write each register.
     * @param client_archive (ClientArchive) The client archive containing the client records to export.
     */
    void writeClientsCSV(Client & client, ClientArchive & client_archive);

    /**
     * @brief 
     * @param client (Client) The client object used to read each register.
     * @param client_archive (ClientArchive) The client archive where the client records are going to be imported to.
     */
    void readClientsCSV(Client & client, ClientArchive & client_archive);

    private:

    std::string _path; // Path where the file will be saved
    char _delimiter; // Character that is used to delimit columns
    Terminal _terminal; // Terminal object with default settings.
};