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



#endif /* defined(____Hero__) */