#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ClassManagement
{
private:
    vector<string> students;    
public:
    ClassManagement(){
        
    }
    ClassManagement(vector<string> students){
        this->students = students;
    }
    void addStudent(string name){
        students.push_back(name);
    }
    void listStudents(){
        for (int i = 0; i < students.size(); i++)
        {
            cout << i + 1 << ". Student: " << students[i] << endl;
        }
    }
};

int main()
{
    ClassManagement myClass; 
    
    myClass.addStudent("Emre");   
    myClass.addStudent("Selin");
    
    myClass.listStudents(); 
    return 0;
}
