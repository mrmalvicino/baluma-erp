#include <iostream>

class Terminal {
    public:
        /**
         * @brief Clears the terminal using different methods depending on the running operative system.
         */
        void clear();

        /**
         * @brief Pauses the terminal using different methods depending on the running operative system.
         */
        void pause();
};