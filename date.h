#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>
#include <iomanip>

class Date
{
private:
    int day, month, year;

public:
    Date();
    Date(int, int, int);
    void printDate();
    int getDay() const
    { return day; }
    int getMonth() const
    { return month; }
    int getYear() const
    { return year; }

    void setDay(int);
    void setMonth(int);
    void setYear(int);

    void addDays(int);
    int daysInMonth(int, int) const;
    bool isLeapYear(int) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date)
    {
        os << std::setw(2) << std::setfill('0') << date.month << "/" << std::setw(2) << std::setfill('0') << date.day << "/" << std::setw(2) << std::setfill('0') << date.year;
        return os;
    }
    
	friend std::istream& operator>>(std::istream& is, Date& date) {
    int month, day, year;
    char ch;
    bool monthFlag, dayFlag, yearFlag, seperatorFlag; //for input val
    // Read the month.
	
	while(true)
	{
		monthFlag = false;
		dayFlag = false;
		yearFlag = false;
		seperatorFlag = false;
		try
		{
			if (!(is >> month))
				{ 
					std::cin.clear();
        			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					throw std::runtime_error("Please enter an integer for the day");
				}
			if (month < 1 || month > 12)
				throw std::invalid_argument("Month must be a value between 1 and 12");
		}
		catch(const std::invalid_argument &e)
		{
			std::cerr << e.what() << std::endl;
			monthFlag = true;
		}
		catch(const std::runtime_error &e)
		{
			std::cerr << e.what() << std::endl;
			monthFlag = true;
		}

		// Read the separator.
		is >> ch;
		if (ch != '/') {
			is.setstate(std::ios::failbit);
			// return is;
			seperatorFlag = true;
		}

		// Read the day.
		try
		{
			if (!(is >> day))
				{
					std::cin.clear();
        			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					throw std::runtime_error("Please enter an integer for the month");
				}
			if (monthFlag == true)
				throw std::invalid_argument("Need valid month");
			else if (day < 1)
				throw std::invalid_argument("Day cannot be less that 1");
			else
				switch(month)
				{
					case 1:
						if (day > 31)
						throw std::invalid_argument("January has 31 days");
						break;
					case 2: 
						// if (isLeapYear(year)) need to factor this in somehow
						if (day > 29) //28 days in non leap years
							throw std::invalid_argument("February has 28/29 days");
						break;
					case 3:	
						if (day > 31)
							throw std::invalid_argument("March has 31 days");
						break;
					case 4:
						if (day > 30)
							throw std::invalid_argument("April has 30 days");
						break;
					case 5:
						if (day > 31)
							throw std::invalid_argument("May has 31 days");
						break;
					case 6:
						if (day > 30)
							throw std::invalid_argument("June has 30 days");
						break;
					case 7: 
						if (day > 31)
							throw std::invalid_argument("July has 31 days");
						break;
					case 8:	
						if (day > 31)
							throw std::invalid_argument("August has 31 days");
						break;
					case 9:
						if (day > 30)
							throw std::invalid_argument("September has 30 days");
						break;
					case 10:
						if (day > 31)
							throw std::invalid_argument("October has 31 days");	
						break;
					case 11:
						if (day > 30)
							throw std::invalid_argument("November has 30 days");
						break;
					case 12:
						if (day > 31)
							throw std::invalid_argument("December has 31 days");
						break;
				}
		}
		catch(const std::invalid_argument &e)
		{
			std::cerr << e.what() << std::endl;
			dayFlag = true;
		}
		catch(const std::runtime_error &e)
		{
			std::cerr << e.what() << std:: endl;
			dayFlag = true;
		}

		// Read the separator.
		is >> ch;
		if (ch != '/') {
			is.setstate(std::ios::failbit);
			// return is;
			seperatorFlag = true;
		}

		// Read the year.
		try
		{
			if (!(is >> year))
			{
				std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::runtime_error("please enter an integer for year");
			}
			if (year < 0)
				throw std::invalid_argument("year must be positive");
			else if (year > 3000)
				throw std::invalid_argument("you're not gonna live that long");
		}
		catch(const std::invalid_argument &e)
		{
			std::cerr << e.what() << std::endl;
			yearFlag = true;
		}
		catch(const std::runtime_error &e)
		{
			std::cerr << e.what() << std::endl;
			yearFlag = true;
		}
		
		if (monthFlag == false && dayFlag == false && yearFlag == false && seperatorFlag == false)
			break;
	}



    // Set the date.
    date.setMonth(month);
    date.setDay(day);
    date.setYear(year);

    return is;
  }

    Date operator <<(Date const&);
};