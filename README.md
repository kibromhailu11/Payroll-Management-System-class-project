# Payroll-Management-System-class-project

A comprehensive C++ console application designed for Addis Ababa Science and Technology University to manage employee records, calculate precise taxation, and generate formatted payroll reports.

## Features
Secure Data Entry: Validates names (letters only), ensures unique IDs, and checks for positive salary inputs.

Automated Taxation: Implements a multi-bracket tax system ranging from 0% to 35% based on salary levels.

Search Functionality: Quickly find specific employees by their First Name or Employee ID.

Formatted Reports: Displays data in a clean, tabular format with automatic column alignment for professional output.

## Taxation Logic
The system automatically calculates tax based on the following brackets:

>= 10,500: 35% Tax

8,500 - 10,499: 30% Tax

6,500 - 8,499: 25% Tax

4,500 - 6,499: 20% Tax

2,500 - 4,499: 15% Tax

1,000 - 2,499: 10% Tax

< 1,000: 0% Tax

## How to Run
Ensure you have a C++ compiler installed (like g++).

Clone the repository:

Bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git
Compile the program:

Bash
g++ main.cpp -o payroll_system
Run the application:

Bash
./payroll_system
## Technical Implementation
Language: C++

Concepts Used: Structs, Arrays, Input Validation, Modular Functions, and String Manipulation.

Institution: Addis Ababa Science and Technology University (AASTU).
