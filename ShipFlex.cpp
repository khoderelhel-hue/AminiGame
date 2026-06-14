#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class CargoWarehouse
{
private:
    vector<T> cargoList;
public:
    CargoWarehouse(){

    }
    void addCargo(T weight){
        cargoList.push_back(weight);
    }
    void listCargo(){
        for (int i = 0; i < cargoList.size(); i++)
        {
            cout << i + 1 << ". Cargo weight: " << cargoList[i] << endl; 
        }
    }
};

int main()
{
    CargoWarehouse<double> myWarehouse; 
    
    myWarehouse.addCargo(5.5);   
    myWarehouse.addCargo(12.3);
    myWarehouse.addCargo(0.8);
    
    myWarehouse.listCargo(); 
    
    return 0;
}
