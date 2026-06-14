#include <iostream>

using namespace std;

double filterSignal(double rawDistance);
void reportError();
bool isCriticalLevel(double distance);
void displaySystemStatus(double raw, double filtered);
void emergencyBrake();

int main()
{
    double sensor[6] = {25.5, -5.0, 30.2, 999.9, 4.0, 45.0};

    for (int i = 0; i < 6; i++)
    {
        double raw = sensor[i];     
        double clean = filterSignal(raw);
        displaySystemStatus(raw, clean);
        
        if (isCriticalLevel(clean))
        {
            emergencyBrake();
        }
    }

    return 0;
}

double filterSignal(double rawDistance) {
    static double lastValidDistance = 0.0;

    cout << "----------------------------------------" << endl;
    if (rawDistance >= 0 && rawDistance <= 100)
    {
        lastValidDistance = rawDistance;
        cout << "clean data: " << rawDistance << "m" << endl;
        return rawDistance;
    }
    else
    {
        reportError();
        return lastValidDistance;
    }
}

void reportError() {
    static int counter = 0;
    counter++;
    cout << "[SYSTEM]: Sensor error! Total Errors: " << counter << endl;
}

void displaySystemStatus(double raw, double filtered) {
    cout << "raw data: " << raw << "m" << endl << "filtered data: " << filtered << "m" << endl; 
}

bool isCriticalLevel(double distance) {
    if (distance > 0 && distance < 5.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void emergencyBrake() {
    cout << "Emergency brake activated..." << endl;
}
