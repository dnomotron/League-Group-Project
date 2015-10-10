//  Dalton Rick, Nathan Foster, Kush Patel, Desmond Lee, Kurtis Hoang
//
//  CIS 22C
//
//  Group Project - Leaugue of Legends Character engine
//
//  Equipment.h

#ifndef ____Equipment__
#define ____Equipment__

#include "Armor.h"
#include "Weapon.h"

using namespace std;

class Equipment{
private:
    string name;
	bool equipped;
    string type;
    void *pointer;

public:
    
    Equipment(): equipped(false), type(""), pointer(NULL) {}
    // ** Setters **
    void setType(string typespecifier);
    void setEquipped(bool status);
    void setPointer(Weapon);
    void setPointer(Armor);
    void Equip();
    void Dequip();
    
	// ** Getters **
	bool getEquipped();
    string getType();
    void * getPointer();
    
    
    // ** Other Functions **
    void print();
};

void Equipment::setType(string typespecifier){
    type = typespecifier;
}
void Equipment::setPointer(Weapon w){
    pointer = new Weapon(w);
    
}
void Equipment::setPointer(Armor a){
    pointer = new Armor(a);
}
void Equipment::Equip(){
    equipped = true;
}
void Equipment::Dequip(){
    equipped = false;
}
void * Equipment::getPointer(){
    
    if (type == "Weapon") {
        return static_cast<Weapon*>(pointer);
    }else if (type == "Armor")
    {
        return static_cast<Armor*>(pointer);
    }else
    return NULL;
}


void Equipment::print(){
    
    if (pointer == NULL) {
        cout << "\nEmpty Equipment Slot!\n";
    }
    else{
        cout << endl << "Name: " << name << endl;
        cout << "Equipped: ";
        if (equipped == true)
        { cout << "Yes" << endl;}
        else
        {cout << "No" << endl;}
        
        cout << "Type: " << type << endl;
        if (type == "Weapon")
        {static_cast<Weapon*>(pointer)->print();}
        else
        { static_cast<Armor*>(pointer)->print();}
    
}





#endif /* defined(____Equipment__) */