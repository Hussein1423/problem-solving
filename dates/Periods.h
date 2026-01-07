#pragma once
#include "SoultionTeacher.h"
#include "DateCalculation.h"
#include "DateComparison.h"
#include <iostream>

using namespace std;

namespace MyLibPeriods
{
    // =============================================
    // Calculate the length of a period in days
    // includeLastDay: whether to include the last day in the count
    // =============================================
    int lengthDaysOfPeriod(MyLibSoultionTeacher::stPeriod period, bool includeLastDay = false)
    {
        return MyLibDate::diffrencesBetweenDates(period.StartDate, period.EndDate, includeLastDay);
    }

    // =============================================
    // Check if a given date is within the period
    // =============================================
    bool isDateInPeriod(MyLibSoultionTeacher::stPeriod period, MyLibSoultionTeacher::sDate date)
    {
        MyLibSoultionTeacher::sDate current = period.StartDate;
        while (!MyLibDate::isDate1EqaulDate2(current, period.EndDate))
        {
            if (MyLibDate::isDate1EqaulDate2(current, date))
                return true;
            current = MyLibDate::increaseOneDay(current);
        }

        // Check the last day
        return MyLibDate::isDate1EqaulDate2(period.EndDate, date);
    }

    // =============================================
    // Check if two periods overlap
    // =============================================
    bool isOverLap(MyLibSoultionTeacher::sDate periodFrom1, MyLibSoultionTeacher::sDate periodTo1,
                   MyLibSoultionTeacher::sDate periodFrom2, MyLibSoultionTeacher::sDate periodTo2)
    {
        MyLibSoultionTeacher::sDate start1 = periodFrom1;
        MyLibSoultionTeacher::sDate end1 = periodTo1;
        MyLibSoultionTeacher::sDate start2 = periodFrom2;
        MyLibSoultionTeacher::sDate end2 = periodTo2;

        while (!MyLibDate::isDate1EqaulDate2(start1, end1))
        {
            if (MyLibDate::isDate1EqaulDate2(start1, start2))
                return true;
            start1 = MyLibDate::increaseOneDay(start1);
        }

        while (!MyLibDate::isDate1EqaulDate2(start2, end2))
        {
            if (MyLibDate::isDate1EqaulDate2(start1, start2))
                return true;
            start2 = MyLibDate::increaseOneDay(start2);
        }

        return false;
    }

    // =============================================
    // Count the number of overlapping days between two periods
    // =============================================
    int countOverLap(MyLibSoultionTeacher::stPeriod period1, MyLibSoultionTeacher::stPeriod period2)
    {
        int count = 0;
        MyLibSoultionTeacher::sDate current = period2.StartDate;

        while (!MyLibDate::isDate1EqaulDate2(current, period2.EndDate))
        {
            if (isOverLap(period1.StartDate, period1.EndDate, current, period2.EndDate))
                count++;

            current = MyLibDate::increaseOneDay(current);
        }

        // Include the last day if overlapping
        if (isOverLap(period1.StartDate, period1.EndDate, period2.EndDate, period2.EndDate))
            count++;

        return count;
    }
}
