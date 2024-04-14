#include <iostream>
#include <iomanip> // for std::setprecision

using namespace std;

struct Employee {
    int id;
    string name;
    string department;
    string designation;
    string dob;
    string doj;
    double salary;
};

const int MAX_EMPLOYEES = 100; // Maximum number of employees
Employee employees[MAX_EMPLOYEES]; // Array to store employees
int numEmployees = 0; // Variable to keep track of the number of employees

void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        cout << "Maximum number of employees reached." << endl;
        return;
    }

    Employee& emp = employees[numEmployees++];
    cout << "Enter ID, Name, Department, Designation, Date of Birth, Date of Joining, and Salary: ";
    cin >> emp.id >> emp.name >> emp.department >> emp.designation >> emp.dob >> emp.doj >> emp.salary;
}

void displayAllEmployees() {
    if (numEmployees == 0) {
        cout << "No employees in the records." << endl;
        return;
    }
    for (int i = 0; i < numEmployees; ++i) {
        const Employee& emp = employees[i];
        cout << emp.id << " " << emp.name << " " << emp.department << " " << emp.designation << " " << emp.dob << " " << emp.doj << " " << emp.salary << endl;
    }
}

void displayEmployeesJoinedBefore(const string& date) {
    for (int i = 0; i < numEmployees; ++i) {
        const Employee& emp = employees[i];
        if (emp.doj < date) {
            cout << emp.id << " " << emp.name << " " << emp.department << " " << emp.designation << " " << emp.dob << " " << emp.doj << " " << emp.salary << endl;
        }
    }
}

void displayEmployeesJoinedAfter(const string& date) {
    for (int i = 0; i < numEmployees; ++i) {
        const Employee& emp = employees[i];
        if (emp.doj > date) {
            cout << emp.id << " " << emp.name << " " << emp.department << " " << emp.designation << " " << emp.dob << " " << emp.doj << " " << emp.salary << endl;
        }
    }
}

void searchEmployeeByID(int id) {
    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        const Employee& emp = employees[i];
        if (emp.id == id) {
            cout << emp.id << " " << emp.name << " " << emp.department << " " << emp.designation << " " << emp.dob << " " << emp.doj << " " << emp.salary << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found." << endl;
    }
}

void updateSalary(int id, double newSalary) {
    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        Employee& emp = employees[i];
        if (emp.id == id) {
            emp.salary = newSalary;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found." << endl;
    }
}

void deleteEmployeeByID(int id) {
    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].id == id) {
            for (int j = i; j < numEmployees - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            --numEmployees;
            cout << "Employee deleted successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found." << endl;
    }
}

void calculateStatistics() {
    if (numEmployees == 0) {
        cout << "No employees in the records." << endl;
        return;
    }

    double totalSalary = 0;
    double maxSalary = employees[0].salary;
    double minSalary = employees[0].salary;

    for (int i = 0; i < numEmployees; ++i) {
        const Employee& emp = employees[i];
        totalSalary += emp.salary;
        if (emp.salary > maxSalary) {
            maxSalary = emp.salary;
        }
        if (emp.salary < minSalary) {
            minSalary = emp.salary;
        }
    }

    cout << "Total employees: " << numEmployees << endl;
    cout << "Average salary: " << fixed << setprecision(2) << totalSalary / numEmployees << endl;
    cout << "Maximum salary: " << maxSalary << endl;
    cout << "Minimum salary: " << minSalary << endl;
}

int main() {
    while (true) {
        cout << "\n1. Add Employee\n2. Display All Employees\n3. Display Employees Joined Before a Date\n4. Display Employees Joined After a Date\n5. Search Employee by ID\n6. Update Employee Salary\n7. Delete Employee by ID\n8. Calculate Statistics\n9. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                {
                    string date;
                    cout << "Enter date: ";
                    cin >> date;
                    displayEmployeesJoinedBefore(date);
                }
                break;
            case 4:
                {
                    string date;
                    cout << "Enter date: ";
                    cin >> date;
                    displayEmployeesJoinedAfter(date);
                }
                break;
            case 5:
                {
                    int id;
                    cout << "Enter ID: ";
                    cin >> id;
                    searchEmployeeByID(id);
                }
                break;
            case 6:
                {
                    int id;
                    double newSalary;
                    cout << "Enter ID and new salary: ";
                    cin >> id >> newSalary;
                    updateSalary(id, newSalary);
                }
                break;
            case 7:
                {
                    int id;
                    cout << "Enter ID: ";
                    cin >> id;
                    deleteEmployeeByID(id);
                }
                break;
            case 8:
                calculateStatistics();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
