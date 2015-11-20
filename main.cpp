//  Dalton Rick, Nathan Foster, Kush Patel, Desmond Lee, Kurtis Hoang
//
//  CIS 22C
//
//  Group Project - Leaugue of Legends Character engine
//
//  main.cpp

#include "List.h"
#include "Random.h"
#include "HashTable.h"
#include "Hero.h"
#include "BST.h"
#include <fstream>
#include <vector>

//======================================================= Local Function to main() Driver

// Must Run at Start
void getData(List<Hero>* Champions, List<Equipment>* Inventory, HashTable* Table, BST<int>* champHealth, BST<int>* equipHealth);

// Run After Sort
void reHashChampions(List<Hero> Champions, HashTable* Table);
void reHashInventory(List<Equipment> Inventory, HashTable* Table);

// Menus
char mainMenu();
char championHallMenu();
char searchMenu();
char attributeMenu();
char equipmentRoomMenu();

//Switch case Functions
void addChampion(List<Hero>* Champions, HashTable* Table, BST<int>* tree);
void print_to_file(List<Hero> Champions, List<Equipment> Inventory);
void search(List<Hero>* Champions, List<Equipment>* Inventory,HashTable* Table, BST<int>* tree, bool remove, char typeSwitch);
void equipChampion(List<Hero>* Champions, List<Equipment> Inventory);
void dequipChampion(List<Hero>* Champions);
void equipmentRoom(List<Hero>* Champions, List<Equipment>* Inventory, HashTable* Table, BST<int>* tree);
void championHall(List<Hero>* Champions, List<Equipment>* Inventory, HashTable* Table, BST<int>* tree);

//Other functions
void battle(List<Hero>* hero);

