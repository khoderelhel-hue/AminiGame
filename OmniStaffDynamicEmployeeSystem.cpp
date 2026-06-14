#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Employee
{
private:
    T name;
    T department;
    double salary;

public:
    Employee()
    {
        name = "undefined";
        department = "undefined";
        salary = 0.0;
    }

    Employee(T name, T department, double salary)
    {
        this->name = name;
        this->department = department;
        this->salary = salary;
    }

    T getName() { return name; }
    T getDepartment() { return department; }
    double getSalary() { return salary; }

    void giveRaise(double percentage)
    {
        salary = salary + (salary * percentage / 100);
    }

    void displayInfo()
    {
        cout << "Name = " << name << endl
             << "Department = " << department << endl
             << "Salary = " << salary << " USD" << endl;
    }
};

int main()
{
    Employee<string> staff[3] = {
        Employee<string>("Emre", "Software", 45000),
        Employee<string>("Selin", "Design", 38000),
        Employee<string>("Can", "Marketing", 32000)
    };

    for (int i = 0; i < 3; i++)
    {
        staff[i].giveRaise(15);
        staff[i].displayInfo();
        cout << endl;
    }

    double maxSalary = staff[0].getSalary();
    int maxIndex = 0;

    for (int i = 0; i < 3; i++)
    {
        if (staff[i].getSalary() >= maxSalary)
        {
            maxSalary = staff[i].getSalary();
            maxIndex = i;
        }
    }
    cout << "Employee with the highest salary = " << staff[maxIndex].getName() << endl;

    for (int i = 0; i < 3; i++)
    {
        if (staff[i].getDepartment() == "Software")
        {
            cout << staff[i].getName() << " works in the 'Software' Department..." << endl; 
        }
    }

    return 0;
}
