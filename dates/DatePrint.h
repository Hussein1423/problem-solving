#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "SoultionTeacher.h"   // sDate struct
#include "DateCalculation.h"   // addDays, daysInMonth, etc.
#include "DateComparison.h"    // date comparison helpers

using namespace std;

namespace MyLibDatePrint
{
    // =============================================
    // Get the name of the day based on day number
    // 0=Sunday, 1=Monday, ..., 6=Saturday
    // =============================================
    string getNameOfDay(int d)
    {
        switch (d)
        {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        default: return "None";
        }
    }

    // =============================================
    // Print calendar for a specific month
    // =============================================
    void printCalenderOfMonth(int year, int month)
    {
        string nameOfMonth[] = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec"};

        cout << "\n  _______________" << nameOfMonth[month - 1] << "_______________\n\n";
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        int current = MyLibDate::calcluateD(year, month, 1);
        short daysInMonth = MyLibDate::daysInMonth(year, month);
        int i;

        for (i = 1; i <= current; i++)
        {
            cout << setw(5) << "";
        }

        for (int j = 1; j <= daysInMonth; j++)
        {
            cout << setw(5) << j;
            if (i++ == 7)
            {
                cout << endl;
                i = 1;
            }
        }
        cout << "\n  _________________________________\n";
    }

    // =============================================
    // Print calendar for the entire year
    // =============================================
    void printCalenderOfYear(int year)
    {
        cout << "   _____________________\n\n\tCalendar " << year << "\n\n   _____________________\n\n";
        for (int i = 1; i <= 12; i++)
        {
            printCalenderOfMonth(year, i);
        }
    }

    // =============================================
    // Count days from the beginning of the year until the given date
    // =============================================
    short dayFromTheBeginningUntilNow(int year, int month, int day)
    {
        short count = 0;
        for (int m = 1; m < month; m++)
        {
            count += MyLibDate::daysInMonth(year, m);
        }
        count += day;
        return count;
    }

    // =============================================
    // Print a date in YYYY/MM/DD format
    // =============================================
    void printDate(MyLibSoultionTeacher::sDate date)
    {
        cout << date.Year << "/" << date.Month << "/" << date.Day << endl;
    }

    // =============================================
    // Print a date along with the name of the day
    // =============================================
    void printDateAndNameOfDay(MyLibSoultionTeacher::sDate date)
    {
        int numberOfDay = MyLibDate::calcluateD(date);
        string nameOfDay = getNameOfDay(numberOfDay);
        cout << "Today is " << nameOfDay << ", " << date.Day << "/" << date.Month << "/" << date.Year << endl;
    }

    // =============================================
    // Print a date in multiple formats
    // Input format: string "YYYY/MM/DD" or "DD/MM/YYYY" etc.
    // =============================================
    void printDateFormat(string dateStr)
    {
        MyLibSoultionTeacher::sDate date = MyLibSoultionTeacher::StringToDate(dateStr);

        cout << date.Day << "/" << date.Month << "/" << date.Year << endl;
        cout << date.Year << "/" << date.Day << "/" << date.Month << endl;
        cout << date.Month << "/" << date.Day << "/" << date.Year << endl;
        cout << date.Month << "-" << date.Day << "-" << date.Year << endl;
        cout << date.Day << "-" << date.Month << "-" << date.Year << endl;
        cout << "Day: " << date.Day << ",  Month: " << date.Month << ",  Year: " << date.Year << endl;
    }
}
