#include <stdexcept>
#include <climits>
#include "date.h"

Date::Date (const int _year, const int _month, const int _day) {
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

void Date::SetMonth (const int _value) {
    // check that month is non-negative.
    if (_value < 0) {
        throw std::invalid_argument("Month cannot be negative.");
    }
    // ensure that month is a real value.
    if (_value > 12) {
        throw std::invalid_argument("Month greater than 12 is not valid.");
    }
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

int Date::GetMonth () {
    return this->month;
}

int Date::GetDay () {
    return this->day;
}