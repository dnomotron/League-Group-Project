//  Dalton Rick
//
//  CIS 22C
//
//  linkList.h

#ifndef ____List__
#define ____List__

#include <iostream>
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

#endif /* defined(____linkList__) */