#include "../headers/DateTime.h"

DateTime::DateTime() {}

DateTime::DateTime(Date date, Time time) {
    setDate(date);
    setTime(time);
}

DateTime::DateTime(int day, int month, int year, int second, int minute, int hour) {
    setDate(day, month, year);
    setTime(second, minute, hour);
}

void DateTime::setDate(Date date) {
    _date = date;
}

Date DateTime::getDate() {
    return _date;
}

void DateTime::setTime(Time time) {
    _time = time;
}

Time DateTime::getTime() {
    return _time;
}

void DateTime::setDate(int day, int month, int year) {
    if (0 < day && day <= _date.getDaysInMonth(month, year) && 0 < month && month <= 12 && 0 < year) {
        _date.setDay(day);
        _date.setMonth(month);
        _date.setYear(year);
    }
}

void DateTime::setTime(int second, int minute, int hour) {
    if (0 <= second && second < 60 && 0 <= minute && minute < 60 && 0 <= hour && hour < 24) {
        _time.setSecond(second);
        _time.setMinute(minute);
        _time.setHour(hour);
    }
}

std::string DateTime::toString() {
    return _date.toString() + " " + _time.toString();
}