//  Dalton Rick
//
//  CIS 22C
//
//  linkList.cpp


#include "List.h"
#include "assert.h"
#include <fstream>
//================================================================= Default Constructor
template <class listitem>
List<listitem>::List(): size(0), head(NULL), tail(NULL), iterator(NULL) {}

//================================================================= Destructor()
template <class listitem>
List<listitem>::~List()
{
    iterator = head;
    NodeRef temp;
    while(iterator != NULL)
    {
        temp = iterator->next;
        
        delete iterator;
        
        iterator = temp;
        
    }// End while loop
}// End List::~List()

//================================================================= Print()
template <class listitem>
void List<listitem>::print()
{
    iterator = head;
    while (iterator != NULL) {
        
        iterator->data.print();
        iterator = iterator->next;
        
    }// End While loop
    cout << endl;
}// End List::print()

//================================================================ push_front()
template <class listitem>
void List<listitem>::push_front(listitem data){
    
    if (size==0)
    {
        head = new Node(data);
        tail = head;
        
    }
    else
    {
        NodeRef newNode = new Node(data);
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    
    size++;
    
}

//============================================================= push_back()
template <class listitem>
void List<listitem>::push_back(listitem data){
    
    if (empty()) {
        head = new Node(data);
        tail = head;
    }
    else
    {
        
        NodeRef newNode = new Node(data);
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

//============================================================ get_size()
template<class listitem>
int List<listitem>::get_size(){
    
    return size;
}

//============================================================ back()
template <class listitem>
listitem List<listitem>::back()
{
    return tail->data;
    
}

//============================================================ Off_End()
template <class listitem>
bool List<listitem>::off_end()
{
    if (iterator == NULL)
        return true;
    else
        return false;
}
//============================================================= Copy Constructor
template <class listitem>
List<listitem>::List(const List &list): size(list.size)
{
    
    NodeRef current;
    if(list.head == NULL) //If the original list is empty, make an empty list for this list
    {
        head = tail = current = NULL;
    }
    else
    {
        head = new Node;
        head->data = list.head->data;
        NodeRef temp = new Node; //Why must I create the temp Node here?
        temp = list.head;
        current = head;
        
        while(temp->next != NULL)
        {
            
            current->next = new Node;
            current = current->next;
            temp = temp->next;
            current->data = temp->data;
            
            
            
        }
        
        tail = current; //Why do I need this line of code?
        
    }
}

//=========================================================== pop_front()
template <class listitem>
void List<listitem>::pop_front(){
    
    if (empty()) //or make a call to the empty() function
    {
        cout << "Cannot call pop_front on an empty list" << endl;
    }
    else if (size==1)
    {
        delete head;
        head = tail = iterator = NULL;
        
        size = 0;
        
    }
    else
    {
        NodeRef temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;
        
        size--;
        
    }
}

//========================================================= pop_back()
template <class listitem>
void List<listitem>::pop_back(){
    
    if (empty())
    {cout << "Cannot call pop_back on an empty list" << endl;}
    else if (size==1)
    {
        delete head;
        head = tail = iterator = NULL;
        size = 0;
    }
    else
    {
        
        iterator = tail->previous;
        delete tail;
        iterator->next = NULL;
        tail = iterator;
        
        
        /* iterator=head;
         
         for(int i=1; i < size-1; i++)
         {
         iterator = iterator->next;
         }
         temp = iterator->next;
         iterator->next = NULL;
         tail = iterator;
         delete temp;
         */
        size--;
    }
}

//============================================================ Empty();
template <class listitem>
bool List<listitem>::empty(){
    
    if(size==0)
        return true;
    else
        return false;
}

//============================================================= front()
template <class listitem>
listitem List<listitem>::front(){
    if(empty())
    {
        cout << "Cannot call first node on empty list!" << endl;
        return 0;
    }
    else
        return head->data;
}

//============================================================== current() **** current does not work, xcode will not allow me to compile unless i resolve the issue of current() reaching end of non void function.
/*
 template <class listitem>
 listitem List<listitem>::current()
 {
 if (off_end())
 {
 cout << "Current: Iterator is off the end of the list!" << endl;
 assert(iterator == NULL); //xcode will not allow end of non-void function cant compile without " return returntype; "
 return -1;
 }
 else
 return iterator -> data;
 }
 */
//============================================================= begin();
template <class listitem>
void List<listitem>::begin(){
    
    iterator = head;
    
    
}
//=========================================================== insert()
template <class listitem>
void List<listitem>::insert(listitem data){
    
    if (off_end()) {
        cout << "Cannot insert, iterator Off_End" << endl;
    }
    else if(get_size() == 1){
        NodeRef newNode = new Node(data);
        iterator->next = newNode;
        newNode->previous = iterator;
        tail = newNode;
        size++;
    }
    
    else{
        NodeRef newNode = new Node(data);
        NodeRef node = iterator->next;
        newNode->next = node;
        newNode->previous = iterator;
        iterator->next = newNode;
        if(newNode->next == NULL)
            tail = newNode;
        else
        {
            NodeRef current = newNode ->next;
            current->previous = newNode;
        }
        size++;
    }
}
//========================================================== scroll();
template <class listitem>
void List<listitem>::scroll(){
    
    if(empty())
        cout << "Cannot scroll empty list!" << endl;
    
    else if (off_end())
        cout << "Cannot scroll! Iterator off_end!" << endl;
    else
        iterator = iterator->next;
    
}
//=========================================================== remove();
template <class listitem>
void List<listitem>::remove(){
    
    if (off_end()) {
        cout << endl << "Cannot delete NULL value" << endl;
    }
    else{
        delete iterator;
        size--;
    }
    
}

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
    //inFile.open("champions.txt");
    
//For Dalton only, xcode requires full path without special settings changes
    inFile.open("/Users/daltonrick/Projects/C++/League Group Project/League Group Project/champions.txt");
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