/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari 
//* Date last updated: 05/27/2024
//* Purpose(Implementation file): Implements the class date, which represents a specific day and month in a year. The class has methods to get the values of each and overloaded operators for better date manipulation
//* Notes:
  - This class correctly handles leap years and invalid dates. It also takes into account months with different amounts of days.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "date.h"

const char* InvalidDateException::what() const noexcept {
    return "Invalid date";
}

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int getDaysInMonth(int month, int year) {
    // Handle February
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }

    // 30 days months
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    // All others have 31 days
    return 31;
}

bool isValidDate(int month_p, int day_p, int year_p) {
    return (year_p < 0)
        || (month_p < 1 || month_p > 12)
        || (month_p == 2 && day_p > 28 && !isLeapYear(year_p))
        || (month_p == 2 && day_p > 29 && isLeapYear(year_p))
        || (month_p == 4 && day_p > 30)
        || (month_p == 6 && day_p > 30)
        || (month_p == 9 && day_p > 30)
        || (month_p == 11 && day_p > 30)
        || (day_p > 31);
}

// Constructor
date::date(int month_p, int day_p, int year_p) {
    if (!isValidDate(month_p, day_p, year_p)) {
        throw InvalidDateException();
    }
    month = month_p;
    day = day_p;
    year = year_p;
}

// Accessors
int date::getDay() const { return day; }
int date::getMonth() const { return month; }
int date::getYear() const { return year; }

// Mutators
void date::setDay(int day_p) {
    if (!isValidDate(month, day_p, year)) {
        throw InvalidDateException();
    }
    day = day_p;
}

void date::setMonth(int month_p) {
    if (!isValidDate(month_p, day, year)) {
        throw InvalidDateException();
    }
    month = month_p;
}

void date::setYear(int year_p) {
    if (year_p < 0) {
        throw InvalidDateException();
    }
    year = year_p;
}

// Overloaded operators
bool date::operator!=(const date& otherDate) const {
    return !(*this == otherDate);
}

bool date::operator<(const date& otherDate) const {
    if (year < otherDate.year) {
        return true;
    }
    if (year == otherDate.year && month < otherDate.month) {
        return true;
    }
    if (year == otherDate.year && month == otherDate.month && day < otherDate.day) {
        return true;
    }
    return false;
}

bool date::operator<=(const date& otherDate) const {
    return (*this < otherDate) || (*this == otherDate);
}

bool date::operator==(const date& otherDate) const {
    return (year == otherDate.year && month == otherDate.month && day == otherDate.day);
}

bool date::operator>(const date& otherDate) const {
    return !(*this <= otherDate);
}

bool date::operator>=(const date& otherDate) const {
    return !(*this < otherDate);
}

date& date::operator++() {
    day++;
    if (day > getDaysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

date date::operator++(int) {
    date copy = *this;
    ++(*this);
    return copy;
}

date& date::operator--() {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = getDaysInMonth(month, year);
    }
    return *this;
}

date date::operator--(int) {
    date copy = *this;
    --(*this);
    return copy;
}

date& date::operator+(int daysToAdd) {
    day += daysToAdd;
    while (day > getDaysInMonth(month, year)) {
        day -= getDaysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

date& date::operator-(int daysToSub) {
    day -= daysToSub;
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += getDaysInMonth(month, year);
    }
    return *this;
}

// Non-member function overloads for operators
date& operator+(int daysToAdd, date& addToDate) {
    return addToDate + daysToAdd;
}

date& operator-(int daysToSub, date& subFromDate) {
    return subFromDate - daysToSub;
}

// Input/output stream overloads
std::istream& operator>>(std::istream& in, date& dateToFill) {
    int month, day, year;
    in >> month >> day >> year;
    try {
        dateToFill = date(month, day, year);
    } catch (const InvalidDateException& e) {
        std::cerr << e.what() << std::endl;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const date& dateToPrint) {
    out << dateToPrint.getYear() << "-"
        << std::setfill('0') << std::setw(2) << dateToPrint.getMonth() << "-"
        << std::setfill('0') << std::setw(2) << dateToPrint.getDay();
    return out;
}