//  Dalton Rick, Nathan Foster, Kush Patel, Desmond Lee, Kurtis Hoang
//
//  CIS 22C
//
//  Group Project - Leaugue of Legends Character engine
//
//  Hero.h


#ifndef ____Hero__
#define ____Hero__

#include <string>
#include <iostream>
#include <iomanip>
#include "Equipment.h"
using namespace std;


class Hero{
    
private:
    string name;
    int health;
    int mana; //
    int attackRange; // i.e. Ranged 550
    int attackDamage;
    double attackSpeed;
    double armor;
    double magicResistance;
    int movementSpeed;
    int equippedCount;
    Equipment Inventory[6];
    
    
public:
    
//Default Constructor
	Hero() : name(""), health(0), mana(0), attackRange(0), attackDamage(0), attackSpeed(0.0), armor(0.0), magicResistance(0.0), movementSpeed(0), equippedCount(0) {}
    
//Copy Constructor
    Hero(const Hero &data);

//Default Constuctor
	~Hero();
    
// ** Setters (manipulators) **
    void setName(string championName);
    void setHealth(int life);
    void setMana(int);
    void setAttackRange(int);
    void setAttackDamage(int);
    void setAttackSpeed(double);
    void setarmor(double);
    void setMagicResistance(double);
    void setMovementSpeed(int);
	void setEquipment(const Equipment e);
    void zeroEquippedCount() {equippedCount = 0;};
    
// ** Accessors **
	string getName() { return name; };
    int getHealth() { return health; };
    int getMana() { return mana; };
    int getAttackRange() { return attackRange; };
    int getAttackDamage() { return attackDamage; };
    double getAttackSpeed() { return attackSpeed; };
    double getarmor() { return armor; };
    double getMagicResistance() { return magicResistance; };
    int getMovementSpeed() { return movementSpeed; };
    //Equipment getEquipment(int count) {return Inventory[count];};
    void removeEquipment(Equipment removed);
    int getEquippedCount() {return equippedCount;};
    //bool operator==(const Equipment &data);
    
// ** Other Member Functions **
    void print();
    void printEqiupment();
    
};

Hero::Hero(const Hero &data){
    
    name = data.name;
    health = data.health;
    mana = data.mana;
    attackRange = data.attackRange;
    attackDamage = data.attackDamage;
    attackSpeed = data.attackSpeed;
    armor = data.armor;
    magicResistance = data.magicResistance;
    movementSpeed = data.movementSpeed;
    equippedCount = data.equippedCount;
    
    
}
Hero::~Hero() {}

void Hero::setName(string championName)
{
    name = championName;
}
void Hero::setHealth(int life){
    health = life;
}
void Hero::setMana(int MA){
    mana = MA;
}
void Hero::setAttackRange(int A_R){
    attackRange = A_R;
}
void Hero::setAttackDamage(int A_D){
    attackDamage = A_D;
}

void Hero::setAttackSpeed(double A_S){
    attackSpeed = A_S;
}
void Hero::setarmor(double AMR){
    armor = AMR;
}
void Hero::setMagicResistance(double magRes){
    magicResistance = magRes;
}
void Hero::setMovementSpeed(int speed){
    movementSpeed = speed;
}

void Hero::setEquipment(const Equipment e){
    
    Equipment temp; Armor tempArmor; Weapon weapon;
    
     if (equippedCount < 6) {
         
        for (int i=0; i < equippedCount; i++) {
            temp = Inventory[i];
            if (temp == e) {
                    cout << "\nItem Already Equipped!\n";
                    return;
            }
        }
         
         Inventory[equippedCount] = e;
         
         
         if (Inventory[equippedCount].getType() == "Weapon") {
             weapon = Inventory[equippedCount].getWeapon();
             
             attackDamage += (weapon.getAttackDamage());
             
         }
         if (Inventory[equippedCount].getType() == "Armor"){
             tempArmor = Inventory[equippedCount].getArmor();
             armor += tempArmor.getArmorBoost();
             health += tempArmor.getHealthBoost();
             mana += tempArmor.getManaBoost();
             magicResistance += tempArmor.getMagicResistanceBoost();
         }
         equippedCount++;
         
         
    }else
    {
        cout << "\nEquipment Slots Full!\n";
    }
    
}

