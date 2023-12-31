/**
 * @file Adress.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents an address with various components such as country, state, city, street, street number, apartment floor, and apartment letter.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <string>
#include <cstring>

class Adress {
    public:

    /**
     * @brief Constructs a new Adress object with default settings.
     */
    Adress();

    /**
     * @brief Constructs a new Adress object.
     * @param country (std::string) The country of the address.
     * @param state (std::string) The state or region of the address.
     * @param city (std::string) The city of the address.
     * @param street (std::string) The street name of the address.
     * @param number (int) The street number of the address.
     * @param floor (int) The floor number (if applicable) of the address.
     * @param letter (char) The letter (if applicable) of the address.
     */
    Adress(std::string country, std::string state, std::string city, std::string street, int number, int floor, char letter);

    /**
     * @brief Sets the Country object.
     * @param country (std::string) The country of the address.
     */
    void setCountry(std::string country);

    /**
     * @brief Gets the Country object.
     * @return (std::string) The country of the address.
     */
    std::string getCountry();

    /**
     * @brief Sets the State object.
     * @param state (std::string) The state or region of the address.
     */
    void setState(std::string state);

    /**
     * @brief Gets the State object.
     * @return (std::string) The state or region of the address.
     */
    std::string getState();

    /**
     * @brief Sets the City object.
     * @param city (std::string) The city of the address.
     */
    void setCity(std::string city);

    /**
     * @brief Gets the City object.
     * @return (std::string) The city of the address.
     */
    std::string getCity();

    /**
     * @brief Sets the Street Name object.
     * @param street (std::string) The street name of the address.
     */
    void setStreet(std::string street);

    /**
     * @brief Gets the Street Name object.
     * @return (std::string) The street name of the address.
     */
    std::string getStreet();

    /**
     * @brief Sets the Street Number object.
     * @param number (int) The street number of the address.
     */
    void setNumber(int number);

    /**
     * @brief Gets the Street Number object.
     * @return (int) The street number of the address.
     */
    int getNumber();

    /**
     * @brief Sets the Apartment Floor object.
     * @param floor (int) The floor number (if applicable) of the address.
     */
    void setFloor(int floor);

    /**
     * @brief Gets the Apartment Floor object.
     * @return (int) The floor number (if applicable) of the address.
     */
    int getFloor();

    /**
     * @brief Sets the Apartment Letter object.
     * @param letter (char) The letter (if applicable) of the address.
     */
    void setLetter(char letter);

    /**
     * @brief Gets the Apartment Letter object.
     * @return (char) The letter (if applicable) of the address.
     */
    char getLetter();

    private:

    /**
     * @brief Country name.
     */
    char _country[30];

    /**
     * @brief State or region name.
     */
    char _state[30];

    /**
     * @brief City name.
     */
    char _city[30];

    /**
     * @brief Street name.
     */
    char _street[30];

    /**
     * @brief Street number.
     */
    int _number;

    /**
     * @brief Floor number (if applicable).
     */
    int _floor;

    /**
     * @brief Letter of apartment (if applicable).
     */
    char _letter;
};