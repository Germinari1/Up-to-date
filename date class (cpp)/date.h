/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari 
//* Date last updated: 05/27/2024
//* Purpose(definition file): Implements the class date, which represents a specific day and month in a year. The class has methods to get the values of each and overloaded operators for better date manipulation
//* Notes:
  - This class correctly handles leap years and invalid dates. It also takes into account months with different amounts of days.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>

// Custom exception class for invalid dates
class InvalidDateException : public std::exception {
public:
    const char* what() const noexcept override;
};

// Helper function to check if a year is a leap year
bool isLeapYear(int year);

// Helper function to get the number of days in a given month and year
int getDaysInMonth(int month, int year);

// Helper function to validate a date
bool isValidDate(int month, int day, int year);

class date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor
    date(int month_p, int day_p, int year_p);

    // Accessors
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Mutators
    void setDay(int day_p);
    void setMonth(int month_p);
    void setYear(int year_p);

    // Overloaded operators
    bool operator!=(const date& otherDate) const;
    bool operator<(const date& otherDate) const;
    bool operator<=(const date& otherDate) const;
    bool operator==(const date& otherDate) const;
    bool operator>(const date& otherDate) const;
    bool operator>=(const date& otherDate) const;
    date& operator++();
    date operator++(int);
    date& operator--();
    date operator--(int);
    date& operator+(int daysToAdd);
    date& operator-(int daysToSub);
};

// Non-member function overloads for operators
date& operator+(int daysToAdd, date& addToDate);
date& operator-(int daysToSub, date& subFromDate);

// Input/output stream overloads
std::istream& operator>>(std::istream& in, date& dateToFill);
std::ostream& operator<<(std::ostream& out, const date& dateToPrint);

#endif