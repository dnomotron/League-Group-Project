//
//  main.cpp
//  League Group Project
//
//  Created by Dalton Rick on 10/2/15.

#include "List.h"
#include <fstream>


void getData(List<Hero>* list);
///////////////////////////////////////////////////////////  - Main Test Driver
int main(int argc, const char * argv[]) {
    
    //creating a new list object L
    
    List<Hero> Champions;
    
    Hero data;
    
    data.setName("Lux");
    data.setHealth(478);
    data.setMana(334);
    data.setDamageRating(550);
    data.setAttackDamage(54);
    data.setAttackSpeed(0.625);
    data.setArmor(18.7);
    data.setMovementSpeed(330);
    
    
    //Champions.push_front(data);
    
    getData(&Champions);
    
    
    Champions.print();
    
    
}
void getData(List<Hero>* list){
    
    Hero current;
    string tempString; int tempInt; double tempDouble;
    ifstream inFile;
    //Comment out my code and access this instead
    inFile.open("champions.txt");
    
    //For Dalton only, xcode requires full path without special settings changes
            //inFile.open("/Users/daltonrick/Projects/C++/League Group Project/League Group Project/champions.txt");
    
    if (inFile.fail()) {
        cout << "Error! Input file not found." << endl;
    }
    
    else{
        while (!inFile.eof()) {
            inFile >> tempString;
            current.setName(tempString);
            inFile >> tempInt;
            current.setHealth(tempInt);
            inFile >> tempInt;
            current.setMana(tempInt);
            inFile >> tempInt;
            current.setDamageRating(tempInt);
            inFile >> tempInt;
            current.setAttackDamage(tempInt);
            inFile >> tempDouble;
            current.setAttackSpeed(tempDouble);
            inFile >> tempDouble;
            current.setArmor(tempDouble);
            inFile >> tempDouble;
            current.setMagicResistance(tempDouble);
            inFile >> tempInt;
            current.setMovementSpeed(tempInt);
            
            list->push_front(current);
            inFile.ignore();
        }
    }
    
    
    
    
}