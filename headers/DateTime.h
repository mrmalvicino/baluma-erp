#include "Date.h"
#include "Time.h"

class DateTime {
    public:
        DateTime();
        DateTime(Date date, Time time);
        DateTime(int day, int month, int year, int second, int minute, int hour);
        void setDate(Date date);
        Date getDate();
        void setTime(Time time);
        Time getTime();
        void setDate(int day, int month, int year);
        void setTime(int second, int minute, int hour);
        std::string toString();

    private:
        Date _date;
        Time _time;
};