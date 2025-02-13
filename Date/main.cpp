#include <iostream>
#include <format>

#include "date.h"

int main () {
    // init _local date to beginning.
    Date _local {0,0,0};
    DateUtil::Month _currentMonth = DateUtil::Month::february;
    ++_currentMonth;
    std::cout << _currentMonth << std::endl;
    // prompt for the year.
    std::cout << "Enter Date: " << std::endl;
    // locals to hold user input.
    int _year {0};
    int _day {0};
    int _month {0};
    // read in user input of date.
    std::cin >> _year >> _month >> _day;
    // re-initialize date object.
    _local = {
        _year,
        _month,
        _day
    };
    // verify the final date result.
    std::cout << std::format("{}/{}/{}", _local.GetMonth(), _local.GetDay(), _local.GetYear()) << std::endl;
}