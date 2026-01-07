#pragma once
#include <iostream>
#include "SoultionTeacher.h" // Contains sDate struct definition

using namespace std;

namespace MyLibDate
{
    // =============================================
    // Calculate the day of the week for a given date
    // Returns 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    // =============================================
    int calcluateD(int year, int month, int day)
    {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;
        int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;
        return d;
    }

    // Overload: Calculate day of the week using sDate
    int calcluateD(MyLibSoultionTeacher::sDate date)
    {
        return calcluateD(date.Year, date.Month, date.Day);
    }

    // =============================================
    // Convert total days since start of year to sDate
    // =============================================
    MyLibSoultionTeacher::sDate convertTotalDayToDate(short totalDay, int year)
    {
        MyLibSoultionTeacher::sDate date;
        short month = 1;
        short daysInCurrentMonth = daysInMonth(year, month);

        while (totalDay > daysInCurrentMonth)
        {
            totalDay -= daysInCurrentMonth;
            month++;
            daysInCurrentMonth = daysInMonth(year, month);
        }

        date.Day = totalDay;
        date.Month = month;
        date.Year = year;
        return date;
    }

    // =============================================
    // Add a number of days to a given date
    // =============================================
    MyLibSoultionTeacher::sDate addDays(int day, int month, int year, int addDays)
    {
        MyLibSoultionTeacher::sDate date;
        int daysInCurrentMonth = daysInMonth(year, month);

        while (addDays != 0)
        {
            day++;
            addDays--;
            if (day > daysInCurrentMonth)
            {
                day = 1;
                month++;
                if (month > 12)
                {
                    month = 1;
                    year++;
                }
                daysInCurrentMonth = daysInMonth(year, month);
            }
        }

        date.Day = day;
        date.Month = month;
        date.Year = year;
        return date;
    }

    // =============================================
    // Increment functions
    // =============================================
    MyLibSoultionTeacher::sDate increaseOneDay(MyLibSoultionTeacher::sDate date)
    {
        return addDays(date.Day, date.Month, date.Year, 1);
    }

    MyLibSoultionTeacher::sDate increaseOneWeek(MyLibSoultionTeacher::sDate date)
    {
        return addDays(date.Day, date.Month, date.Year, 7);
    }

    MyLibSoultionTeacher::sDate increaseWeeks(MyLibSoultionTeacher::sDate date, int howManyWeeks)
    {
        for (int i = 0; i < howManyWeeks; i++)
            date = increaseOneWeek(date);
        return date;
    }

    MyLibSoultionTeacher::sDate increaseOneMonth(MyLibSoultionTeacher::sDate date)
    {
        date.Month++;
        if (date.Month > 12)
        {
            date.Month = 1;
            date.Year++;
        }

        // Adjust day if it exceeds new month
        short maxDays = daysInMonth(date.Year, date.Month);
        if (date.Day > maxDays)
            date.Day = maxDays;

        return date;
    }

    MyLibSoultionTeacher::sDate increasMonths(MyLibSoultionTeacher::sDate date, int howManyMonths)
    {
        for (int i = 0; i < howManyMonths; i++)
            date = increaseOneMonth(date);
        return date;
    }

    MyLibSoultionTeacher::sDate increaseOneYear(MyLibSoultionTeacher::sDate date)
    {
        date.Year++;
        return date;
    }

    MyLibSoultionTeacher::sDate increaseYears(MyLibSoultionTeacher::sDate date, int howManyYears)
    {
        for (int i = 0; i < howManyYears; i++)
            date = increaseOneYear(date);
        return date;
    }

    MyLibSoultionTeacher::sDate increaseYearsFaster(MyLibSoultionTeacher::sDate date, int howManyYears)
    {
        date.Year += howManyYears;
        return date;
    }

    MyLibSoultionTeacher::sDate increaseOneDecade(MyLibSoultionTeacher::sDate date)
    {
        return increaseYearsFaster(date, 10);
    }

    MyLibSoultionTeacher::sDate increaseDecades(MyLibSoultionTeacher::sDate date, int howManyDecades)
    {
        for (int i = 0; i < howManyDecades; i++)
            date = increaseOneDecade(date);
        return date;
    }

