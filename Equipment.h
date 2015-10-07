
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


class Equipment{

private:
public:

};

class Weapon : Equipment{

private:
	string weaponName;
	int attackDamageBoost;
	double attackSpeedBoost;

public:
	//Default Constructor
	Weapon() : weaponName("Default Weapon"), attackDamageBoost(0), attackSpeedBoost(0.0){}

	//Copy Constructor

	//Default Constuctor
	
	// ** Setters (manipulators) **
	void setWeaponName(string);
	void setAttackDamageBoost(int);
	void setattackSpeedBoost(double);

	// ** Accessors **
	string getWeaponName();
	int getAttackDamage();
	double getAttackSpeed();

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


class Armor : Equipment{

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


	// ** Accessors **

	// ** Other Member Functions **


};

#endif /* defined(____Equipment__) */