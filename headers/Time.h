/**
 * @file Time.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a time of day with hours, minutes, and seconds.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#include <string>
#include <ctime>

class Time {
    public:

    /**
     * @brief Default constructor that sets the time to the current time.
     */
    Time();

    /**
     * @brief Constructs a Time object with the specified seconds, minutes, and hours.
     * @param second (int) The second component of the time.
     * @param minute (int) The minute component of the time.
     * @param hour (int) The hour component of the time.
     */
    Time(int second, int minute, int hour);

    /**
     * @brief Sets the second component of the time.
     * @param second (int) The second value to set.
     */
    void setSecond(int second);

    /**
     * @brief Retrieves the second component of the time.
     * @return (int) The second component of the time.
     */
    int getSecond();

    /**
     * @brief Sets the minute component of the time.
     * @param minute (int) The minute value to set.
     */
    void setMinute(int minute);

    /**
     * @brief Retrieves the minute component of the time.
     * @return (int) The minute component of the time.
     */
    int getMinute();

    /**
     * @brief Sets the hour component of the time.
     * @param hour (int) The hour value to set.
     */
    void setHour(int hour);

    /**
     * @brief Retrieves the hour component of the time.
     * @return (int) The hour component of the time.
     */
    int getHour();

    /**
     * @brief Converts the time into a string representation in the format "HH:MM:SS".
     * @return (std::string) The time as a formatted string.
     */
    std::string toString();

    /**
     * @brief Sets the time to the current time.
     */
    void setCurrentTime();

    private:

    int _second; // The second component of the time.
    int _minute; // The minute component of the time.
    int _hour; // The hour component of the time.
};