void Hero::removeEquipment(Equipment removed){
    
    bool found = false; int count = 0; Weapon tempWeapon; Armor tempArmor;
    
    if (removed.getType() == "Weapon") {
        while (found == false && count < equippedCount) {
            if (Inventory[count].getWeapon() == removed.getWeapon()) {
                found = true;
                for (int i = count; i < equippedCount; i++) {
                    Inventory[count] = Inventory[count+1];
                }
                equippedCount--;
                tempWeapon = removed.getWeapon();
                attackDamage -= tempWeapon.getAttackDamage();
                attackSpeed -= tempWeapon.getAttackSpeed();
            }
        }
    }else if(removed.getType() == "Armor"){
        while (found == false && count < equippedCount){
            if(Inventory[count].getArmor() == removed.getArmor()){
                found = true;
                for(int i= count; i < equippedCount; i++){
                    Inventory[count] = Inventory[count+1];
                }
                equippedCount--;
                tempArmor = removed.getArmor();
                armor -= tempArmor.getArmorBoost();
                health -= tempArmor.getHealthBoost();
                mana -= tempArmor.getManaBoost();
                magicResistance -= tempArmor.getMagicResistanceBoost();
            }
        }
    }
}

void Hero::print(){
    cout << setprecision(3);
    
    cout << left << "Champion:\t" << name << endl;
    cout << left << setw(20) <<  "Health: " <<  right << setw(6) << health << endl;
    cout << left << setw(20) << "Mana: " << right << setw(6) << mana << endl;
    cout << left << setw(20) << "Attack Range: " << right << setw(6) << attackRange << endl;
    cout << left << setw(20) << "Attack Damage: " << right << setw(6) << attackDamage << endl;
    cout << left << setw(20) << "Attack Speed: " << right << setw(6) << attackSpeed << endl;
    cout << left << setw(20) << "Armor: " << right << setw(6) << armor << endl;
    cout << left << setw(20) << "Magic Resistance: " << right << setw(6) << magicResistance << endl;
    cout << left << setw(20) << "Movement Speed: " << right << setw(6) << movementSpeed << endl;
    cout << left << setw(20) << "Equipped Items: " << right << setw(6) << equippedCount << endl;
}
void Hero::printEqiupment(){
    
    for (int i=0; i < equippedCount; i++) {
        Inventory[i].print();
    }
}
/*
 if (Inventory[equippedCount].getType() == "Weapon") {
 weapon = Inventory[equippedCount].getWeapon();
 
 tempInt = weapon.getAttackDamage(); cout << tempInt << endl;
 attackDamage += tempInt;
 cout << attackDamage << endl;
 tempDouble = weapon.getAttackSpeed(); cout << tempDouble << endl;
 attackSpeed += tempDouble;
 cout << attackSpeed << endl;
 equippedCount++;
 
 
 }else if (Inventory[equippedCount].getType() == "Armor"){
 tempArmor = Inventory[equippedCount].getArmor();
 cout << "This ran too" << endl;
 tempDouble = tempArmor.getArmorBoost();
 armor += tempDouble;
 tempInt = tempArmor.getHealthBoost();
 health += tempInt;
 tempInt = tempArmor.getManaBoost();
 mana += tempInt;
 tempDouble = tempArmor.getMagicResistanceBoost();
 magicResistance += tempDouble;
 equippedCount++;
 }else{
 cout << "\nCannot Equip Empty Equipment Slot!\n";
 }

 
 
 
 */








#endif /* defined(____Hero__) */
