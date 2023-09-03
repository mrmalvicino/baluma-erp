#include <string>
#include <cstring>

class Adress {
    public:
        Adress();
        Adress(std::string country, std::string state, std::string city, std::string street, int number, int floor, char letter);
        void setCountry(std::string country);
        void setState(std::string state);
        void setCity(std::string city);
        void setStreet(std::string street);
        void setNumber(int number);
        void setFloor(int floor);
        void setLetter(char letter);
        std::string getCountry();
        std::string getState();
        std::string getCity();
        std::string getStreet();
        int getNumber();
        int getFloor();
        char getLetter();

    private:
        char _country[30];
        char _state[30];
        char _city[30];
        char _street[30];
        int _number;
        int _floor;
        char _letter;
};