    MyLibSoultionTeacher::sDate increaseDecadesFaster(MyLibSoultionTeacher::sDate date, int howManyDecades)
    {
        date.Year += howManyDecades * 10;
        return date;
    }

    MyLibSoultionTeacher::sDate increaseOneCentury(MyLibSoultionTeacher::sDate date)
    {
        return increaseDecadesFaster(date, 10);
    }

    MyLibSoultionTeacher::sDate increaseOneMillenium(MyLibSoultionTeacher::sDate date)
    {
        return increaseYearsFaster(date, 1000);
    }

    // =============================================
    // Decrement functions
    // =============================================
    MyLibSoultionTeacher::sDate decreseOneDay(MyLibSoultionTeacher::sDate date)
    {
        if (date.Day == 1)
        {
            date.Month--;
            if (date.Month < 1)
            {
                date.Month = 12;
                date.Year--;
                if (date.Year < 1)
                    date.Year = 1; // avoid negative year
            }
            date.Day = daysInMonth(date.Year, date.Month);
        }
        else
        {
            date.Day--;
        }
        return date;
    }

    MyLibSoultionTeacher::sDate decreseDays(MyLibSoultionTeacher::sDate date, int howManyDays)
    {
        for (int i = 0; i < howManyDays; i++)
            date = decreseOneDay(date);
        return date;
    }

    MyLibSoultionTeacher::sDate decreseOneWeek(MyLibSoultionTeacher::sDate date)
    {
        return decreseDays(date, 7);
    }

    MyLibSoultionTeacher::sDate decreseWeeks(MyLibSoultionTeacher::sDate date, int howManyWeeks)
    {
        for (int i = 0; i < howManyWeeks; i++)
            date = decreseOneWeek(date);
        return date;
    }

    MyLibSoultionTeacher::sDate decreseOneMonth(MyLibSoultionTeacher::sDate date)
    {
        date.Month--;
        if (date.Month < 1)
        {
            date.Month = 12;
            date.Year--;
            if (date.Year < 1)
                date.Year = 1;
        }

        short maxDays = daysInMonth(date.Year, date.Month);
        if (date.Day > maxDays)
            date.Day = maxDays;

        return date;
    }

    MyLibSoultionTeacher::sDate decreseMonths(MyLibSoultionTeacher::sDate date, int howManyMonths)
    {
        for (int i = 0; i < howManyMonths; i++)
            date = decreseOneMonth(date);
        return date;
    }

    MyLibSoultionTeacher::sDate decreseOneYear(MyLibSoultionTeacher::sDate date)
    {
        if (date.Year > 1)
            date.Year--;
        return date;
    }

    MyLibSoultionTeacher::sDate decreseYears(MyLibSoultionTeacher::sDate date, int howManyYears)
    {
        for (int i = 0; i < howManyYears; i++)
            date = decreseOneYear(date);
        return date;
    }

    MyLibSoultionTeacher::sDate decreseYearsFaster(MyLibSoultionTeacher::sDate date, int howManyYears)
    {
        date.Year -= howManyYears;
        if (date.Year < 1) date.Year = 1;
        return date;
    }

    MyLibSoultionTeacher::sDate decreseOneDecade(MyLibSoultionTeacher::sDate date)
    {
        return decreseYearsFaster(date, 10);
    }

    MyLibSoultionTeacher::sDate decreseDecades(MyLibSoultionTeacher::sDate date, int howManyDecades)
    {
        for (int i = 0; i < howManyDecades; i++)
            date = decreseOneDecade(date);
        return date;
    }

    MyLibSoultionTeacher::sDate decreseDecadesFaster(MyLibSoultionTeacher::sDate date, int howManyDecades)
    {
        return decreseYearsFaster(date, howManyDecades * 10);
    }

    MyLibSoultionTeacher::sDate decreseOneCentury(MyLibSoultionTeacher::sDate date)
    {
        return decreseYearsFaster(date, 100);
    }

    MyLibSoultionTeacher::sDate decreseOneMillennium(MyLibSoultionTeacher::sDate date)
    {
        return decreseYearsFaster(date, 1000);
    }
}
