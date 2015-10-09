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
char attributeMenu();

//Switch case Functions
void addChampion(List<Hero>* list);
void print_to_file(List<Hero> list);
void search(List<Hero>* list, bool remove);

//Other functions
void battle(List<Hero>* hero);

///////////////////////////////////////////////////////////  - Main Test Driver
int main(int argc, const char * argv[]) {
    
    //creating a new list object L
    
    List<Hero> Champions; getData(&Champions); char choice; bool remove = false;

    
   
// Menu should start here:
    
    while((choice = mainMenu()) && choice != 'E'){
        
        switch (choice) {
            case 'A':
                addChampion(&Champions);
				break;
			case 'B':
				battle(&Champions);
				break;
            case 'R':
                remove = true;
                search(&Champions, remove);
                break;

			case 'S':
				remove = false;
				search(&Champions, remove);
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
    print_to_file(Champions);
    
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
            
            list->push_back(current);
            inFile.ignore();
        }//While Loop END
    }// Else Statement END
    
    inFile.close();
}// getData Function END

//======================================================= mainMenu()
char mainMenu(){
    char choice = 'E';
    cout << endl;
    cout << "\t\t\t\t ** Welcome to the Main Menu **\n\nPlease choose from the following:\n\n";
    
    cout << "\t A to add new champion\n"
	<< "\t B to go to battle\n"
    << "\t S to enter search menu\n"
    << "\t P to print list\n"
    << "\t R to remove a champion\n"
    << "\t E to Exit";
    
    
    cout << "\n\nChoice: "; cin >> choice;
    return toupper(choice);
}// mainMenu() function END

//======================================================= searchMenu()
char searchMenu(){
    char choice = 'E';
    cout << endl;
    cout << "\t\t\t\t\t *** Search Menu ***\n\nPlease choose from the following:\n\n";
    
    cout << "\t N to search by name\n"
    << "\t H to search by hash number\n"
    << "\t A to search by Attribute\n"
    << "\t E to exit to main menu\n";
    
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
    << "\t Q to search by Movement Speed\n";
    
    cout << "\n\nChoice: ";
    cin >> choice;
    
    return toupper(choice);
    
}

//======================================================= addChampion()
void addChampion(List<Hero>* list){
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
            
            list->push_back(newChampion);
            
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
            
            list->push_back(newChampion);
            
            cout << i+1 << " of " << count << " added." << endl;
        }// for Loop END

    }// else statement END
    return;
}// addChampion Function END

