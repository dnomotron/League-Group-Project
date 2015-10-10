//  Dalton Rick, Nathan Foster, Kush Patel, Desmond Lee, Kurtis Hoang
//
//  CIS 22C
//
//  Group Project - Leaugue of Legends Character engine
//
//  Equipment.h

#ifndef ____Equipment__
#define ____Equipment__

#include "Hero.h"
using namespace std;

//***************************************************************************************************************************************WEAPON
class Weapon {
	friend class Equipment;
private:
	string weaponName;
	int attackDamageBoost;
	double attackSpeedBoost;

public:
	//Default Constructor
    Weapon(): weaponName(""), attackDamageBoost(0), attackSpeedBoost(0.0) {}
	//Weapon(string name, int damage, double speed){ weaponName = name, attackDamageBoost = damage, attackSpeedBoost = speed; }

	//Copy Constructor
    
	// ** Setters (manipulators) **
	void setWeaponName(string);
	void setAttackDamageBoost(int);
	void setattackSpeedBoost(double);

	// ** Accessors **
	string getWeaponName(){ return weaponName; }
	int getAttackDamage() { return attackDamageBoost; }
	double getAttackSpeed() { return attackSpeedBoost; }

	// ** Other Member Functions **
    void print();
};

void Weapon::setWeaponName(string name){
	weaponName = name;
}

void Weapon::setAttackDamageBoost(int damage){
	attackDamageBoost = damage;
}

void Weapon::setattackSpeedBoost(double speed){
	attackSpeedBoost = speed;
}
void Weapon::print(){
    cout << "Weapon Name: " << weaponName << endl;
    cout << "Attack Damage Boost: " << attackDamageBoost << endl;
    cout << "Attack Speed Boost: " << attackSpeedBoost << endl;
}

//***************************************************************************************************************************************ARMOR
class Armor{
	friend class Equipment;
private:
	string armorName;
	double armorBoost;
	int healthBoost;
	int manaBoost;
	double magicResistanceBoost;



public:
	//Default Constructor
	Armor() : armorName("Default Armor"), armorBoost(0), healthBoost(0), manaBoost(0), magicResistanceBoost(0){}

	//Copy Constructor

	//Default Constuctor

	// ** Setters (manipulators) **
	void setArmorName(string);
	void setArmorBoost(double);
	void setHealthBoost(int);
	void setManaBoost(int);
	void setMagicResistanceBoost(double);

	// ** Accessors **
	string getArmorName(){ return armorName; }
	double getArmorBoost(){ return armorBoost; }
	int getHealthBoost(){ return healthBoost; }
	int getManaBoost(){ return manaBoost; }
	double getMagicResistanceBoost(){ return magicResistanceBoost; }

	// ** Other Member Functions **


};

void Armor::setArmorName(string name){
	armorName = name;
}
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

//***************************************************************************************************************************************EQUIPMENT
class Equipment{
private:
	bool equipped;
    string type;
    Weapon weapon;
    Armor armor;

public:
    
    Equipment(): equipped(false), type("") {}
    
    
    // ** Setters **
    void setType(string typespecifier);
    void setEquipped(bool status);
    void setWeapon(Weapon e);
    void setArmor(Armor a);
    

	// ** Getters **
	bool getEquipped();
    string getType();
    int getWeapon();
    
    // ** Other Functions **
    void print();
};

void Equipment::setType(string typespecifier){
    type = typespecifier;
}
void Equipment::setEquipped(bool status){
    equipped = status;
    
}
void Equipment::setWeapon(Weapon e){
    type = "Weapon";
    weapon.setAttackDamageBoost(e.getAttackDamage());
    weapon.setattackSpeedBoost(e.getAttackSpeed());
    weapon.setWeaponName(e.getWeaponName());
    
}
void Equipment::setArmor(Armor a){
    type = "Armor";
    armor.setArmorBoost(a.getArmorBoost());
    armor.setHealthBoost(a.getHealthBoost());
    armor.setMagicResistanceBoost(a.getMagicResistanceBoost());
    armor.setManaBoost(a.getManaBoost());
    armor.setArmorName(a.getArmorName());
    
}
void Equipment::print(){
    
    if (type == "Weapon") {
        cout << "Weapon Name: " << weapon.getWeaponName() << endl;
        cout << "Attack Damage: " << weapon.getAttackDamage() << endl;
        cout << "Attack Speed: " << weapon.getAttackSpeed() << endl;
    }else if(type == "Armor"){
        
        cout << "Armor Name: " << armor.getArmorName() << endl;
        cout << "Armor Boost: " << armor.getArmorBoost() << endl;
        cout << "Health Boost: " << armor.getHealthBoost() << endl;
        cout << "Magic Resistance: " << armor.getMagicResistanceBoost() << endl;
        cout << "Mana Boost: " << armor.getManaBoost() << endl;
        
    }
    else{
        cout << "\nEmpty Weapon Slot!" << endl;
    }
}
#endif /* defined(____Equipment__) */