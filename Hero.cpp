//
//  Hero.cpp
//
//
//  Created by Dalton Rick on 10/2/15.
//
//
#include <iostream>
#include "Hero.h"
using namespace std;

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
    
    cout << endl << endl << "Champion: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Mana: " << mana << endl;
    cout << "Damage Rating: " << damageRating << endl;
    cout << "Attack Damage: " << attackDamage << endl;
    cout << "Attack Speed: " << attackSpeed << endl;
    cout << "Armor: " << armor << endl;
    cout << "Magic Resistance: " << magicResistance << endl;
    cout << "Movement Speed: " << movementSpeed << endl;
}