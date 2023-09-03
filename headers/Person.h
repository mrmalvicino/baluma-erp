#include <string>

class Person {
    public:
        Person();
        Person(std::string first_name, std::string last_name);

        void setFirstName(std::string first_name);
        void setLastName(std::string last_name);
        std::string getFirstName();
        std::string getLastName();

    private:
        std::string _first_name;
        std::string _last_name;
};