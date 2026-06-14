#include <iostream>
#include <string>
using namespace std;

void printCharacter(string name, int hp, int atk, int arm);
void takeDamage(int *hp, int damage);
void levelUp(int &hp, int &attack, int &armor, double multiplier);
void swapEquipment(int &attack1, int &armor1, int &attack2, int &armor2);
int* getLowestHP(int *hp1, int *hp2, int *hp3);

int main()
{
    
    string name1 = "Warrior", name2 = "Mage", name3 = "Guardian";

    int hp1 = 150, atk1 = 80, arm1 = 60;
    int hp2 = 90, atk2 = 120, arm2 = 30;
    int hp3 = 200, atk3 = 40, arm3 = 90;

    cout << "--- Characters are Ready ---" << endl;

    
    printCharacter(name1, hp1, atk1, arm1);
    printCharacter(name2, hp2, atk2, arm2);
    printCharacter(name3, hp3, atk3, arm3);
    cout << endl;

    
    takeDamage(&hp1, 50);
    takeDamage(&hp2, 100);

    cout << endl << "[Battle Started]" << endl;
    cout << "Damaged characters... " << name1 << " <> " << name2 << endl;
    cout << "New HP values: " << hp1 << " <> " << hp2 << endl;
    cout << "\n[Combat Resolved]" << endl;

    
    levelUp(hp3, atk3, arm3, 1.5);
    cout << endl << "Guardian leveled up with a 1.5 multiplier." << endl;
    cout << "New Guardian stats... HP: " << hp3 << " | Atk: " << atk3 << " | Arm: " << arm3 << endl;
    cout << "\n[Guardian Leveled Up!]" << endl;

    
    swapEquipment(atk1, arm1, atk2, arm2);

    cout << endl << "Warrior and Mage are swapping their equipment..." << endl;
    cout << "Warrior's new attack and armor: " << atk1 << " <> " << arm1 << endl;
    cout << "Mage's new attack and armor: " << atk2 << " <> " << arm2 << endl;
    cout << "\n[Equipment Swapped!]" << endl;
    
    
    
    cout << "\n[Applying Critical Healing...]" << endl;
    int* weakAddress = getLowestHP(&hp1, &hp2, &hp3);
    
    
    *weakAddress += 50; 

    cout << "Character with the lowest HP found and healed by 50." << endl;
    cout << "New HP value: " << *weakAddress << " (Address: " << weakAddress << ")" << endl;
    
    
    cout << "\n=== END OF GAME STATISTICS ===" << endl;
    
    printCharacter(name1, hp1, atk1, arm1);
    printCharacter(name2, hp2, atk2, arm2);
    printCharacter(name3, hp3, atk3, arm3);

    return 0;
}

void printCharacter(string name, int hp, int atk, int arm){
    cout << endl << " Character Name: " << name <<
    endl << " Character HP: " << hp <<
    endl << " Character Atk: " << atk <<
    endl << " Character Arm: " << arm;
    cout << endl << "---------------------------";
} 

void takeDamage(int *hp, int damage){
    *hp = *hp - damage;
    if (*hp < 0)
    {
        *hp = 0;
    }
}

void levelUp(int &hp, int &attack, int &armor, double multiplier){
    hp = hp * multiplier;
    armor = armor * multiplier;
    attack = attack * multiplier;
}

void swapEquipment(int &attack1, int &armor1, int &attack2, int &armor2){
    int tempAtk = attack1;
    attack1 = attack2;
    attack2 = tempAtk;

    int tempArm = armor1;
    armor1 = armor2;
    armor2 = tempArm;
}

int* getLowestHP(int *hp1, int *hp2, int *hp3) {
    int *lowestAddress = hp1;

    if (*hp2 < *lowestAddress) {
        lowestAddress = hp2;
    }
    if (*hp3 < *lowestAddress) {
        lowestAddress = hp3;
    }

    return lowestAddress; // Return the original address of the lowest HP
}
