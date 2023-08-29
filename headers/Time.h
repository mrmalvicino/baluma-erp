#include <string>
#include <ctime>

class Time{
    public:
        // Construct
        Time();
        Time(int second, int minute, int hour);

        // Public Methods
        void setSecond(int second);
        void setMinute(int minute);
        void setHour(int hour);
        int getSecond();
        int getMinute();
        int getHour();
        std::string toString();

    private:
        // Attributes
        int _second;
        int _minute;
        int _hour;
};