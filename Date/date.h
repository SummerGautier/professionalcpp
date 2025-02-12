#pragma once

class Date {
    public:
        // construct date object.
        Date (const int _year, const int _month, const int _day);
        // increment the current 'day' by _increment amount of days.
        void AddDay (const int _increment);

        // set property values.
        void SetYear (const int _value);
        void SetMonth (const int _value);
        void SetDay (const int _value);
        
        // return property value.
        int GetYear ();
        int GetMonth ();
        int GetDay ();
    private:
        // unsigned, 4-byte integer since year has a floor (0) but no high ceiling.
        // 2-billion should be sufficient maximum.
        int year {0};
        // single-byte since possible months < 255. unsigned since it must be positive.
        int month {0};
        // single-byte since possible days < 255. unsigned since it must be positive.
        int day {0};
};