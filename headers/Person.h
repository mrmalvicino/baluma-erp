#include <string>

class Person{
    public:
        // Construct
        Person();
        Person(std::string first_name, std::string last_name);

        // Public Methods
        void setFirstName(std::string first_name);
        void setLastName(std::string last_name);
        std::string getFirstName();
        std::string getLastName();

    private:
        // Attributes
        std::string _first_name;
        std::string _last_name;
};