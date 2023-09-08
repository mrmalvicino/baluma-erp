#include <string>
#include "Date.h"

class Person {
    public:
        Person();
        Person(std::string first_name, std::string last_name);
        void setFirstName(std::string first_name);
        std::string getFirstName();
        void setLastName(std::string last_name);
        std::string getLastName();
        void setBirthdate(int day, int month, int year);
        Date getBirthdate();

    private:
        char _first_name[30];
        char _last_name[30];
        Date _birthdate;
};