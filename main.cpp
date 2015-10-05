//  Dalton Rick, Nathan Foster, Kush Patel, Desmond Lee, Kurtis Hoang
//
//  CIS 22C
//
//  Group Project - Leaugue of Legends Character engine
//
//  main.cpp

#include "List.h"
#include "Random.h"
#include <fstream>

//======================================================= Local Function to main() Driver

// Must Run at Start
void getData(List<Hero>* list);

// Menus
char mainMenu();
char searchMenu();

//Switch case Functions
void addChampion(List<Hero>* list);
void print_to_file(List<Hero> list);
void searchFunction(List<Hero> list);
void remove(List<Hero>* list, int choice);

///////////////////////////////////////////////////////////  - Main Test Driver
int main(int argc, const char * argv[]) {
    
    //creating a new list object L
    
    List<Hero> Champions; getData(&Champions); char choice; int counter=0;

    
   
// Menu should start here:
    
    while((choice = mainMenu()) && choice != 'E'){
        
        switch (choice) {
            case 'A':
                addChampion(&Champions);
                break;
                
            case 'S':
                //searchFunction(Champions);
                break;
                
            case 'R':
                Champions.print();
                
                cout << "Please enter champion to delete: ";
                cin >> counter;
                remove(&Champions, counter);
                break;
                
            case 'P':
                Champions.print();
                break;
                
            default:
                cout << "\nNot a valid choice!\n";
                break;
        }
        
        
    }
    
    
    
    
    
/* /////////////////////////////////////// Test Case:
    Champions.print();
    
    addChampion(&Champions);
    
    Champions.print();
        
    print_to_file(Champions);
    
*/
    
//======================================================= Save any New Champions or data to file before exit
    //print_to_file(Champions);
    
    return 0;
}
//======================================================= getData()
void getData(List<Hero>* list){
    
    Hero current;
    string tempString; int tempInt; double tempDouble;
    ifstream inFile;

    inFile.open("Champions.txt");
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
        }//While Loop END
    }// Else Statement END
}// getData Function END

//======================================================= mainMenu()
char mainMenu(){
    char choice = 'E';
    cout << endl;
    cout << "\t\t\t ** Welcome to the Main Menu **\n\t\t\tPlease choose from the following:\n\n";
    
    cout << "\t A to add new champion\n"
    << "\t S to enter search menu\n"
    << "\t P to print list\n"
    << "\t R to remove a champion\n"
    << "\t E to Exit";
    
    
    cout << "\n\nChoice: "; cin >> choice;
    return toupper(choice);
}

//======================================================= addChampion()
void addChampion(List<Hero>* list){
    Hero newChampion; string tempString; //int tempInt; double tempDouble;

	//creating random generator

	Random r; // Example of how to generator a number between 1-200 -> r.DrawNumber(1, 200);
    
    cout << "\nEnter champion's Name: ";
    
    cin >> tempString;
    newChampion.setName(tempString);
    
    //cout << "\nEnter champion's Health: ";
    //cin >> tempInt;
    //newChampion.setHealth(tempInt);
	newChampion.setHealth(r.DrawNumber(450, 650));
	cout << "Health: " << newChampion.getHealth() << endl;
    
    //cout << "\nEner champion's Mana: ";
    //cin >> tempInt;
	//newChampion.setMana(tempInt);
	newChampion.setMana(r.DrawNumber(235, 365));
	cout << "Mana: " << newChampion.getMana() << endl;
    
    //cout << "\nEnter champion's Damage Range: ";
    //cin >> tempInt;
   // newChampion.setDamageRating(tempInt);
	newChampion.setDamageRating(r.DrawNumber(150, 565));
	cout << "Damage Rating: " << newChampion.getDamageRating() << endl;

    //cout << "\nEnter champion's Attack Damage: ";
    //cin >> tempInt;
    //newChampion.setAttackDamage(tempInt);
	newChampion.setAttackDamage(r.DrawNumber(38, 60));
	cout << "Attack Damage: " << newChampion.getAttackDamage() << endl;

    //cout << "\nEnter champion's Attack Speed: ";
    //cin >> tempDouble;
    //newChampion.setAttackSpeed(tempDouble); // The random number generator only works with ints
    newChampion.setAttackSpeed(r.DrawNumber(600, 800) * .001); // Convert the random generated int into a double.
    cout << "Attack Speed: " << newChampion.getAttackSpeed() << endl;

    //cout << "\nEnter champion's Armor: ";
   // cin >> tempDouble;
    //newChampion.setArmor(tempDouble);
	newChampion.setArmor(r.DrawNumber(15, 35));
	cout << "Armor: " << newChampion.getArmor() << endl;
    
    //cout << "\nEnter champion's Magic Resistance: ";
    //cin >> tempDouble;
   // newChampion.setMagicResistance(tempDouble);
	newChampion.setMagicResistance(r.DrawNumber(25, 35));
	cout << "Magic Resistance: " << newChampion.getMagicResistance() << endl;
    
   // cout << "\nEnter champion's Movement Speed: ";
    //cin >> tempInt;
   // newChampion.setMovementSpeed(tempInt);
	newChampion.setMovementSpeed(r.DrawNumber(315, 375));
	cout << "Movement Speed: " << newChampion.getMovementSpeed() << endl;
    
    list->push_back(newChampion);
    
    return;
}// addChampion Function END

void print_to_file(List<Hero> list){
   
    ofstream outFile; Hero tempChampion; int count = 0;
    
    
    outFile.open("Champions.txt");
    if (outFile.fail()) {
        cout << "Error opening file! " << endl;
    }else
    {
        list.begin();
        
        while (!list.off_end()) {
            tempChampion = list.current();
            if (count != 0)
                outFile << endl;
            
            outFile << tempChampion.getName() << " " << tempChampion.getHealth() << " " << tempChampion.getMana() << " "
            << tempChampion.getDamageRating() << " " << tempChampion.getAttackDamage() << " " << tempChampion.getAttackSpeed()
            << " " << tempChampion.getArmor() << " " << tempChampion.getMagicResistance() << " " << tempChampion.getMovementSpeed();
            
            list.scroll();
            count++;
        }//While Loop END
        
        cout << count << " Champions saved to file. " << endl;
    }// else statement END

    
}// print_to_file Function END

void remove(List<Hero>* list, int choice){
    
    list->begin(); int count=1;
    
    if(choice == 0)
        return;
    else{
        while (count < choice) {
            list->scroll();
            count++;
        }// while statement END
        
        list->remove();
 
    }// else Statement END
    
}// remove Function END



