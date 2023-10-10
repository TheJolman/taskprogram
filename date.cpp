#include "date.h"
#include <ctime>

Date::Date() 
{
    time_t now = time(0);
    struct tm* currentTime = localtime(&now);
    day = currentTime->tm_mday;
    month = currentTime->tm_mon + 1;  // tm_mon is zero-based
    year = currentTime->tm_year + 1900;  // tm_year is years since 1900
}
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {} 
void Date::setDay(int day)
{
    this->day = day;
}
void Date::setMonth(int month)
{
    this->month = month;
}
void Date::setYear(int year)
{
    this->year = year;
}
 // Function to add a certain number of days to the date.
void Date::addDays(int daysToAdd)
{
    // Calculate the new day and month, taking into account month/year boundaries.
    day += daysToAdd;
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// Helper function to get the number of days in a specific month.
int Date::daysInMonth(int m, int y) const
{
    static const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysPerMonth[m];
    if (m == 2 && isLeapYear(y)) {
        days++;  // February has 29 days in a leap year.
    }
    return days;
}

// Helper function to check if a year is a leap year.
bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}