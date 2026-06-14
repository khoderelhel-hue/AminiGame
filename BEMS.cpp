#include <iostream>
using namespace std;

const int ROOM = 4;
const int FLOOR = 5;
const int HOUR = 8; 
const int DAY = 7;

double average(const double data[], int n);
double average(const int data[], int n);
int anomalyCount(const double temperature[], int n, double lowerLimit, double upperLimit);
void printWarning(const double temperature[], int n, double lower, double upper);
void floorReport(const double temperatures[][4], int floorCount, int roomCount);
int maxIndex(const double data[], int n);

int main() {
    double temperature[] = {21.5, 22.0, 25.5, 29.3, 30.1, 27.8, 23.0, 21.0};
    double floorRoom[FLOOR][ROOM] = { {22.1, 23.4, 21.8, 24.0},
                                      {20.5, 19.8, 21.2, 20.9},
                                      {25.6, 26.2, 24.8, 25.1},
                                      {18.2, 17.9, 18.5, 19.0},
                                      {23.0, 22.8, 23.5, 22.6} };
    double co2[] = {412.5, 680.3, 1250.8, 520.1, 890.4};
    double thisWeek[] = {120.5, 118.3, 125.7, 122.1, 119.8, 131.2, 128.6};
    double lastWeek[] = {115.2, 117.0, 119.8, 121.5, 118.4, 125.3, 124.1};

    double total = average(temperature, HOUR);
    cout << "Average temperature: " << total << endl;
    cout << "-------------------------" << endl;

    double lowerLimit = 18.0;
    double upperLimit = 28.0;
    int counter = anomalyCount(temperature, HOUR, lowerLimit, upperLimit);
    cout << "Anomaly value count: " << counter << endl;
    cout << "------------------------" << endl;

    printWarning(temperature, HOUR, lowerLimit, upperLimit);

    floorReport(floorRoom, FLOOR, ROOM);

    int critical = maxIndex(co2, ROOM);
    cout << "Critical CO2 floor: Floor " << critical << endl;

    double thisWeekAvg = average(thisWeek, DAY);
    double lastWeekAvg = average(lastWeek, DAY);

    cout << "Energy change percentage compared to last week: %" << (thisWeekAvg - lastWeekAvg) / lastWeekAvg * 100 << endl;

    return 0;
}

double average(const double data[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }
    double total = sum / n;
    return total;
}

double average(const int data[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }
    int total = sum / n;
    return total;
}

int anomalyCount(const double temperature[], int n, double lowerLimit, double upperLimit){
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (temperature[i] < lowerLimit || temperature[i] > upperLimit)
        {
            counter++;
        }
    }
    return counter;
}

void printWarning(const double temperature[], int n, double lower, double upper){
    for (int i = 0; i < n; i++)
    {
        if (temperature[i] < lower || temperature[i] > upper)
        {
            cout << "Critical temperature read: " << temperature[i] << endl;
            cout << "------------------------------------------" << endl;
        }
    }
}

void floorReport(const double temperatures[][4], int floorCount, int roomCount){
    for (int i = 0; i < floorCount; i++)
    {
        for (int j = 0; j < roomCount; j++)
        {
            cout << "Floor " << i + 1 << ", Room " << j + 1 << " temperature value: " << temperatures[i][j] << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

int maxIndex(const double data[], int n){
    int mindex = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] >= data[mindex])
        {
            mindex = i;
        }
    }
    return mindex + 1;
}
