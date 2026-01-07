#pragma once
#include <iostream>

using namespace std;

namespace MyLibDate
{
    // Arrays for number of days in each month (leap year and normal year)
    const short leapMonth[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    const short notLeapMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // =============================================
    // Check if a year is a leap year (returns text)
    // =============================================
    string leapYear(int year)
    {
        if (year % 400 == 0)
            return "Leap Year\n";
        else if (year % 4 == 0 && year % 100 != 0)
            return "Leap Year\n";
        else
            return "Not Leap Year\n";
    }

    // =============================================
    // Quick check if a year is a leap year (returns bool)
    // =============================================
    bool shortIsleapYear(int year)
    {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }

    // =============================================
    // Get number of days in a year
    // =============================================
    short daysInYear(int year)
    {
        return shortIsleapYear(year) ? 366 : 365;
    }

    // =============================================
    // Get number of hours in a year
    // =============================================
    short hoursInYear(short days)
    {
        return days * 24;
    }

    // =============================================
    // Get number of minutes in a year
    // =============================================
    int minutesInYear(short hours)
    {
        return hours * 60;
    }

    // =============================================
    // Get number of seconds in a year
    // =============================================
    int secondsInYear(int minutes)
    {
        return minutes * 60;
    }

    // =============================================
    // Get number of days in a specific month
    // =============================================
    short daysInMonth(int year, int month)
    {
        if (month >= 1 && month <= 12)
            return shortIsleapYear(year) ? leapMonth[month - 1] : notLeapMonth[month - 1];
        else
            return 0; // Invalid month
    }

    // =============================================
    // Get number of hours in a specific month
    // =============================================
    short hoursInMonth(int year, int month)
    {
        return daysInMonth(year, month) * 24;
    }

    // =============================================
    // Get number of minutes in a specific month
    // =============================================
    int minutesInMonth(int year, int month)
    {
        return hoursInMonth(year, month) * 60;
    }

    // =============================================
    // Get number of seconds in a specific month
    // =============================================
    int secondsInMonth(int year, int month)
    {
        return minutesInMonth(year, month) * 60;
    }
}
