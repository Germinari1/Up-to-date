# Up-to-date
A lightweight date class for C++ that implements a class called `date` that represents a specific day, month, and year. The class provides various methods and overloaded operators to manipulate and work with dates efficiently.

## Features

- Correctly handles leap years and validates input dates
- Supports months with different numbers of days
- Provides accessors (`getDay()`, `getMonth()`, `getYear()`) and mutators (`setDay()`, `setMonth()`, `setYear()`)
- Implements comparison operators (`!=`, `<`, `<=`, `==`, `>`, `>=`)
- Supports increment (`++`) and decrement (`--`) operators, both pre and post
- Allows addition (`+`) and subtraction (`-`) of days to/from a date
- Overloads input (`>>`) and output (`<<`) stream operators for convenient date input/output

## Installation and dependencies

1. Clone the repository or download the source files.
2. Ensure you have a C++ compiler installed (e.g., GCC, Clang, MSVC).
It is important to note that the project has the following dependencies:
- `<iostream>`: For input/output stream operations.
- `<string>`: For string operations.
- `<iomanip>`: For stream manipulators used in output formatting.
- `<stdexcept>`: For exception handling.

## Usage

1. Include the `date.h` header file in your C++ source file.
2. Create instances of the `date` class by providing the month, day, and year as arguments to the constructor.
3. Use the provided methods and operators to manipulate and work with dates as needed.

Here's an example:

```cpp
#include <iostream>
#include "date.h"

int main() {
   date today(5, 27, 2024); // Create a date object for May 27, 2024
   std::cout << "Today's date: " << today << std::endl; // Output: Today's date: 2024-05-27

   date nextWeek = today + 7; // Add 7 days
   std::cout << "Next week: " << nextWeek << std::endl; // Output: Next week: 2024-06-03

   if (today < nextWeek) {
       std::cout << "Today is before next week." << std::endl;
   }

   return 0;
}
