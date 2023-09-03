#include <string>
#include <ctime>

class Time {
    public:
        Time();
        Time(int second, int minute, int hour);

        void setSecond(int second);
        void setMinute(int minute);
        void setHour(int hour);
        int getSecond();
        int getMinute();
        int getHour();
        std::string toString();

    private:
        int _second;
        int _minute;
        int _hour;
};