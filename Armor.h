//
//  Armor.h
//  League Group Project
//
//  Created by Dalton Rick on 10/9/15.
//  Copyright (c) 2015 Dalton Rick. All rights reserved.
//

#ifndef League_Group_Project_Armor_h
#define League_Group_Project_Armor_h
#include <iostream>
using namespace std;

class Armor{
    //friend class Equipment;
private:
    double armorBoost;
    int healthBoost;
    int manaBoost;
    double magicResistanceBoost;
    
    
    
public:
    //Default Constructor
    Armor() : armorBoost(0), healthBoost(0), manaBoost(0), magicResistanceBoost(0){}
    
    //Copy Constructor
    Armor(const Armor &data);
    //Default Constuctor
    
    // ** Setters (manipulators) **
    void setArmorBoost(double);
    void setHealthBoost(int);
    void setManaBoost(int);
    void setMagicResistanceBoost(double);
    
    // ** Accessors **
    double getArmorBoost(){ return armorBoost; }
    int getHealthBoost(){ return healthBoost; }
    int getManaBoost(){ return manaBoost; }
    double getMagicResistanceBoost(){ return magicResistanceBoost; }
    
    // ** Other Member Functions **
    
    void print();
    
};

void Armor::setArmorBoost(double ab){
    armorBoost = ab;
}
void Armor::setHealthBoost(int hb){
    healthBoost = hb;
}
void Armor::setManaBoost(int mb){
    manaBoost = mb;
}
void Armor::setMagicResistanceBoost(double mrb){
    magicResistanceBoost = mrb;
}
Armor::Armor(const Armor &data){
    armorBoost = data.armorBoost;
    healthBoost = data.healthBoost;
    manaBoost = data.manaBoost;
    magicResistanceBoost = data.magicResistanceBoost;
}

void Armor::print(){
    cout << "Armor Boost: " << armorBoost << endl;
    cout << "Health Boost: " << healthBoost << endl;
    cout << "Mana Boost: " << manaBoost << endl;
    cout << "Magic Resistance Boost: " << magicResistanceBoost << endl << endl;
    
}
#endif
