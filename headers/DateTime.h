#include "Date.h"
#include "Time.h"

class DateTime{
    public:
        // Construct
        DateTime();
        DateTime(Date date, Time time);
        DateTime(int day, int month, int year, int second, int minute, int hour);

        // Public Methods
        void setDate(Date date);
        void setTime(Time time);
        void setDate(int day, int month, int year);
        void setTime(int second, int minute, int hour);
        Date getDate();
        Time getTime();
        std::string toString();

    private:
        // Attributes
        Date _date;
        Time _time;
};