#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> numbers;
    
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    numbers.pop_back();

    numbers[0] = 99;
    numbers.clear();
    
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}
