#include <iostream>
#include <string>

using namespace std;

class SensorReading
{
private:
    int sensorID;
    double distance;
    int timestamp;

public:
    double total = 0;
    int counter = 0;

    SensorReading(int sensorID, double distance, int timestamp)
    {
        this->sensorID = sensorID;
        this->distance = distance;
        this->timestamp = timestamp;
    }

    void reportNoise()
    {
        cout << "noise detected" << endl;
    }

    void reportOutOfRange()
    {
        cout << "out of range" << endl;
    }

    void filterData(const SensorReading data[], int size, double &referenceAverage)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i].distance > 0 && data[i].distance <= 300)
            {
                total += data[i].distance;
                counter++;
            }
            else if (data[i].distance <= 0)
            {
                reportNoise();
            }
            else if (data[i].distance > 300)
            {
                reportOutOfRange();
            }
        }
        referenceAverage = (double) total / counter;
    }

    ~SensorReading()
    {
        cout << "object destroyed" << endl;
    }
};

int main()
{
    SensorReading sensors[5] = {
        SensorReading(101, 45.5, 1),
        SensorReading(102, -5.0, 2),
        SensorReading(103, 120.2, 3),
        SensorReading(101, 350.0, 4),
        SensorReading(102, 85.5, 5)
    };
    int size = 5;
    double average = 0.0;

    sensors[4].filterData(sensors, size, average);
    cout << "calculated average: " << average << endl;
    
    return 0;
}
