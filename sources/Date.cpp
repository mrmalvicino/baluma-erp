#include "../headers/Date.h"

// Construct

Date::Date(){
    std::time_t now = std::time(NULL);
    std::tm * local_time = std::localtime(& now);
    _day = (* local_time).tm_mday;
    _month = (* local_time).tm_mon + 1;
    _year = (* local_time).tm_year + 1900;
}

Date::Date(int day, int month, int year){
    if(0 < day && day <= getDaysInMonth(month, year) && 0 < month && month <= 12 && 0 < year){
        _day = day;
        _month = month;
        _year = year;
    }
}

// Public Methods

void Date::setDay(int day){
    if(0 < day && day <= 31){
        _day = day;
    }
}

void Date::setMonth(int month){
    if(0 < month && month <= 12){
        _month = month;
    }
}

void Date::setYear(int year){
    if(0 < year){
        _year = year;
    }
}

int Date::getDay(){
    return _day;
}

int Date::getMonth(){
    return _month;
}

int Date::getYear(){
    return _year;
}

void Date::addDays(int amount_days){
    if(0 < amount_days){
        for(int i = 0; i < amount_days; i++){
            increaseDay();
        }
    } else if (amount_days < 0){
        for(int i = 0; i < - amount_days; i++){
            decreaseDay();
        }
    }
}

std::string Date::toString(){
    std::string dd;
    std::string mm;
    std::string yyyy = std::to_string(_year);

    if(_day < 10){
        dd = "0" + std::to_string(_day);
    } else{
        dd = std::to_string(_day);
    }

    if(_month < 10){
        mm = "0" + std::to_string(_month);
    } else{
        mm = std::to_string(_month);
    }

    return dd + "/" + mm + "/" + yyyy;
}

int Date::getDaysInMonth(int month, int year){
    int amount_days = 31; // Enero, marzo, mayo, julio, agosto, octubre, diciembre

    if (month == 4 || month == 6 || month == 9 || month == 11){
        amount_days = 30; // Abril, junio, septiembre, noviembre
    } else if (month == 2){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            amount_days = 29; // Febrero en años bisiestos
        } else {
            amount_days = 28; // Febrero en años no bisiestos
        }
    }

    return amount_days;
}

// Private Methods

void Date::increaseDay(){
    if(_day == getDaysInMonth(_month, _year)){
        _day = 1;

        if(_month == 12){
            _month = 1;
            _year ++;
        } else{
            _month ++;
        }
    } else{
        _day ++;
    }
}

void Date::decreaseDay(){
    if(_day == 1){
        if(_month == 1){
            _day = getDaysInMonth(12, _year - 1);
            _month = 12;
            _year --;
        } else{
            _day = getDaysInMonth(_month - 1, _year);
            _month --;
        }
    } else{
        _day --;
    }
}