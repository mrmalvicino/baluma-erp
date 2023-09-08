#include <string>
#include <ctime>

class Time {
    public:
        Time();
        Time(int second, int minute, int hour);
        void setSecond(int second);
        int getSecond();
        void setMinute(int minute);
        int getMinute();
        void setHour(int hour);
        int getHour();
        std::string toString();
        void setCurrentTime();

    private:
        int _second;
        int _minute;
        int _hour;
};