#include <iostream>
#include <string>
#include <limits>

using namespace std;

// This structure groups all data for one employee
struct Employee {
    string firstName;
    string fatherName;
    char gender;
    string id;
    string department;
    double salary;
    double tax;
    double netPayment;
};

int employeeCount = 0;

// This function calculates tax based on the salary amount
double calculateTax(double salary) {
    if (salary >= 10500)
    return salary * 0.35;
    else if (salary >= 8500 && salary <1050)
     return salary * 0.30;
    else if (salary >= 6500 && salary <8500)
    return salary * 0.25;
    else if (salary >= 4500 && salary <6500)
     return salary * 0.20;
    else if (salary >= 2500  && salary <4500)
    return salary * 0.15;
    else if (salary >= 1000 && salary <2500)
    return salary * 0.10;
    else return 0.0;
}

void recordStaff(Employee staffList[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter information for employee " << i + 1 << ":\n";

        // Validation for First Name (letters only, length >= 2)
        bool validFirst = false;
        while (!validFirst) {
            cout << "First Name: ";
            cin >> staffList[i].firstName;
            if (staffList[i].firstName.length() < 2) {
                cout << "Error: Name must be at least 2 letters long.\n";
            } else {
                validFirst = true;
                for (int k = 0; k < staffList[i].firstName.length(); k++) {
                    if (!((staffList[i].firstName[k] >= 'a' && staffList[i].firstName[k] <= 'z') ||
                          (staffList[i].firstName[k] >= 'A' && staffList[i].firstName[k] <= 'Z'))) {
                        validFirst = false;
                        cout << "Error: Name should only contain letters.\n";
                        break;
                    }
                }
            }
        }

        // Validation for Father's Name (letters only, length >= 2)
        bool validFather = false;
        while (!validFather) {
            cout << "Father's Name: ";
            cin >> staffList[i].fatherName;
            if (staffList[i].fatherName.length() < 2) {
                cout << "Error: Name must be at least 2 letters long.\n";
            } else {
                validFather = true;
                for (int k = 0; k < staffList[i].fatherName.length(); k++) {
                    if (!((staffList[i].fatherName[k] >= 'a' && staffList[i].fatherName[k] <= 'z') ||
                          (staffList[i].fatherName[k] >= 'A' && staffList[i].fatherName[k] <= 'Z'))) {
                        validFather = false;
                        cout << "Error: Name should only contain letters.\n";
                        break;
                    }
                }
            }
        }

        // Validation for Gender
        char tempGender;
        bool validGender = false;
        while (!validGender) {
            cout << "Gender (M/F): ";
            cin >> tempGender;
            if (tempGender == 'm' || tempGender == 'M' || tempGender == 'f' || tempGender == 'F') {
                validGender = true;
            } else {
                cout << "Invalid input! Use M or F.\n";
            }
        }
        staffList[i].gender = (char)toupper(tempGender);

        // Validation for ID (length >= 2, must contain at least one digit)
        string tempID;
        bool validID = false;
        while (!validID) {
            bool idExists = false;
            bool hasDigit = false;
            cout << "ID: ";
            cin >> tempID;

            if (tempID.length() < 2) {
                cout << "Error: ID must be at least 2 characters.\n";
                continue;
            }

            for (int k = 0; k < tempID.length(); k++) {
                if (tempID[k] >= '0' && tempID[k] <= '9') hasDigit = true;
            }

            if (!hasDigit) {
                cout << "Error: ID must include at least one number.\n";
                continue;
            }

            for (int j = 0; j < i; j++) {
                if (staffList[j].id == tempID) {
                    idExists = true;
                    cout << "Error: This ID is already used. Try another.\n";
                    break;
                }
            }
            if (!idExists) validID = true;
        }
        staffList[i].id = tempID;

        cout << "Department: ";
        cin >> staffList[i].department;

        // Loop for valid salary input
        cout << "Salary: ";
        while (!(cin >> staffList[i].salary) || staffList[i].salary < 0) {
            cout << "Invalid! Enter a positive number for Salary: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        staffList[i].tax = calculateTax(staffList[i].salary);
        staffList[i].netPayment = staffList[i].salary - staffList[i].tax;

        employeeCount++;
    }
}

// Function for the top of the report
void printReportHeader() {
    cout << "\n*******************************************************************************\n";
    cout << "                Addis Ababa Science and Technology University\n";
    cout << "                          Employee Information\n";
    cout << "*******************************************************************************\n";
    cout << "ID\tFull Name\t\tGender\tSalary\tTax\tNet Pay\n";
    cout << "-------------------------------------------------------------------------------\n";
}

// Function to print a row for one employee
void displayEmployee(Employee emp) {
    // Print ID
    cout << emp.id << "\t";

    // Combine names
    string fullName = emp.firstName + " " + emp.fatherName;
    cout << fullName;

    // Logic to keep the table columns matched up correctly
    if (fullName.length() < 8) {
        cout << "\t\t\t";
    } else if (fullName.length() < 16) {
        cout << "\t\t";
    } else {
        cout << "\t";
    }

    // Print the rest of the data
    cout << emp.gender << "\t"
         << emp.salary << "\t"
         << emp.tax << "\t"
         << emp.netPayment << endl;
}

void displayStaffInformation(Employee staffList[]) {
    if (employeeCount == 0) {
        cout << "No records found.\n";
        return;
    }
    printReportHeader();
    for (int i = 0; i < employeeCount; ++i) {
        displayEmployee(staffList[i]);
    }
}

void searchStaff(Employee staffList[]) {
    if (employeeCount == 0) {
        cout << "No data recorded yet.\n";
        return;
    }
    string searchQuery;
    cout << "Search by First Name or ID: ";
    cin >> searchQuery;
    bool found = false;
    bool headerPrinted = false;

    for (int i = 0; i < employeeCount; ++i) {
        if (staffList[i].firstName == searchQuery || staffList[i].id == searchQuery) {
            if (!headerPrinted) {
                printReportHeader();
                headerPrinted = true;
            }
            // Calling the display helper function to ensure table alignment matches
            displayEmployee(staffList[i]);
            found = true;
        }
    }
    if (!found) cout << "\nEmployee not found.\n";
}

int main() {
    int n;
    cout << "=============================================\n";
    cout << "    WELCOME TO EMPLOYEE MANAGEMENT SYSTEM    \n";
    cout << "=============================================\n";

    cout << "Enter total number of employees to register: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Array to store employee data
    Employee staffList[100];

    recordStaff(staffList, n);

    int choice = 0;
    while (choice != 3) {
        cout << "\nMain Menu:\n";
        cout << "1. Display All Staff Members\n";
        cout << "2. Search Staff\n";
        cout << "3. Exit Program\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: displayStaffInformation(staffList); break;
            case 2: searchStaff(staffList); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}
