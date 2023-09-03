#include "Date.h"
#include "Time.h"

class DateTime {
    public:
        DateTime();
        DateTime(Date date, Time time);
        DateTime(int day, int month, int year, int second, int minute, int hour);
        void setDate(Date date);
        void setTime(Time time);
        void setDate(int day, int month, int year);
        void setTime(int second, int minute, int hour);
        Date getDate();
        Time getTime();
        std::string toString();

    private:
        Date _date;
        Time _time;
};