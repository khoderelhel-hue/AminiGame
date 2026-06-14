#include <iostream>
#include <string>

using namespace std;

class EngineControlUnit
{
private:
    int rpm;
    double engineTemperature;
    bool checkEngineLight;

public:
    EngineControlUnit() {
        rpm = 0;
        engineTemperature = 25.0;
        checkEngineLight = false;
    }

    EngineControlUnit(int rpm, double engineTemperature)
    {
        this->rpm = rpm;
        this->engineTemperature = engineTemperature;
        this->checkEngineLight = false;
    }

    int getRpm()
    {
        return rpm;
    }

    double getEngineTemperature()
    {
        return engineTemperature;
    }

    void setParameters(int newRpm, double newTemperature)
    {
        if (newRpm > 7000)
        {
            cout << "High RPM! Error code: ERR_RPM" << endl;
            checkEngineLight = true;
            rpm = newRpm;
        }
        if (newTemperature > 110.0)
        {
            cout << "Engine overheated! Error code: ERR_TEMP" << endl;
            checkEngineLight = true;
            engineTemperature = newTemperature;
        }
    }

    bool isCheckEngineLightActive() {
        return checkEngineLight;
    }

    ~EngineControlUnit()
    {
        cout << "object destroyed" << endl;
    }
};

int main()
{
    EngineControlUnit engine1{3000, 85.5};
    cout << engine1.isCheckEngineLightActive() << endl;
    engine1.setParameters(7500, 115.0);
    return 0;
}
