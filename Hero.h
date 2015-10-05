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
    
public:
    
//Default Constructor
    Hero(): name(""), health(0), mana(0), damageRating(0), attackDamage(0), attackSpeed(0.0), armor(0.0), magicResistance(0.0), movementSpeed(0) {}
    
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
    void setArmor(double);
    void setMagicResistance(double);
    void setMovementSpeed(int);
    
// ** Accessors **
    string getName();
    int getHealth();
    int getMana();
    int getAttackRange();
    int getAttackDamage();
    double getAttackSpeed();
    double getArmor();
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
    armor = data.armor;
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
void Hero::setAttackRange(int D_R){
    damageRating = D_R;
}
void Hero::setAttackDamage(int A_D){
    attackDamage = A_D;
}

void Hero::setAttackSpeed(double A_S){
    attackSpeed = A_S;
}
void Hero::setArmor(double AMR){
    armor = AMR;
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
    return damageRating;
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
double Hero::getArmor(){
    return armor;
}
int Hero::getMovementSpeed(){
    return movementSpeed;
}
void Hero::print(){
    
    cout << "Champion: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Mana: " << mana << endl;
    cout << "Attack Range: " << attackRange << endl;
    cout << "Attack Damage: " << attackDamage << endl;
    cout << "Attack Speed: " << attackSpeed << endl;
    cout << "Armor: " << armor << endl;
    cout << "Magic Resistance: " << magicResistance << endl;
    cout << "Movement Speed: " << movementSpeed << endl;
}
#endif /* defined(____Hero__) */