///////////////////////////////////////////////////////////  - Main Test Driver
int main(int argc, const char * argv[]) {
    
    //creating a new list object L
    
    List<Hero> Champions; List<Equipment> Inventory; HashTable Table;  char choice;
    BST<int> champHealth; BST<int> equipHealth;
    /* JUST IN CASE ANYONE DECIDES TO BST THE WHOLE DAMN ATTRIBUTE LIST
    BST<int> manaTree; BST<int> aRangeTree; BST<int> aDamageTree; BST<double> aSpeedTree; BST<double> armorTree; BST<double> magResTree; BST<int> moveSpeedTree;
    */
    getData(&Champions, &Inventory, &Table, &champHealth, &equipHealth);
    
//Main Menu
    
    while ((choice = mainMenu()) && choice != 'Q') {
        switch (choice) {
            case 'C':
                championHall(&Champions, &Inventory, &Table, &champHealth);
                break;
                
            case 'E':
                equipmentRoom(&Champions, &Inventory, &Table, &equipHealth);
                break;
                
            default:
                cout << endl << choice << " is not a valid choice!\n";
                break;
        }
    }


    
//======================================================= Save any New Champions or data to file before exit
    print_to_file(Champions, Inventory);
    
    return 0;
}
//======================================================= getData()
void getData(List<Hero>* Champions, List<Equipment>* Inventory, HashTable* Table, BST<int>* champHealth, BST<int>* equipHealth){
    
    Hero current; Weapon weapon; Armor armor; Equipment tempEquip;
    string tempString; int tempInt; double tempDouble; //char tempChar;
    ifstream inFile;

    inFile.open("Champions.txt"); // Load Chmapion data
    if (inFile.fail()) {
        cout << "Error! Champions data not found!" << endl;
        return;
    }else{
    
        while (!inFile.eof()) {
            inFile >> tempString;
            current.setName(tempString);
            Table->addItem(tempString, Champions->getIndex());
            inFile >> tempInt;
            current.setHealth(tempInt);
            champHealth->add(tempInt, Champions->getIndex());
            inFile >> tempInt;
            current.setMana(tempInt);
            inFile >> tempInt;
            current.setAttackRange(tempInt);
            inFile >> tempInt;
            current.setAttackDamage(tempInt);
            inFile >> tempDouble;
            current.setAttackSpeed(tempDouble);
            inFile >> tempDouble;
            current.setarmor(tempDouble);
            inFile >> tempDouble;
            current.setMagicResistance(tempDouble);
            inFile >> tempInt;
            current.setMovementSpeed(tempInt);
            //current.zeroEquippedCount();
            Champions->insert(current);
            inFile.ignore();
        }//While Loop END
    }
    
    inFile.close();
    
    
    inFile.open("Inventory.txt"); // Load inventory data
    if(inFile.fail()){
        cout << "Error! Inventory Data not Found!" << endl;
        return;
    }else{

        while (!inFile.eof()) {
            inFile >> tempString;
            
            if (tempString == "Armor") {
                
                inFile >> tempDouble;
                armor.setArmorBoost(tempDouble);
                inFile >> tempInt;
                armor.setHealthBoost(tempInt);
                equipHealth->add(tempInt, Inventory->getIndex());
                inFile >> tempInt;
                armor.setManaBoost(tempInt);
                inFile >> tempDouble;
                armor.setMagicResistanceBoost(tempDouble);
                inFile.ignore();
                getline(inFile, tempString);
                Table->addItem(tempString, Inventory->getIndex());
                tempEquip.setName(tempString);
                tempEquip.setArmor(armor);
                Inventory->insert(tempEquip);
            }
            else{
                
                inFile >> tempInt;
                weapon.setAttackDamageBoost(tempInt);
                inFile >> tempDouble;
                weapon.setattackSpeedBoost(tempDouble);
                inFile.ignore();
                getline(inFile, tempString);
                Table->addItem(tempString, Inventory->getIndex());
                tempEquip.setName(tempString);
                tempEquip.setWeapon(weapon);
                Inventory->insert(tempEquip);
            }
        
        }
    }
    inFile.close();
    
    inFile.open("Personal_Inventory.txt");
    if (inFile.fail()) {
        cout << "Personal_Inventory.txt failed to open\n";
    }else{
        while (!inFile.eof()) {
            
        inFile >> tempString;
        int index = Table->findName(tempString);
        Champions->scrollToIndex(index);
        inFile >> tempInt;
            Hero old = Champions->current();
            
        inFile.ignore();
            for (int i = 0; i < tempInt; i++) {
                getline(inFile, tempString);
                Inventory->scrollToIndex(Table->findName(tempString));
                tempEquip = Equipment(Inventory->current());
                Champions->equipCurrent(tempEquip);
            }
            Hero current = Champions->current();
            champHealth->containReplace(old.getHealth(), current.getHealth());
        }
    }
    inFile.close();
    
    
}// getData Function END
//======================================================= reHashChampions(Champions, Table)
void reHashChampions(List<Hero> Champions, HashTable* Table){
    
    Champions.begin(); Hero champTemp;
    
    while (!Champions.off_end()) {
        champTemp = Champions.current();
        Table->updateIndex(champTemp.getName(), Champions.getIndex());
        
        Champions.scroll();
    }
}
//======================================================= reHashInventory(Inventory, Table)
void reHashInventory(List<Equipment> Inventory, HashTable* Table){
    Inventory.begin(); Equipment tempEquip;
    
    while (!Inventory.off_end()) {
        tempEquip = Inventory.current();
        Table->updateIndex(tempEquip.getName(), Inventory.getIndex());
        Inventory.scroll();
    }
}

//======================================================= mainMenu()
char mainMenu(){
    char choice;
    
    cout << endl;
    cout << "\t\t\t\t ** Welcome to the Main Menu **\n\nPlease choose from the following:\n\n";
    
    cout << "\t C to enter the Champions Lounge\n"
    << "\t E to enter the Equipment room\n"
    << "\t Q to exit program";
    
    
    cout << "\n\nChoice: "; cin >> choice;
    return toupper(choice);
    
    return toupper(choice);
}
//======================================================= championHallMenu()
char championHallMenu(){
    char choice = 'E';
    cout << endl;
    cout << "\t\t\t\t ** Welcome to the Champions Lounge **\n\nPlease choose from the following:\n\n";
    
    cout << "\t A to add new champion\n"
	<< "\t B to go to battle\n"
    << "\t S to enter search menu\n"
    << "\t P to print champion list\n"
    << "\t R to remove a champion\n"
    << "\t E to exit the Lounge";
    
    
    cout << "\n\nChoice: "; cin >> choice;
    return toupper(choice);
}// mainMenu() function END