//======================================================= print_to_file()
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
            << tempChampion.getAttackRange() << " " << tempChampion.getAttackDamage() << " " << tempChampion.getAttackSpeed()
            << " " << tempChampion.getarmor() << " " << tempChampion.getMagicResistance() << " " << tempChampion.getMovementSpeed();
            
            list.scroll();
            count++;
        }//While Loop END
        
        cout << count << " Champions saved to file. " << endl;
    }// else statement END

    
}// print_to_file Function END
//======================================================= search()
void search(List<Hero>* list, bool remove){
    char choice; string query; Hero temp; int selected =0; int count =0; char response = 'N'; bool found = false; char attribute;
    int intMin, intMax; double doubleMin, doubleMax; int counted=0; int convert=0;
    
    while((choice = searchMenu()) && choice != 'E'){
        found = false;
        switch (choice) {
            case 'N':// Name
                cout << "\nEnter champion name: ";
                cin >> query; cout << endl;
                
                list->begin(); selected = 0;
                
                while (list->off_end() == false) {
                    
                    temp = list->current();
                    selected++;// this keeps track of where in the list we are. If query is found, selected is the spot in the list that remove function must delete;
                    if (temp.getName() == query) {
                        temp.print(); found = true;
                                        //====================================== Remove option enabled
                                            if (remove == true) {
                                                cout << "\nWould you like to delete? (Y/N): ";
                                                cin >> response;
                                                if (toupper(response) == 'N') {
                                                    selected=0;
                                                }// if response == 'N' statement END
                                            }// if (remove==true) statement END
                        break;
                        
                    }//if Statement END
                    
                    list->scroll();
                    
                }// while loop END
                if (found == false)
                    cout << "\nNo match found!" << endl;
            
                break;// End Name
                
            case 'H':// Hash
                
                break;// END Hash
                
            case 'A':// Attribute
                list->begin(); selected = 0; counted =0;
                cout << "Select an attribute:\n";

                            switch ((attribute = attributeMenu())) {
                        
                                    case 'H':// Health
                                        cout << "Enter Min Range: "; cin >> intMin;
                                        cout << "\nEnter Max Range: "; cin >> intMax;
                        
                                        while (list->off_end() == false) {
                                                temp = list->current();
                                            
                                            if (temp.getHealth() >= intMin && temp.getHealth() <= intMax) { counted++;
                                                cout << endl << endl << counted << endl; temp.print(); found = true;
                                                
                                            }//if Statement END
                            
                                                list->scroll();
                            
                                        }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getHealth() >= intMin && temp.getHealth() <= intMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END

                                        }
                                    }// if (remove==true) statement END
                                    
                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                                    break;// END Health
                
                                case 'M':// Mana
                                    cout << "Enter Min Range: "; cin >> intMin;
                                    cout << "\nEnter Max Range: "; cin >> intMax;
                        
                                    while (list->off_end() == false) {
                                        temp = list->current();
                                        if (temp.getMana() >= intMin && temp.getMana() <= intMax) {counted++;
                                            cout << endl << endl << counted << endl; temp.print(); found = true;
                                            
                                        }//if Statement END
                            
                                        list->scroll();
                            
                                    }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getMana() >= intMin && temp.getMana() <= intMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END
                                            
                                        }
                                    }// if (remove==true) statement END

                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                        
                                    break;
                        
                                case 'R':// Attack Range
                                    cout << "Enter Min Range: "; cin >> intMin;
                                    cout << "\nEnter Max Range: "; cin >> intMax;
                                    
                                    while (list->off_end() == false) {
                                        temp = list->current();
                                       
                                        if (temp.getAttackRange() >= intMin && temp.getAttackRange() <= intMax) {
                                            counted++;
                                            cout << endl << endl << counted << endl; temp.print(); found = true;
                                            
                                            
                                        }//if Statement END
                                        
                                        list->scroll();
                                        
                                    }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getAttackRange() >= intMin && temp.getAttackRange() <= intMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END
                                            
                                        }
                                    }// if (remove==true) statement END

                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                                    break;
                        
                                case 'D':// Attack Damage
                                    cout << "Enter Min Range: "; cin >> intMin;
                                    cout << "\nEnter Max Range: "; cin >> intMax;
                                    
                                    while (list->off_end() == false) {
                                        temp = list->current();
                                        
                                        if (temp.getAttackDamage() >= intMin && temp.getAttackDamage() <= intMax) {
                                            counted++;
                                            cout << endl << endl << counted << endl; temp.print(); found = true;
                                            
                                            
                                        }//if Statement END
                                        
                                        list->scroll();
                                        
                                    }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getHealth() >= intMin && temp.getHealth() <= intMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END
                                            
                                        }
                                    }// if (remove==true) statement END

                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                                    break;
                        
                                case 'S':// Attack Speed
                                    cout << "Enter Min Range: "; cin >> doubleMin;
                                    cout << "\nEnter Max Range: "; cin >> doubleMax;
                                    
                                    while (list->off_end() == false) {
                                        temp = list->current();
                                        
                                        if (temp.getAttackSpeed() >= doubleMin && temp.getAttackSpeed() <= doubleMax) {
                                            counted++;
                                            cout << endl << endl << counted << endl; temp.print(); found = true;
                                            
                                            
                                        }//if Statement END
                                        
                                        list->scroll();
                                        
                                    }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getAttackSpeed() >= doubleMin && temp.getAttackSpeed() <= doubleMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END
                                            
                                        }
                                    }// if (remove==true) statement END

                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                                    break;
                        
                                case 'A':// armor
                                    cout << "Enter Min Range: "; cin >> doubleMin;
                                    cout << "\nEnter Max Range: "; cin >> doubleMax;
                                    
                                    while (list->off_end() == false) {
                                        temp = list->current();
                                        
                                        if (temp.getarmor() >= doubleMin && temp.getarmor() <= doubleMax) {
                                            counted++;
                                            cout << endl << endl << counted << endl; temp.print(); found = true;
                                    
                                            
                                        }//if Statement END
                                        
                                        list->scroll();
                                        
                                    }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getarmor() >= doubleMin && temp.getarmor() <= doubleMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END
                                            
                                        }
                                    }// if (remove==true) statement END

                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                                    break;
                        
                                case 'G':// Magic Resistance
                                    cout << "Enter Min Range: "; cin >> doubleMin;
                                    cout << "\nEnter Max Range: "; cin >> doubleMax;
                                    
                                    while (list->off_end() == false) {
                                        temp = list->current();
                                        
                                        if (temp.getMagicResistance() >= doubleMin && temp.getMagicResistance() <= doubleMax) {
                                            counted++;
                                            cout << endl << endl << counted << endl; temp.print(); found = true;
                                            
                                        }//if Statement END
                                        
                                        list->scroll();
                                        
                                    }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getMagicResistance() >= doubleMin && temp.getMagicResistance() <= doubleMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END
                                            
                                        }
                                    }// if (remove==true) statement END

                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                                    break;
                        
                                case 'Q':// Movement Speed
                                    cout << "Enter Min Range: "; cin >> intMin;
                                    cout << "\nEnter Max Range: "; cin >> intMax;
                                    
                                    while (list->off_end() == false) {
                                        temp = list->current();
                                    
                                        if (temp.getMovementSpeed() >= intMin && temp.getMovementSpeed() <= intMax) {
                                            counted++;
                                            cout << endl << endl << counted << endl; temp.print(); found = true;
                                            
                                            
                                        }//if Statement END
                                        
                                        list->scroll();
                                        
                                    }// while loop END
                                    
                                    //====================================== Remove option enabled
                                    if (remove == true && found == true) {
                                        cout << "\nWhich you like to delete? (Enter 0 to cancel): ";
                                        cin >> convert;
                                        if (convert == 0) {
                                            selected=0;
                                        }else
                                        {
                                            list->begin(); counted =0; selected =0;
                                            while (list->off_end() == false && counted < convert) {
                                                temp = list->current();
                                                selected++;
                                                if (temp.getMovementSpeed() >= intMin && temp.getMovementSpeed() <= intMax) {
                                                    counted++;
                                                }//if Statement END
                                                
                                                list->scroll();
                                                
                                            }// while loop END
                                            
                                        }
                                    }// if (remove==true) statement END

                                    
                                    if (found == false)
                                        cout << "\nNo match found!" << endl;
                                    break;
                
                                default:
                                    cout << "\nNot a valid choice!\n";
                                    break;
                            }// End Attribute switch
                
        
                break;// End Attribute
                
            case 'E'://Exit
                return;
                
                break;
                
            default:
                cout << "\nNot a valid choice!\n";
                break;
        }
        //=========================================== Remove option enabled
        if (remove == true && selected != 0){
            list->begin();
            for (count = 0; count < selected-1; count++){
                list->scroll();
            }// for statement END
            list->remove();
        }// if Statement END
        
            }// while statement END
}
//======================================================= battle()
void battle(List<Hero>* hero) {
	string selectedChampion; int selected; Hero temp; bool found = false;
	cout << "Enter the name of the champion you want to fight with: " << endl;
	cin >> selectedChampion;

	hero->begin(); selected = 0;

	while (hero->off_end() == false) {

		temp = hero->current();
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
