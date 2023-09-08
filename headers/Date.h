#include <string>
#include <ctime>

class Date {
    public:
        Date();
        Date(int day, int month, int year);
        void setDay(int day);
        int getDay();
        void setMonth(int month);
        int getMonth();
        void setYear(int year);
        int getYear();
        void addDays(int amount_days);
        std::string toString();
        int getDaysInMonth(int month, int year);
        void setCurrentDate();

    private:
        int _day;
        int _month;
        int _year;
        void increaseDay();
        void decreaseDay();
};