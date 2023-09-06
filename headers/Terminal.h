#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits>

class Terminal {
    public:
        Terminal();
        void setLineLenght(int line_lenght);
        int getLineLenght();
        void setBackCaption(std::string back_caption);
        std::string getBackCaption();
        void setBackIcon(std::string back_icon);
        std::string getBackIcon();

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

        void centerAndPrint(std::string text);

        void printBackOption();

        void displayMenuHeader(std::string title);

        void displayMenuFooter();

        void printBool(bool parameter, std::string text_if_true, std::string text_if_false);

        bool validateBool();

        int validateInt();

        int validateInt(int min);

        int validateInt(int min, int max);

        long long int validateLongInt();

        long long int validateLongInt(int min);

        long long int validateLongInt(int min, int max);

        char validateChar();

    private:
        int _line_lenght;
        char _back_caption[30];
};