// 12.5 wap in c++ reading and writing n employee data (using array) with file handling function
#include <iostream>
#include <fstream>
using namespace std;
class Employee
{
private:
    char name[20];
    int id;
    double salary;

public:
    void input()
    {
        cout << "Enter the name of employee: " << endl;
        cin >> name;
        cout << "Enter the employee id: " << endl;
        cin >> id;
        cout << "Enter the salary: " << endl;
        cin >> salary;
    }
    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
    void write(fstream &file)
    {
        file << name << endl
             << id << endl
             << salary << endl;
    }
    void read(fstream &file)
    {
        file >> name >> id >> salary;
    }
};
int main()
{
    fstream file;
    file.open("emp.txt", ios::in | ios::out);
    if (!file)
    {
        cout << "File could not be opened" << endl;
        return 1;
    }
    int n;
    cout << "Enter number of employees: " << endl;
    cin >> n;
    Employee E[50];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter employee " << i + 1 << " data: " << endl;
        E[i].input();
        E[i].write(file);
    }
    cout << "Data from the file\n";
    for (int i = 0; i < n; i++)
    {
        E[i].read(file);
        E[i].show();
    }
    file.close();
    return 0;
}

// Output:
// Enter number of employees:
// 2
// Enter employee 1 data:
// Enter the name of employee:
// harsh
// Enter the employee id:
// 101
// Enter the salary:
// 120000
// Enter employee 2 data:
// Enter the name of employee:
// garvit
// Enter the employee id:
// 102
// Enter the salary:
// 103000
// Data from the file
// Name: harsh
// Id: 101
// Salary: 120000
// Name: garvit
// Id: 102
// Salary: 103000
