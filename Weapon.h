//
//  Weapon.h
//  League Group Project
//
//  Created by Dalton Rick on 10/9/15.
//  Copyright (c) 2015 Dalton Rick. All rights reserved.
//

#ifndef League_Group_Project_Weapon_h
#define League_Group_Project_Weapon_h
#include <iostream>
using namespace std;

class Weapon {
    //friend class Equipment;
private:
    int attackDamageBoost;
    double attackSpeedBoost;
    
public:
    //Default Constructor
    Weapon(): attackDamageBoost(0), attackSpeedBoost(0.0) {}
    
    
    //Copy Constructor
    Weapon(const Weapon &data);
    
    // ** Setters (manipulators) **
    void setAttackDamageBoost(int);
    void setattackSpeedBoost(double);
    
    // ** Accessors **
    int getAttackDamageBoost() { return attackDamageBoost; }
    double getAttackSpeedBoost() { return attackSpeedBoost; }
    
    // ** Other Member Functions **
    void print();
};


void Weapon::setAttackDamageBoost(int damage){
    attackDamageBoost = damage;
}

void Weapon::setattackSpeedBoost(double speed){
    attackSpeedBoost = speed;
}

Weapon::Weapon(const Weapon &data){
    attackDamageBoost = data.attackDamageBoost;
    attackSpeedBoost = data.attackSpeedBoost;
}



void Weapon::print(){
    cout << "Attack Damage Boost: " << attackDamageBoost << endl;
    cout << "Attack Speed Boost: " << attackSpeedBoost << endl << endl;
}
#endif
