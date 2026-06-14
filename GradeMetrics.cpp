#include <iostream>
using namespace std;

double enterGrades(int *array, int n);
double calculateAverage(const int *array, int n);

int main()
{
    int n = 0;
    cout << "How many students are there: ";
    cin >> n;

    int *grades = new int[n];

    enterGrades(grades, n);
    cout << "Average of student grades: " << calculateAverage(grades, n) << endl;

    delete[] grades;
    grades = nullptr;
    return 0;
}

double enterGrades(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter grade for Student " << i + 1 << ": ";
        cin >> array[i];
    }
    return *array;
}

double calculateAverage(const int *array, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum / n;
}
