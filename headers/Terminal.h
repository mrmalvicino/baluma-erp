#pragma once
#include <iostream>

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

    private:
        int _line_lenght;
        char _back_icon[4];
        char _back_caption[30];
};