#include <iostream>
using namespace std;

int* registerPatients(int n);
void enterScores(int* patients, int n);
double calculateAverage(const int* patients, int n);
int maximumScore(const int* patients, int n);
int minimumScore(const int* patients, int n);
int* addPatient(int* oldList, int oldN, int newScore);

int main() {
    int n;
    cout << "How many patients are there? "; 
    cin >> n;
    int *patients = registerPatients(n);
    enterScores(patients, n);
    cout << "average pain value: " << calculateAverage(patients, n) << endl;
    cout << "max pain value: " << maximumScore(patients, n) << endl;
    cout << "min pain value: " << minimumScore(patients, n) << endl;
    int newScore;
    cout << "New patient score: "; 
    cin >> newScore;
    patients = addPatient(patients, n, newScore);
    n++;
    cout << "\nUpdated Pain Scores List: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Patient " << i + 1 << ": " << patients[i] << endl;
    }
    cout << "New Average: " << calculateAverage(patients, n) << endl;
    delete[] patients;
    patients = nullptr;
    return 0;
}

int* registerPatients(int n){
    int* patients = new int[n]();
    return patients;
}

void enterScores(int* patients, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter pain score for Patient " << i + 1 << " (1 - 10): " << endl;
        cin >> patients[i];

        if (patients[i] < 1 || patients[i] > 10)
        {
            cout << "You entered an invalid score... Please enter again." << endl;
            i--;
        }
    }
}

double calculateAverage(const int* patients, int n){
    double t = 0;
    for (int i = 0; i < n; i++)
    {
        t += patients[i];
    }
    return (double)(t / n);
}

int maximumScore(const int* patients, int n){
    int maxVal = patients[0];
    for (int i = 1; i < n; i++)
    {
        if (patients[i] >= maxVal) maxVal = patients[i];
    }
    return maxVal;
}

int minimumScore(const int* patients, int n){
    int minVal = patients[0];
    for (int i = 1; i < n; i++)
    {
        if (patients[i] <= minVal) minVal = patients[i];
    }
    return minVal;
}

int* addPatient(int* oldList, int oldN, int newScore){
    int* newList = new int[oldN + 1];
    for (int i = 0; i < oldN; i++)
    {
        newList[i] = oldList[i];
    }
    newList[oldN] = newScore;

    delete[] oldList;

    return newList;
}