//======================================================= searchMenu()
char searchMenu(){

    char choice = 'E';
    cout << endl;
    cout << "\t\t\t\t\t *** Search Menu ***\n\nPlease choose from the following:\n\n";
    
        cout << "\t N to search by name\n"
        << "\t A to search by Attribute\n"
        << "\t E to exit the search menu\n";
    
    cout << "\n\nChoice: ";
    cin >> choice;
    //cout << "------------------------------------------------------\n\n";
    
    return toupper(choice);
}
//======================================================= attributeMenu()
char attributeMenu(){
    char choice = 'E';
    cout << endl;
    cout << "\t\t\t\t *** Attribute Menu ***\n\nPlease choose from the following:\n\n";
    
    cout << "\t H to search by Health\n"
    << "\t M to search by Mana\n"
    << "\t R to search by Attack Range\n"
    << "\t D to search by Attack Damage\n"
    << "\t S to search by Attack Speed\n"
    << "\t A to search by Armor \n"
    << "\t G to search by Magic Resistance\n"
    << "\t Q to search by Movement Speed\n"
    << "\t E to exit the attribute menu";
    
    cout << "\n\nChoice: ";
    cin >> choice;
    
    return toupper(choice);
    
}
//======================================================= equipmentRoom()
char equipmentRoomMenu(){
    char choice = 'E';
    cout << endl;
    cout << "\t\t\t\t *** Equipment Room ***\n\nPlease choose from the following:\n\n";
    
    cout << "\t Q to equip a champion\n"
    << "\t D to remove champion equipment\n"
    << "\t A to add new item\n"
    << "\t S to search for equipment\n"
    << "\t R to destroy an item\n"
    << "\t P to print inventory List\n"
    << "\t E to exit the Equipment Room\n";
    
    cout << "\n\nChoice: ";
    cin >> choice;
    
    
    return toupper(choice);
}

//======================================================= addChampion()
void addChampion(List<Hero>* Champions, HashTable* Table, BST<int>* tree){
    Hero newChampion; string tempString;int tempInt; double tempDouble; int count; char choice;

	//creating random generator

    Random r;  // Example of how to generator a number between 1-200 -> r.DrawNumber(1, 200);
    
    cout << "Would you like to use the Random Stat Generator? (Y/N): ";
    cin >> choice;
    
    if (toupper(choice) == 'Y') {
        
        cout << "How many champions would you like to add?: ";
        cin >> count;
        
        for (int i=0; i < count; i++) {
            
            cout << "\nEnter champion's Name: ";
            cin >> tempString;
            newChampion.setName(tempString);
            
            newChampion.setHealth(r.DrawNumber(450, 650));
            cout << "Health: " << newChampion.getHealth() << endl;
            tree->add(newChampion.getHealth(), Champions->getIndex()+1);
            
            newChampion.setMana(r.DrawNumber(235, 365));
            cout << "Mana: " << newChampion.getMana() << endl;
            
            newChampion.setAttackRange(r.DrawNumber(150, 565));
            cout << "Attack Range: " << newChampion.getAttackRange() << endl;
            
            newChampion.setAttackDamage(r.DrawNumber(38, 60));
            cout << "Attack Damage: " << newChampion.getAttackDamage() << endl;
            
            newChampion.setAttackSpeed(r.DrawNumber(600, 800) * .001); // Convert the random generated int into a double.
            cout << "Attack Speed: " << newChampion.getAttackSpeed() << endl;
            
            newChampion.setarmor(r.DrawNumber(15, 35));
            cout << "Armor: " << newChampion.getarmor() << endl;
            
            newChampion.setMagicResistance(r.DrawNumber(25, 35));
            cout << "Magic Resistance: " << newChampion.getMagicResistance() << endl;
            
            newChampion.setMovementSpeed(r.DrawNumber(315, 375));
            cout << "Movement Speed: " << newChampion.getMovementSpeed() << endl;
            
            Champions->push_back(newChampion);
            Table->addItem(tempString, Champions->getIndex());
            cout << i+1 << " of " << count << " added." << endl;
            
        }// for loop END
    }// if statement END
    
    else{
        
        cout << "How many champions would you like to add?: ";
        cin >> count;
        
        for (int i=0; i < count; i++) {
            cout << "\nEnter champion's Name: ";
            
            cin >> tempString;
            newChampion.setName(tempString);
            
            cout << "\nEnter champion's Health: ";
            cin >> tempInt;
            newChampion.setHealth(tempInt);
    
            
            cout << "\nEner champion's Mana: ";
            cin >> tempInt;
            newChampion.setMana(tempInt);
            
            cout << "\nEnter champion's Damage Range: ";
            cin >> tempInt;
            newChampion.setAttackRange(tempInt);
            
            cout << "\nEnter champion's Attack Damage: ";
            cin >> tempInt;
            newChampion.setAttackDamage(tempInt);
            
            
            cout << "\nEnter champion's Attack Speed: ";
            cin >> tempDouble;
            newChampion.setAttackSpeed(tempDouble); // The random number generator only works with ints
           
            
            cout << "\nEnter champion's Armor: ";
            cin >> tempDouble;
            newChampion.setarmor(tempDouble);
            
            cout << "\nEnter champion's Magic Resistance: ";
            cin >> tempDouble;
            newChampion.setMagicResistance(tempDouble);
            
            cout << "\nEnter champion's Movement Speed: ";
            cin >> tempInt;
            newChampion.setMovementSpeed(tempInt);
            
            Champions->push_back(newChampion);
            
            cout << i+1 << " of " << count << " added." << endl;
        }// for Loop END

    }// else statement END
    return;
}// addChampion Function END

