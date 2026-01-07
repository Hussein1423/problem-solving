#pragma once
#include <iostream>
#include "SoultionTeacher.h"
#include "DateCalculation.h"
#include "DateComparison.h"

using namespace std;

namespace MyLibBusinessDays
{
    // =============================================
    // Check if the date is the end of the week (Sunday)
    // =============================================
    bool isEndOfWeek(MyLibSoultionTeacher::sDate date)
    {
        int numberOfDay = MyLibDate::calcluateD(date);
        string nameOfDay = MyLibDatePrint::getNameOfDay(numberOfDay);
        return (nameOfDay == "Sunday");
    }

    // =============================================
    // Check if the date is a weekend (Friday or Saturday)
    // =============================================
    bool isWeekEnd(MyLibSoultionTeacher::sDate date)
    {
        int numberOfDay = MyLibDate::calcluateD(date);
        string nameOfDay = MyLibDatePrint::getNameOfDay(numberOfDay);
        return (nameOfDay == "Friday" || nameOfDay == "Saturday");
    }

    // =============================================
    // Check if the date is a business day
    // =============================================
    bool isBusinessDay(MyLibSoultionTeacher::sDate date)
    {
        return !isWeekEnd(date);
    }

    // =============================================
    // Count number of days until the end of the week
    // =============================================
    int untilEndDayOfWeek(MyLibSoultionTeacher::sDate date)
    {
        int count = 0;
        while (!isEndOfWeek(date))
        {
            count++;
            date = MyLibDate::increaseOneDay(date);
        }
        return count;
    }

    // =============================================
    // Count number of days until the end of the month
    // =============================================
    int untilEndDayOfMonth(MyLibSoultionTeacher::sDate date)
    {
        int daysOfMonth = MyLibDate::daysInMonth(date.Year, date.Month);
        int count = 0;
        while (date.Day != daysOfMonth)
        {
            count++;
            date = MyLibDate::increaseOneDay(date);
        }
        return count;
    }

    // =============================================
    // Count number of days until the end of the year
    // =============================================
    int untilEndDayOfYear(MyLibSoultionTeacher::sDate date)
    {
        int count = 0;
        while (!MyLibDate::isLastDayInYear(date))
        {
            count++;
            date = MyLibDate::increaseOneDay(date);
        }
        return count;
    }

    // =============================================
    // Calculate actual vacation days (count only business days)
    // =============================================
    int actualVacation(MyLibSoultionTeacher::sDate start, MyLibSoultionTeacher::sDate end)
    {
        int diff = MyLibDate::diffrencesBetweenDates(start, end, true);
        int count = 0;
        for (int i = 0; i < diff; i++)
        {
            if (isBusinessDay(start))
                count++;
            start = MyLibDate::increaseOneDay(start);
        }
        return count;
    }

    // =============================================
    // Determine the return-to-work date after vacation
    // =============================================
    MyLibSoultionTeacher::sDate returnToWork(MyLibSoultionTeacher::sDate start, int vacationDays)
    {
        while (vacationDays > 0)
        {
            if (isBusinessDay(start))
                vacationDays--;
            start = MyLibDate::increaseOneDay(start);
        }
        return start;
    }
}
