
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


class Weapon {
	friend class Equipment;
private:
	string weaponName;
	int attackDamageBoost;
	double attackSpeedBoost;

public:
	//Default Constructor
	Weapon(string name, int damage, double speed){ weaponName = name, attackDamageBoost = damage, attackSpeedBoost = speed; }

	//Copy Constructor

	//Default Constuctor
	
	// ** Setters (manipulators) **
	void setWeaponName(string);
	void setAttackDamageBoost(int);
	void setattackSpeedBoost(double);

	// ** Accessors **
	string getWeaponName(){ return weaponName; }
	int getAttackDamage() { return attackDamageBoost; }
	double getAttackSpeed() { return attackSpeedBoost; }

	// ** Other Member Functions **
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
	string Armor::getArmorName(){ return armorName; }
	double Armor::getArmorBoost(){ return armorBoost; }
	int Armor::getHealthBoost(){ return healthBoost; }
	int Armor::getManaBoost(){ return manaBoost; }
	double Armor::getMagicResistanceBoost(){ return magicResistanceBoost; }

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

class Equipment{
private:
	bool equipped;

public:
	void showSeceret(Weapon e, Armor a)
	{
		cout << e.getAttackDamage() << endl;
		cout << a.getArmorBoost() << endl;
	}
	// ** Setters **
	void setEquipped(bool status);

	// ** Getters **
	bool getEquipped();
	//void Equipment::setEquipped(bool status){
		//equipped = status;
	//}
	//bool Equipment::getEquipped(){
		//return equipped;
	//}
};
#endif /* defined(____Equipment__) */