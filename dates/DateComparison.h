#pragma once
#include <iostream>
#include "SoultionTeacher.h"   // sDate struct
#include "LeapYear.h"          // leap year functions
#include "DateCalculation.h"   // daysInMonth, etc.

using namespace std;

namespace MyLibDateComparison
{
    // =============================================
    // Enum for date comparison
    // before  = -1
    // eqaul   = 0
    // after   = 1
    // =============================================
    enum CompareDate { before = -1, eqaul = 0, after = 1 };

    // =============================================
    // Compare two dates
    // Returns true if date1 > date2
    // =============================================
    bool compareDates(MyLibSoultionTeacher::sDate date1, MyLibSoultionTeacher::sDate date2)
    {
        if (date1.Year != date2.Year) return date1.Year > date2.Year;
        if (date1.Month != date2.Month) return date1.Month > date2.Month;
        return date1.Day > date2.Day;
    }

    // =============================================
    // Check if two dates are equal
    // =============================================
    bool isDate1EqaulDate2(MyLibSoultionTeacher::sDate date1, MyLibSoultionTeacher::sDate date2)
    {
        return (date1.Day == date2.Day &&
                date1.Month == date2.Month &&
                date1.Year == date2.Year);
    }

    // =============================================
    // Check if a date is the last day in its month
    // =============================================
    bool isLastDayInMonth(MyLibSoultionTeacher::sDate date)
    {
        return date.Day == MyLibDate::daysInMonth(date.Year, date.Month);
    }

    // =============================================
    // Check if a date is the last day in its year
    // =============================================
    bool isLastDayInYear(MyLibSoultionTeacher::sDate date)
    {
        return (date.Month == 12 && isLastDayInMonth(date));
    }

    // =============================================
    // Check if a date is the first day in its month
    // =============================================
    bool isFirstDayInMonth(MyLibSoultionTeacher::sDate date)
    {
        return date.Day == 1;
    }

    // =============================================
    // Check if a month is the first month in a year (January)
    // =============================================
    bool isFirstMonthInYear(int month)
    {
        return month == 1;
    }

    // =============================================
    // Check if date1 comes after date2
    // =============================================
    bool isDate1AfterDate2(MyLibSoultionTeacher::sDate date1, MyLibSoultionTeacher::sDate date2)
    {
        return compareDates(date1, date2);
    }

    // =============================================
    // Compare two dates using CompareDate enum
    // =============================================
    CompareDate compareDate(MyLibSoultionTeacher::sDate date1, MyLibSoultionTeacher::sDate date2)
    {
        if (isDate1EqaulDate2(date1, date2)) return eqaul;
        return compareDates(date1, date2) ? after : before;
    }

    // =============================================
    // Validate if a date is correct
    // Day and month within limits
    // =============================================
    bool isValidateDate(MyLibSoultionTeacher::sDate date)
    {
        if (date.Month < 1 || date.Month > 12) return false;
        int maxDay = MyLibDate::daysInMonth(date.Year, date.Month);
        if (date.Day < 1 || date.Day > maxDay) return false;
        return true;
    }
}
