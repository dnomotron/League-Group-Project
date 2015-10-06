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
using namespace std;


class Hero{
    
private:
    string name;
    int health;
    int mana; //
    int attackRange; // i.e. Ranged 550
    int attackDamage;
    double attackSpeed;
    double armorClass;
    double magicResistance;
    int movementSpeed;
	bool wearingEquipment;
	int weapon;
	int armor;
    
public:
    
//Default Constructor
	Hero() : name(""), health(0), mana(0), attackRange(0), attackDamage(0), attackSpeed(0.0), armorClass(0.0), magicResistance(0.0), movementSpeed(0), wearingEquipment(false), weapon(0), armor(0) {}
    
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
    void setarmorClass(double);
    void setMagicResistance(double);
    void setMovementSpeed(int);
    
// ** Accessors **
    string getName();
    int getHealth();
    int getMana();
    int getAttackRange();
    int getAttackDamage();
    double getAttackSpeed();
    double getarmorClass();
    double getMagicResistance();
    int getMovementSpeed();
    
// ** Other Member Functions **
    void print();
    
    
};

Hero::Hero(const Hero &data){
    
    name = data.name;
    health = data.health;
    mana = data.mana;
    attackRange = data.attackRange;
    attackDamage = data.attackDamage;
    attackSpeed = data.attackSpeed;
    armorClass = data.armorClass;
    magicResistance = data.magicResistance;
    movementSpeed = data.movementSpeed;
    
}

Hero::~Hero()
{}

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
void Hero::setarmorClass(double AMR){
    armorClass = AMR;
}
void Hero::setMagicResistance(double magRes){
    magicResistance = magRes;
}
void Hero::setMovementSpeed(int speed){
    movementSpeed = speed;
}
string Hero::getName()
{
    return name;
}

int Hero::getHealth(){
    return health;
}
int Hero::getMana(){
    return mana;
}
int Hero::getAttackRange(){
    return attackRange;
}
int Hero::getAttackDamage(){
    return attackDamage;
}
double Hero::getAttackSpeed(){
    return attackSpeed;
}
double Hero::getMagicResistance(){
    return magicResistance;
}
double Hero::getarmorClass(){
    return armorClass;
}
int Hero::getMovementSpeed(){
    return movementSpeed;
}
void Hero::print(){
    cout << setprecision(3);
    
    cout << left << "Champion:\t" << name << endl;
    cout << left << setw(20) <<  "Health: " <<  right << setw(6) << health << endl;
    cout << left << setw(20) << "Mana: " << right << setw(6) << mana << endl;
    cout << left << setw(20) << "Attack Range: " << right << setw(6) << attackRange << endl;
    cout << left << setw(20) << "Attack Damage: " << right << setw(6) << attackDamage << endl;
    cout << left << setw(20) << "Attack Speed: " << right << setw(6) << attackSpeed << endl;
    cout << left << setw(20) << "armorClass: " << right << setw(6) << armorClass << endl;
    cout << left << setw(20) << "Magic Resistance: " << right << setw(6) << magicResistance << endl;
    cout << left << setw(20) << "Movement Speed: " << right << setw(6) << movementSpeed << endl;
}
#endif /* defined(____Hero__) */
