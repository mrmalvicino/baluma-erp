/**
 * @file Date.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a date with day, month, and year components.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#include <string>
#include <ctime>

class Date {
    public:

    /**
     * @brief Default constructor that initializes the date to the current date.
     */
    Date();

    /**
     * @brief Constructs a Date object with the specified day, month, and year.
     * @param day (int) The day component of the date.
     * @param month (int) The month component of the date.
     * @param year (int) The year component of the date.
     */
    Date(int day, int month, int year);

    /**
     * @brief Sets the day component of the date.
     * @param day (int) The day value to set.
     */
    void setDay(int day);

    /**
     * @brief Retrieves the day component of the date.
     * @return (int) The day component of the date.
     */
    int getDay();

    /**
     * @brief Sets the month component of the date.
     * @param month (int) The month value to set.
     */
    void setMonth(int month);

    /**
     * @brief Retrieves the month component of the date.
     * @return (int) The month component of the date.
     */
    int getMonth();

    /**
     * @brief Sets the year component of the date.
     * @param year (int) The year value to set.
     */
    void setYear(int year);

    /**
     * @brief Retrieves the year component of the date.
     * @return (int) The year component of the date.
     */
    int getYear();

    /**
     * @brief Adds a specified number of days to the current date.
     * @param amount_days (int) The number of days to add to the date.
     */
    void addDays(int amount_days);

    /**
     * @brief Converts the date into a string representation in the format "DD/MM/YYYY".
     * @return (std::string) The date as a formatted string.
     */
    std::string toString();

    /**
     * @brief Calculates the number of days in a specified month of a given year.
     * @param month (int) The month for which to determine the number of days (1-12, where 1 represents January and 12 represents December).
     * @param year (int) The year for which to determine the number of days.
     * @return (int) Returns the number of days that the specified month of the given year has.
     */
    int getDaysInMonth(int month, int year);

    /**
     * @brief Sets the date to the current date.
     */
    void setCurrentDate();

    private:

    int _day; // The day component of the date.
    int _month; // The month component of the date.
    int _year; // The year component of the date.

    /**
     * @brief Increases the day component of the date by one.
     */
    void increaseDay();

    /**
     * @brief Decreases the day component of the date by one.
     */
    void decreaseDay();
};