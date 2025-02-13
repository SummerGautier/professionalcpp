#include <stdexcept>
#include <climits>
#include "date.h"
#include <vector>

/**
 * Date
 */

Date::Date (const int _year, const DateUtil::Month _month, const int _day) {
    // using initializer list {} to force failure if narrowing conversion.
    this->SetYear(_year);
    this->SetMonth(_month);
    this->SetDay(_day);
}

void Date::AddDay (const int _increment) {
    // check if operation would cause an overflow.
    if (this->day + _increment > INT_MAX) {
        throw std::overflow_error("Integer overflow encountered. Unable to increment Date::Day()");
    }
    // updaet the day by adding the increment.
    this->day = this->day + _increment;
    return;
}

void Date::SetYear (const int _value) {
    // check that year is non-negative.
    if (_value < 0) {
        throw std::invalid_argument("Year cannot be negative.");
    }
    // update year from _value.
    this->year = _value;
    return;
}

void Date::SetMonth (const DateUtil::Month _value) {
    // update month from _value.
    this->month = _value;
    return;
}

void Date::SetDay (const int _value) {
    // check that day is non-negative.
    if (_value < 0) {
        throw std::invalid_argument("Day cannot be negative.");
    }
    // ensure that day is a real value.
    if (_value > 31) {
        throw std::invalid_argument("Day greater than 31 is not valid.");
    }
    // update day from _value.
    this->day = _value;
    return;
}

int Date::GetYear () {
    return this->year;
}

DateUtil::Month Date::GetMonth () {
    return this->month;
}

int Date::GetDay () {
    return this->day;
}

/** 
 * Date Utils
 */

const std::vector<std::string> DateUtil::namesOfDays {
    "sunday", "monday", "tuesday", "wednesday",
    "friday", "saturday"
};

const std::vector<std::string> DateUtil::namesOfMonths {
    "january", "february", "march", "april",
    "may", "june", "july", "august", "september",
    "october", "november", "december"
};

DateUtil::Month DateUtil::MonthFromInt (const int _x) {
    // check if arg is less than january.
    if (_x < int(DateUtil::Month::january)) {
        throw std::invalid_argument("Month cannot convert int below 1.");
    }
    // check if arg is greater than december.
    if (_x > int(DateUtil::Month::december)) {
        throw std::invalid_argument("Month cannot convert int above 12.");
    }
    // if int is valid, return new Month object.
    return DateUtil::Month {_x};
}

DateUtil::Day DateUtil::DayFromInt (const int _x) {
    // check if arg is less than sunday.
    if (_x < int(DateUtil::Day::sunday)) {
        throw std::invalid_argument("Day cannot convert int below 0.");
    }
    // check if arg is greater than saturday.
    if (_x > int(DateUtil::Day::saturday)) {
        throw std::invalid_argument("Day cannot convert int above 6.");
    }
    //if int is valid return new Day object.
    return DateUtil::Day {_x};
}

DateUtil::Month DateUtil::operator ++ (DateUtil::Month& _month) {
    // if month is jan-nov, then increment by one to next month. i.e. jan->feb, feb->march, etc.
    if (_month < DateUtil::Month::december) {
        _month = DateUtil::Month(int(_month) + 1);
        return _month;
    }
    // otherwise, if month is already december, then wrap around to january.
    _month = DateUtil::Month::january;
    return _month;
}

std::ostream& DateUtil::operator << (std::ostream& _os, DateUtil::Month _month) {
    // calculate 0-based index.
    int _index = int(_month) - int(DateUtil::Month::january);
    // add month name as string to ostream.
    return _os << DateUtil::namesOfMonths[_index];
}