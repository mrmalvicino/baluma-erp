/**
 * @file Terminal.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Utility class designed to facilitate common text-based interactions in a terminal or console environment. Provides methods for formatting output, validating user input, and creating user-friendly text-based menus.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>

class Terminal {
    public:

    /**
     * @brief Constructs a new Terminal object with default settings.
     */
    Terminal();

    /**
     * @brief Sets the Line Lenght object.
     * @param line_lenght (int) Amount of characters that the class will use to print lines or align headers.
     */
    void setLineLenght(int line_lenght);

    /**
     * @brief Gets the Line Lenght object.
     * @return (int) Amount of characters that the class will use to print lines or align headers.
     */
    int getLineLenght();

    /**
     * @brief Sets the Back Caption object.
     * @param back_caption (std::string) Text that is going to be printed in the option of the menus which the user may choose to go to the previous menu.
     */
    void setBackCaption(std::string back_caption);

    /**
     * @brief Gets the Back Caption object.
     * @return (std::string) Text that is going to be printed in the option of the menus which the user may choose to go to the previous menu.
     */
    std::string getBackCaption();

    /**
     * @brief Clears the terminal using different methods depending on the running operative system.
     */
    void clear();

    /**
     * @brief Pauses the terminal using different methods depending on the running operative system.
     */
    void pause();

    /**
     * @brief Prints a line in the terminal by printing a string of '-' characters.
     */
    void printLine();

    /**
     * @brief Aligns a given text within the terminal window by calculating the number of leading spaces required to center the text in order to print the text surrounded by the necessary spaces.
     * @param text (std::string) The text to be center-aligned and printed.
     */
    void centerAndPrint(std::string text);

    /**
     * @brief Displays a menu item that the user can select to go to the previous menu, according to a preset caption.
     */
    void printBackOption();

    /**
     * @brief Creates a visual header for a menu in a text-based user interface.
     * @param title (std::string) The title to be displayed as the menu header.
     */
    void displayMenuHeader(std::string title);

    /**
     * @brief Creates a visual footer for a menu in a text-based user interface which contains a back option.
     */
    void displayMenuFooter();

    /**
     * @brief Prints text based on the value of a boolean parameter. Prints one of two possible strings depending on whether the boolean parameter is true or false.
     * @param parameter (bool) Boolean condition whose value determines the output message.
     * @param text_if_true (std::string) Text to be printed if the parameter is true.
     * @param text_if_false (std::string) Text to be printed if the parameter is false.
     */
    void printBool(bool parameter, std::string text_if_true, std::string text_if_false);

    /**
     * @brief Requests and validates a boolean input from the user interactively. Expects the user to enter either 'Y' or 'S' to represent true or 'N' to represent false (case-insensitive). Ensures that the user input is a valid boolean representation.
     * @return (bool) Returns the boolean value entered by the user.
     */
    bool validateBool();

    /**
     * @brief Requests and validates an integer input from the user interactively. Ensures that the entered value is an integer.
     * @return (int) Returns the integer value entered by the user.
     */
    int validateInt();

    /**
     * @brief Requests and validates an integer input from the user interactively. Ensures that the entered value is an integer and that it is greater than or equal to a given minimum.
     * @param min (int) The minimum allowable integer value (inclusive) that the user can input.
     * @return (int) Returns an integer value entered by the user that is greater than or equal to the specified minimum value.
     */
    int validateInt(int min);

    /**
     * @brief Requests and validates an integer input from the user interactively. Ensures that the entered value is both an integer and falls within the given minimum and maximum boundaries.
     * @param min (int) The minimum allowable integer value (inclusive) that the user can input.
     * @param max (int) The maximum allowable integer value (inclusive) that the user can input.
     * @return (int) Returns an integer value entered by the user that falls within the specified range [min, max].
     */
    int validateInt(int min, int max);

    /**
     * @brief Requests and validates a long integer input from the user interactively. Ensures that the entered value is a long integer.
     * @return (long long int) Returns the long integer value entered by the user.
     */
    long long int validateLongInt();

    /**
     * @brief Requests and validates a long integer input from the user interactively. Ensures that the entered value is a long integer and that it is greater than or equal to a given minimum.
     * @param min (int) The minimum allowable integer value (inclusive) that the user can input.
     * @return (long long int) Returns a long integer value entered by the user that is greater than or equal to the specified minimum value.
     */
    long long int validateLongInt(int min);

    /**
     * @brief Requests and validates a long integer input from the user interactively. Ensures that the entered value is both a long integer and falls within the given minimum and maximum boundaries.
     * @param min (int) The minimum allowable integer value (inclusive) that the user can input.
     * @param max (int) The maximum allowable integer value (inclusive) that the user can input.
     * @return (long long int) Returns a long integer value entered by the user that falls within the specified range [min, max].
     */
    long long int validateLongInt(int min, int max);

    /**
     * @brief Requests and validates a character input from the user. Ensures that the entered value is a character.
     * @return (char) Returns the character value entered by the user.
     */
    char validateChar();

    /**
     * @brief Configures terminal encoding to UTF-8.
     */
    void configureUTF8();

    /**
     * Clears the input buffer by discarding characters until a newline ('\n') character is encountered or the buffer is empty.
     */
    void cleanBuffer();

    private:

    /**
     * @brief Amount of characters that the class will use to print lines or align headers.
     */
    int _line_lenght;

    /**
     * @brief Text that is going to be printed in the option of the menus which the user may choose to go to the previous menu.
     */
    char _back_caption[30];
};