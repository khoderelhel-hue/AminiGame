#include <iostream>
#include <string>

using namespace std;

void checkArray(int const array[], int size);
void reportNegativeError(int value);
void reportOverLimitError(int value);

int main()
{
    int array[10] = {45, -12, 120, 300, 0, 85, -5, 150, 420, 90};
    int size = 10;

    checkArray(array, size);

    return 0;
}

void checkArray(int const array[], int size)
{
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0 && array[i] <= 300)
        {
            sum += array[i];
            counter++;
        }
        else if (array[i] < 0)
        {
            reportNegativeError(array[i]);
        }
        else if (array[i] > 300)
        {
            reportOverLimitError(array[i]);
        }
    }
    cout << "Average safe distance: " << sum / counter << endl;
}

void reportNegativeError(int value)
{
    cout << "Invalid measurement skipped: " << value << endl;
}

void reportOverLimitError(int value)
{
    cout << "High noise filtered" << endl;
}
