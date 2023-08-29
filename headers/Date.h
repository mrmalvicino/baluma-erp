#include <string>
#include <ctime>

class Date{
    public:
        // Construct
        Date();
        Date(int day, int month, int year);

        // Public Methods
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
        // Attributes
        int _day;
        int _month;
        int _year;

        // Private Methods
        void increaseDay();
        void decreaseDay();
};