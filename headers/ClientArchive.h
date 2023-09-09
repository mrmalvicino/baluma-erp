#pragma once
#include <cstdio>
#include "Client.h"

class ClientArchive {
    public:

    /**
     * @brief Constructs a new Client Archive object with default path.
     */
    ClientArchive();

    /**
     * @brief Constructs a new Client Archive object.
     * @param path (std::string) Path where the file will be saved.
     */
    ClientArchive(std::string path);

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
     * @brief Writes a client record to the archive file.
     * @param reg (Client) The client record to be written to the archive.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary append mode ("ab") to ensure that new records are appended to the end of the file without overwriting existing data. If the file cannot be opened, an error message is printed to standard error.
     */
    bool write(Client & reg);

    /**
     * @brief Overwrites a client record at the specified index in the archive file.
     * @param reg (Client) The new client record that will overwrite the existing record.
     * @param index (int) The index of the record to be overwritten.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary read-write mode ("rb+") to allow modification of existing records without affecting other parts of the file. If the file cannot be opened, an error message is printed to standard error.
     */
    bool overWrite(Client & reg, int index);

    /**
     * @brief Reads a client record from the archive file at a given index.
     * @param index (int) The index of the record to be read.
     * @return (Client) Returns a client record read from the archive file.
     * @note The file is opened in binary read mode ("rb"). An empty client wil be returned if there is a reading error or if the specified index is out of bounds.
     */
    Client read(int index);

    /**
     * @brief Finds the index of a client record with a given ID.
     * @param id (int) The ID of the client record to search for.
     * @return (int) The index of the matching client record.
     */
    int getIndex(int id);

    /**
     * @brief Finds the index of a client record with a given description.
     * @param description (std::string) The description of the client record to search for.
     * @return (int) The index of the matching client record.
     */
    int getIndex(std::string & description);

    /**
     * @brief Retrieves the total number of client records stored in the archive file.
     * @return (int) Amount of client records stored in the archive file.
     * @note Calculates the number of records by dividing the file's size by the size of each client record.
     */
    int getAmountOfRegisters();

    /**
     * @brief Creates an empty client archive file.
     * @warning The method does not check if the file already exists; it will create a new empty file or overwrite an existing one.
     */
    void createEmptyClientArchive();

    private:

    std::string _path; // Path where the file will be saved
};