//======================================================= print_to_file()
void print_to_file(List<Hero> Champions, List<Equipment> Inventory){
   
    ofstream outFile; Hero tempChampion; int count = 0;
    Equipment tempEquip; Weapon tempWeapon; Armor tempArmor;
    

    outFile.open("Personal_Inventory.txt");
    if (outFile.fail()) {
        cout << "Error opening Personal_Inventory.txt\n";
    }else{
        Champions.begin();
        
        while (!Champions.off_end()) {
            tempChampion = Champions.current();
            
            if (tempChampion.getEquippedCount() != 0) {
            
                if (count != 0) {// newline if not first input
                    outFile << endl;
                }
                
                outFile << tempChampion.getName() << " ";
                outFile << tempChampion.getEquippedCount();
                
                for (int i=0; i < tempChampion.getEquippedCount(); i++) {
                    tempEquip = Equipment(Champions.sendCurrentEquip(i));
                    outFile << endl << tempEquip.getName();
                }
                
                count++;
                
            }
            Champions.scroll();

        }
        cout << count << " Champion Inventory Saved.\n";
    }
    outFile.close();
    
    Champions.dequipAll();
    
    outFile.open("Champions.txt");
    if (outFile.fail()) {
        cout << "Error opening file! " << endl;
    }else
    {
        Champions.begin(); count = 0;
        
        while (!Champions.off_end()) {
            
            tempChampion = Champions.current(); // Make champion data accessible
            if (count != 0) // Newline if not first input
                outFile << endl;
            
            outFile << tempChampion.getName() << " " << tempChampion.getHealth() << " " << tempChampion.getMana() << " "
            << tempChampion.getAttackRange() << " " << tempChampion.getAttackDamage() << " " << tempChampion.getAttackSpeed()
            << " " << tempChampion.getarmor() << " " << tempChampion.getMagicResistance() << " " << tempChampion.getMovementSpeed();
            
            Champions.scroll();
            count++;
        }//While Loop END
        
        cout << count << " Champions saved. \n";
    }// else statement END
    outFile.close();
    
    outFile.open("Inventory.txt");
    if (outFile.fail()) {
        cout << "Inventory.txt unable to open.\n";
    }else{
        count = 0;
        Inventory.begin();
        
        while (!Inventory.off_end()) {
            tempEquip = Inventory.current();
            
            if (count != 0) {
                outFile << endl;
            }
            outFile << tempEquip.getType() << " ";
            if (tempEquip.getType() == "Weapon") {
                tempWeapon = tempEquip.getWeapon();
                outFile << tempWeapon.getAttackDamage() << " "
                << tempWeapon.getAttackSpeed() << " ";
                
                
                
            }else{
                tempArmor = tempEquip.getArmor();
                outFile << tempArmor.getArmorBoost() << " "
                << tempArmor.getHealthBoost() << " "
                << tempArmor.getManaBoost() << " "
                << tempArmor.getMagicResistanceBoost() << " ";
                
            }
            outFile << tempEquip.getName();
            Inventory.scroll(); count++;
        }
        cout << count << " Inventory items saved.\n";
    }
    outFile.close();
    
    
}// print_to_file Function END
//======================================================= search()
void search(List<Hero>* Champions, List<Equipment>* Inventory, HashTable* Table, BST<int>* tree, bool remove, char typeSwitch){
    char choice; string query; Hero temp; Equipment eTemp; int selected =0; char response = 'N'; bool found = false; char attribute;
    int intMin, intMax; double doubleMin, doubleMax; int counted=0; int convert=0; vector<int> indexRange;
    
    while((choice = searchMenu()) && choice != 'E'){
        found = false;
        
        
        switch (choice) {
            case 'N':// Name
                
                if (typeSwitch == 'C') {
                    cout << "\nEnter champion name: ";
                    cin >> query; cout << endl;
                    
                    Champions->scrollToIndex(Table->findName(query));
                    selected = 0;
                    
                    if (Champions->off_end() == false) {
                        
                        temp = Champions->current();
                        selected = Table->findName(query);// this keeps track of where in the list we are. If query is found, selected is the spot in the list that remove function must delete;
                        temp.print(); found = true;
                        
                            //====================================== Remove option enabled
                            if (remove == true) {
                                cout << "\nWould you like to delete? (Y/N): ";
                                cin >> response;
                                if (toupper(response) == 'N') {
                                    selected=0;
                                }// if response == 'N' statement END
                                Table->removeItem(query);
                            }// if (remove==true) statement END
                            break;
                            
                       
                        
                    }// if statement END
                    if (found == false)
                        cout << "\nNo match found!" << endl;
                    
                    
                }else if(typeSwitch == 'I'){
                    cin.ignore();
                    cout << "\nEnter Item name: ";
                    
                    getline(cin, query); cout << endl;
                    
                    Inventory->scrollToIndex(Table->findName(query)); selected = 0;
                    
                    
                    if (Inventory->off_end() == false) {
                        
                        eTemp = Inventory->current();
                        selected = Table->findName(query);// this keeps track of where in the list we are. If query is found, selected is the spot in the list that remove function must delete;
                        eTemp.print(); found = true;
                        
                            //====================================== Remove option enabled
                            if (remove == true) {
                                cout << "\nWould you like to delete? (Y/N): ";
                                cin >> response;
                                if (toupper(response) == 'N') {
                                    selected=0;
                                }// if response == 'N' statement END
                                Table->removeItem(query);
                            }// if (remove==true) statement END
                            break;
                        
                        
                    }// if Statement END
                    if (found == false)
                        cout << "\nNo match found!" << endl;
                }
                
                break;// End Name
                
            case 'A':// Attribute
                Champions->begin(); selected = 0; counted =0;
                cout << "Select an attribute:\n";
//---------------------------------------------------------- Search Attribute begin ---------------------------------------------------------
                if (typeSwitch == 'C') {
                    
                    switch ((attribute = attributeMenu())) {
                            
                        case 'H':// Health
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            
                            indexRange = tree->search(intMin, intMax);
                
                            
                            for (int i=0; i < indexRange.size(); i++) {
                                found = true;
                                Champions->scrollToIndex(indexRange.at(i));
                                temp = Champions->current();
                                cout << endl << i + 1 << endl;
                                temp.print();
                                
                            }
                            
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->scrollToIndex(indexRange.at(convert));
                                    selected = Champions->getIndex();
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;// END Health
                            
                        case 'M':// Mana
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Champions->off_end() == false) {
                                temp = Champions->current();
                                if (temp.getMana() >= intMin && temp.getMana() <= intMax) {counted++;
                                    cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                }//if Statement END
                                
                                Champions->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->begin(); counted =0; selected =0;
                                    while (Champions->off_end() == false && counted < convert) {
                                        temp = Champions->current();
                                        selected++;
                                        if (temp.getMana() >= intMin && temp.getMana() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        
                                        Champions->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            
                            break;
                            
                        case 'R':// Attack Range
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Champions->off_end() == false) {
                                temp = Champions->current();
                                
                                if (temp.getAttackRange() >= intMin && temp.getAttackRange() <= intMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                
                                Champions->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->begin(); counted =0; selected =0;
                                    while (Champions->off_end() == false && counted < convert) {
                                        temp = Champions->current();
                                        selected++;
                                        if (temp.getAttackRange() >= intMin && temp.getAttackRange() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        
                                        Champions->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'D':// Attack Damage
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Champions->off_end() == false) {
                                temp = Champions->current();
                                
                                if (temp.getAttackDamage() >= intMin && temp.getAttackDamage() <= intMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                
                                Champions->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->begin(); counted =0; selected =0;
                                    while (Champions->off_end() == false && counted < convert) {
                                        temp = Champions->current();
                                        selected++;
                                        if (temp.getHealth() >= intMin && temp.getHealth() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        
                                        Champions->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'S':// Attack Speed
                            cout << "Enter Min Range: "; cin >> doubleMin;
                            cout << "\nEnter Max Range: "; cin >> doubleMax;
                            
                            while (Champions->off_end() == false) {
                                temp = Champions->current();
                                
                                if (temp.getAttackSpeed() >= doubleMin && temp.getAttackSpeed() <= doubleMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                
                                Champions->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->begin(); counted =0; selected =0;
                                    while (Champions->off_end() == false && counted < convert) {
                                        temp = Champions->current();
                                        selected++;
                                        if (temp.getAttackSpeed() >= doubleMin && temp.getAttackSpeed() <= doubleMax) {
                                            counted++;
                                        }//if Statement END
                                        
                                        Champions->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'A':// armor
                            cout << "Enter Min Range: "; cin >> doubleMin;
                            cout << "\nEnter Max Range: "; cin >> doubleMax;
                            
                            while (Champions->off_end() == false) {
                                temp = Champions->current();
                                
                                if (temp.getarmor() >= doubleMin && temp.getarmor() <= doubleMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                
                                Champions->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->begin(); counted =0; selected =0;
                                    while (Champions->off_end() == false && counted < convert) {
                                        temp = Champions->current();
                                        selected++;
                                        if (temp.getarmor() >= doubleMin && temp.getarmor() <= doubleMax) {
                                            counted++;
                                        }//if Statement END
                                        
                                        Champions->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'G':// Magic Resistance
                            cout << "Enter Min Range: "; cin >> doubleMin;
                            cout << "\nEnter Max Range: "; cin >> doubleMax;
                            
                            while (Champions->off_end() == false) {
                                temp = Champions->current();
                                
                                if (temp.getMagicResistance() >= doubleMin && temp.getMagicResistance() <= doubleMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                }//if Statement END
                                
                                Champions->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->begin(); counted =0; selected =0;
                                    while (Champions->off_end() == false && counted < convert) {
                                        temp = Champions->current();
                                        selected++;
                                        if (temp.getMagicResistance() >= doubleMin && temp.getMagicResistance() <= doubleMax) {
                                            counted++;
                                        }//if Statement END
                                        
                                        Champions->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'Q':// Movement Speed
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Champions->off_end() == false) {
                                temp = Champions->current();
                                
                                if (temp.getMovementSpeed() >= intMin && temp.getMovementSpeed() <= intMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                
                                Champions->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Champions->begin(); counted =0; selected =0;
                                    while (Champions->off_end() == false && counted < convert) {
                                        temp = Champions->current();
                                        selected++;
                                        if (temp.getMovementSpeed() >= intMin && temp.getMovementSpeed() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        
                                        Champions->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        default:
                            cout << endl << choice << " is not a valid choice!\n";
                            break;
                    }// End Attribute switch
                    
//---------------------------------------------------------- Search Attribute Else ---------------------------------------------------------
                }else if (typeSwitch == 'I'){
                    Inventory->begin();
                    
                    switch ((attribute = attributeMenu())) {
                            
                        case 'D'://attack damage Boost
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Inventory->off_end() == false) {
                            
                                eTemp = Inventory->current();
                                
                                if (eTemp.getType() == "Weapon") {
                                    Weapon wpn2compare(eTemp.getWeapon());
                                    
                                    
                                    if (wpn2compare.getAttackDamage() >= intMin && wpn2compare.getAttackDamage() <= intMax) {
                                        counted++;
                                        cout << endl << endl << counted << endl; eTemp.print(); found = true;
                                        
                                        
                                    }//if Statement END
                                }
                                
                                
                                Inventory->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Inventory->begin(); counted =0; selected =0;
                                    
                                    
                                    while (Inventory->off_end() == false && counted < convert) {
                                        eTemp = Inventory->current();
                                        if (eTemp.getType() == "Weapon") {
                                         Weapon wpn2compare = eTemp.getWeapon();
                                        selected++;
                                        if (wpn2compare.getAttackDamage() >= intMin && wpn2compare.getAttackDamage() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        }
                                        Inventory->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            
                            break;
                            
                        case 'S':// Attack Speed
                            cout << "Enter Min Range: "; cin >> doubleMin;
                            cout << "\nEnter Max Range: "; cin >> doubleMax;
                            
                            while (Inventory->off_end() == false) {
                                eTemp = Inventory->current();
                                
                                if (eTemp.getType() == "Weapon") {
                                Weapon wpn2compare(eTemp.getWeapon());
                                
                                if (wpn2compare.getAttackSpeed() >= doubleMin && wpn2compare.getAttackSpeed() <= doubleMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; eTemp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                }
                                Inventory->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Inventory->begin(); counted =0; selected =0;
                                    while (Inventory->off_end() == false && counted < convert) {
                                        eTemp = Inventory->current();
                                        if (eTemp.getType() == "Weapon") {
                                        Weapon wpn2compare = eTemp.getWeapon();
                                        selected++;
                                        if (wpn2compare.getAttackDamage() >= doubleMin && wpn2compare.getAttackDamage() <= doubleMax) {
                                            counted++;
                                        }//if Statement END
                                        }
                                        Inventory->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'H':// Health Boost
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Inventory->off_end() == false) {
                                eTemp = Inventory->current();
                                
                                if (eTemp.getType() == "Armor") {
                                Armor arm2compare(eTemp.getArmor());
                                
                                if (arm2compare.getHealthBoost() >= intMin && arm2compare.getHealthBoost() <= intMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; eTemp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                }
                                Inventory->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Inventory->begin(); counted =0; selected =0;
                                    while (Inventory->off_end() == false && counted < convert) {
                                        eTemp = Inventory->current();
                                        if (eTemp.getType() == "Armor") {
                                        Armor arm2compare = eTemp.getArmor();
                                        selected++;
                                        if (arm2compare.getHealthBoost() >= intMin && arm2compare.getHealthBoost() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        }
                                        Inventory->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'A':// Armor Boost
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Inventory->off_end() == false) {
                                eTemp = Inventory->current();
                                if (eTemp.getType() == "Armor") {
                                Armor arm2compare(eTemp.getArmor());
                                
                                if (arm2compare.getArmorBoost() >= intMin && arm2compare.getArmorBoost() <= intMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; eTemp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                }
                                Inventory->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Inventory->begin(); counted =0; selected =0;
                                    while (Inventory->off_end() == false && counted < convert) {
                                        eTemp = Inventory->current();
                                        if (eTemp.getType() == "Armor") {
                                        Armor arm2compare = eTemp.getArmor();
                                        selected++;
                                        if (arm2compare.getArmorBoost() >= intMin && arm2compare.getArmorBoost() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        }
                                        Inventory->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'M': // Mana Boost
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Inventory->off_end() == false) {
                                eTemp = Inventory->current();
                                if (eTemp.getType() == "Armor") {
                                Armor arm2compare(eTemp.getArmor());
                                
                                if (arm2compare.getManaBoost() >= intMin && arm2compare.getManaBoost() <= intMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; eTemp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                }
                                Inventory->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Inventory->begin(); counted =0; selected =0;
                                    while (Inventory->off_end() == false && counted < convert) {
                                        eTemp = Inventory->current();
                                        if (eTemp.getType() == "Armor") {
                                        Armor arm2compare = eTemp.getArmor();
                                        selected++;
                                        if (arm2compare.getManaBoost() >= intMin && arm2compare.getManaBoost() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        }
                                        Inventory->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        case 'G': // Magic Resistance Boost
                            cout << "Enter Min Range: "; cin >> intMin;
                            cout << "\nEnter Max Range: "; cin >> intMax;
                            
                            while (Inventory->off_end() == false) {
                                eTemp = Inventory->current();
                                if (eTemp.getType() == "Armor") {
                                Armor arm2compare(eTemp.getArmor());
                                
                                if (arm2compare.getMagicResistanceBoost() >= intMin && arm2compare.getMagicResistanceBoost() <= intMax) {
                                    counted++;
                                    cout << endl << endl << counted << endl; eTemp.print(); found = true;
                                    
                                    
                                }//if Statement END
                                }
                                
                                Inventory->scroll();
                                
                            }// while loop END
                            
                            //====================================== Remove option enabled
                            if (remove == true && found == true) {
                                cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                cin >> convert;
                                if (convert == 0) {
                                    selected=0;
                                }else
                                {
                                    Inventory->begin(); counted =0; selected =0;
                                    while (Inventory->off_end() == false && counted < convert) {
                                        eTemp = Inventory->current();
                                        if (eTemp.getType() == "Armor") {
                                        Armor arm2compare = eTemp.getArmor();
                                        selected++;
                                        if (arm2compare.getMagicResistanceBoost() >= intMin && arm2compare.getMagicResistanceBoost() <= intMax) {
                                            counted++;
                                        }//if Statement END
                                        }
                                        Inventory->scroll();
                                        
                                    }// while loop END
                                    
                                }
                            }// if (remove==true) statement END
                            
                            
                            if (found == false)
                                cout << "\nNo match found!" << endl;
                            break;
                            
                        default:
                            cout << endl << attribute << " is not a valid choice!\n";;
                            break;
                            
                            
                    }// switch inventory attribute
                    
                    
                }else
                    cout << "Invalid Seach choice\n";
                
                
                
        
                break;// End Attribute
                
            case 'E'://Exit
                return;
                
                break;
                
            default:
                cout << "\nNot a valid choice!\n";
                break;
        }
        
        
        //======================================================================== Remove option enabled
        if (remove == true && selected > 0 && typeSwitch == 'C') {
            
            Champions->scrollToIndex(selected);
            Champions->remove();
            
            
        }else if(remove == true && selected > 0 && typeSwitch == 'I'){
            Inventory->scrollToIndex(selected);
            Inventory->remove();
        }
        
            }// while statement END
}
//======================================================= battle()
void battle(List<Hero>* Champions) {
	string selectedChampion; int selected; Hero temp; bool found = false;
	cout << "Enter the name of the champion you want to fight with: " << endl;
	cin >> selectedChampion;

	Champions->begin(); selected = 0;

	while (Champions->off_end() == false) {

		temp = Champions->current();
		selected++;// this keeps track of where in the list we are. If query is found, selected is the spot in the list that remove function must delete;
		if (temp.getName() == selectedChampion) {
			//temp.print();
			found = true;
		}
	}//end while
	if (found == true)
	{
		cout << "true" << endl;
	}
	else { cout << "false" << endl; }

}
//======================================================= EquipmentRoom()
void equipmentRoom(List<Hero>* Champions, List<Equipment>* Inventory, HashTable* Table, BST<int>* tree){
    
    char choice; bool remove; char typeSwitch = 'I';
    
    while((choice = equipmentRoomMenu()) && choice != 'E'){
        
        switch (choice) {
                
            case 'Q':
                
                equipChampion(Champions, *Inventory);
                
                break;
                
            case 'D':
                
                dequipChampion(Champions);
                
                break;
                
            case 'R':
                remove = true;
                search(Champions, Inventory, Table, tree, remove, typeSwitch);
                
                break;
                
            case 'S'://Search equipment
                remove = false;
                search(Champions, Inventory, Table, tree, remove, typeSwitch);
                
                break;
                
            case 'P':
                
                Inventory->print();
                
                break;
                
            case 'A':// add item
                
                
                break;
                
                
            default:
                cout << endl << choice << " is not a valid choice!\n";
            
                break;
                
        }// End Switch
        
    }// End While
    
    
}
//======================================================= Champion Hall
void championHall(List<Hero>* Champions, List<Equipment>* Inventory, HashTable* Table, BST<int>* tree){
    char typeSwitch = 'C'; bool remove; char choice;
    
    while((choice = championHallMenu()) && choice != 'E'){
        
        switch (choice) {
            case 'A':
                addChampion(Champions, Table, tree);
                break;
            case 'B':
                battle(Champions);
                break;
            case 'R':
                remove = true; typeSwitch = 'C';
                search(Champions, Inventory, Table, tree, remove, typeSwitch);
                break;
                
            case 'S':
                remove = false; typeSwitch = 'C';
                search(Champions, Inventory, Table, tree, remove, typeSwitch);
                break;
                
            case 'P':
                Champions->print();
                break;
                
            
            default:
                cout << endl << choice << "is not a valid choice!\n";
                break;
        }
        
        
    }
}

//======================================================= equipChampion()
void equipChampion(List<Hero>* Champions, List<Equipment> Inventory){
    
    Equipment tempEquipment; int choice; Hero tempHero;
    
    Champions->print();
    
    cout << "\nEnter Champion to equip: ";
    cin >> choice;
    cout << endl << endl;
    Champions->begin();
    for (int i=0; i < choice-1; i++) {
        Champions->scroll();
    }

    
    Inventory.print();
    
    cout << "\nEnter item to equip: ";
    cin >> choice;
    cout << endl << endl;
    
    Inventory.begin();
    
    for(int i=0; i < choice-1; i++){
        Inventory.scroll();
    }
    
    tempEquipment = Equipment(Inventory.current());
    
   Champions->equipCurrent(tempEquipment);    
    
    
    
    
}
//======================================================= dequipChampion()
void dequipChampion(List<Hero>* Champions){
    
    Champions->print(); int choice=0; int count=0;
    
    cout << "\nEnter Champion Number: ";
    cin >> choice;
    cout << endl << endl;
    
    Champions->begin();
    for (int i=0; i < choice-1; i++) {
        Champions->scroll();
    }
    
    Champions->print1();
    
    cout << "\nEnter item to remove: ";
    cin >> count;
    cout << endl;
    
     Champions->dequipCurrent(count);
    
    
}
