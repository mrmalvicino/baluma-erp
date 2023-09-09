/**
 * @file DateTime.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a combined date and time object.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#include "Date.h"
#include "Time.h"

class DateTime {
    public:

    /**
     * @brief Constructs a DateTime object with default values.
     */
    DateTime();

    /**
     * @brief Constructs a DateTime object with a given date and time.
     * @param date (Date) The date component of the DateTime.
     * @param time (Time) The time component of the DateTime.
     */
    DateTime(Date date, Time time);

    /**
     * @brief Constructs a DateTime object with specific date and time values.
     * @param day (int) The day component of the date.
     * @param month (int) The month component of the date.
     * @param year (int) The year component of the date.
     * @param second (int) The second component of the time.
     * @param minute (int) The minute component of the time.
     * @param hour (int) The hour component of the time.
     */
    DateTime(int day, int month, int year, int second, int minute, int hour);

    /**
     * @brief Sets the date component of the DateTime.
     * @param date (Date) The new date to set.
     */
    void setDate(Date date);

    /**
     * @brief Gets the date component of the DateTime.
     * @return (Date) The date component of the DateTime.
     */
    Date getDate();

    /**
     * @brief Sets the time component of the DateTime.
     * @param time (Time) The new time to set.
     */
    void setTime(Time time);

    /**
     * @brief Gets the time component of the DateTime.
     * @return (Time) The time component of the DateTime.
     */
    Time getTime();

    /**
     * @brief Sets both date and time components of the DateTime.
     * @param day (int) The day component of the date.
     * @param month (int) The month component of the date.
     * @param year (int) The year component of the date.
     */
    void setDate(int day, int month, int year);

    /**
     * @brief Sets the time components of the DateTime.
     * @param second (int) The second component of the time.
     * @param minute (int) The minute component of the time.
     * @param hour (int) The hour component of the time.
     */
    void setTime(int second, int minute, int hour);

    /**
     * @brief Converts the DateTime object to a string representation.
     * @return (std::string) A string representation of the DateTime object.
     */
    std::string toString();

    private:

    Date _date; // The date component of the DateTime
    Time _time; // The time component of the DateTime
};