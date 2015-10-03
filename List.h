//  Dalton Rick
//
//  CIS 22C
//
//  linkList.h

#ifndef ____List__
#define ____List__

#include <iostream>
#include "assert.h"
#include <cstddef>
#include "Hero.h"
using namespace std; // Less cout statement code

//============================= Linked List Template ============================
template <class listitem>
class List
{
    
private:
    struct Node
    {
        listitem data;
        Node* next;
        Node* previous;
        
        Node(): next(NULL), previous(NULL){} //define our own default constructor
        Node(listitem data): next(NULL), previous(NULL), data(data){}
    };
    
    typedef struct Node* NodeRef;
    
    NodeRef head;
    NodeRef tail;
    NodeRef iterator; //points to one node at a time
    int size;
    
public:
    /**Constructors and Destructors*/
    List();
    //Default constructor; initializes an empty list
    //Postcondition: int data - 0; head = null; tail = null; next - null;
    
    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: head = null;
    //
    List(const List &list);
    //Copy construcor. Initializes list to have the same elements as another list
    //Postcondition: Deep copy of List made;
    
    /**Accessors*/
    listitem back();
    //Returns the last element in the list
    //Precondition: Head != NULL
    //Postcondition: returned item is == to data from tail
    
    // ***** Cannot use current(), see linkList.cpp file for details ******** ERROR!
    
    listitem current();
    //Returns the element pointed to by the iterator
    //Precondition: head != NULL
    //Postcondition: data from iterator is returned
    
    bool empty();
    //Determines whether a list is empty.
    
    listitem front();
    //Returns the first element in the list
    //Precondition: head != NULL
    
    bool off_end();
    //Determines if the iterator is off the end of the list
    
    int get_size();
    //Returns the length of the list
    
    
    /**Manipulation Procedures*/
    
    void begin();
    //Moves the iterator to point to the first element in the list
    //If the list is empty, the iterator remains NULL
    //Postcondition: iterator == head
    
    
    void insert(listitem data);
    //Inserts a new element into the list in the position after the iterator
    //Precondition: Head != NULL
    //Postcondition: size++
    
    void pop_back();
    //Removes the value of the last element in the list
    //Precondition: iterator != NULL
    //Postcondition: int size--
    
    void pop_front();
    //Removes the value of the first element in the list
    //Precondition: head != NULL
    //Postcondition: int size--
    
    void push_back(listitem data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition: int size++
    
    void push_front(listitem data);
    //Inserts a new element at the front of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition: int size ++
    
    void remove();
    //Removes the element pointed at by the iterator
    //causing iterator to go off_End
    //Precondition: iterator != NULL
    //Postcondition: iterator == NULL; size--
    
    void scroll();
    //Moves the iterator forward by one element in the list
    //Has no effect if the iterator is offend or the list is empty
    //Postcondition: Iterator == Iterator->next
    
    
    /**Additional List Operations*/
    
    void print();
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    
    
};

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


#endif /* defined(____linkList__) */