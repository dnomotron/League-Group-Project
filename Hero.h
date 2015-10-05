//
//  Hero.h
//
//
//  Created by Dalton Rick on 10/2/15.
//
//

#ifndef ____Hero__
#define ____Hero__

#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Hero{
    
private:
    string name;
    int health;
    int mana; //
    int damageRating; // i.e. Ranged 550
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
    
    // Accessors
    
    // Getters
    void setName(string championName);
    string getName();
    void setHealth(int life);
    int getHealth();
    void setMana(int);
    int getMana();
    void setDamageRating(int);
    int getDamageRating();
    void setAttackDamage(int);
    int getAttackDamage();
    void setAttackSpeed(double);
    double getAttackSpeed();
    void setArmor(double);
    double getArmor();
    void setMagicResistance(double);
    double getMagicResistance();
    void setMovementSpeed(int);
    int getMovementSpeed();
    
    void print();
    
    
};

Hero::Hero(const Hero &data){
    
    name = data.name;
    health = data.health;
    mana = data.mana;
    damageRating = data.damageRating;
    attackDamage = data.attackDamage;
    attackSpeed = data.attackSpeed;
    armor = data.armor;
    magicResistance = data.magicResistance;
    movementSpeed = data.movementSpeed;
    
}

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
void Hero::setDamageRating(int D_R){
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
int Hero::getDamageRating(){
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
    cout << "Damage Rating: " << damageRating << endl;
    cout << "Attack Damage: " << attackDamage << endl;
    cout << "Attack Speed: " << attackSpeed << endl;
    cout << "Armor: " << armor << endl;
    cout << "Magic Resistance: " << magicResistance << endl;
    cout << "Movement Speed: " << movementSpeed << endl;
}
#endif /* defined(____Hero__) */