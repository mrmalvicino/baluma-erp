#include <string>
#include <ctime>

class Date {
    public:
        Date();
        Date(int day, int month, int year);
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        int getDay();
        int getMonth();
        int getYear();
        int getDaysInMonth(int month, int year);
        void addDays(int amount_days);
        std::string toString();

    private:
        int _day;
        int _month;
        int _year;
        void increaseDay();
        void decreaseDay();
};