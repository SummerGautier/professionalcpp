#pragma once
#include <vector>

class Date {
    public:
        // construct date object.
        Date (const int _year, const DateUtil::Month _month, const int _day);
        // increment the current 'day' by _increment amount of days.
        void AddDay (const int _increment);

        // set property values.
        void SetYear (const int _value);
        void SetMonth (const DateUtil::Month _month);
        void SetDay (const int _value);
        
        // return property value.
        int GetYear ();
        DateUtil::Month GetMonth ();
        int GetDay ();
    private:
        // unsigned, 4-byte integer since year has a floor (0) but no high ceiling.
        // 2-billion should be sufficient maximum.
        int year {0};
        // Month as represented by 1-12 (january-december) enum. 
        DateUtil::Month month {DateUtil::Month::january};
        // single-byte since possible days < 255. unsigned since it must be positive.
        int day {0};
};

namespace DateUtil {
    // 1-based indexing (declared with specified offset on first entry/january=1)
    enum class Month {
        january=1, february, march, april, may, 
        june, july, august, september, october, 
        novemeber, december
    };
    // 0-based indexing (default)
    enum class Day {
        sunday, monday, tuesday, wednesday, thursday, 
        friday, saturday
    };
    // Map day to strings.
    extern const std::vector<std::string> namesOfDays;
    // Map month to string.
    extern const std::vector<std::string> namesOfMonths;
    // Use to convert valid integer to Month enum.
    Month MonthFromInt (const int _x);
    // Use to convert valid integer to Day enum.
    Day DayFromInt (const int _x);
    // Addition of Months.
    Month operator ++ (DateUtil::Month& _month);
    // Print out Months.
    std::ostream& operator << (std::ostream& _os, DateUtil::Month _month);
}