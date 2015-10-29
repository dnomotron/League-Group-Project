//
//  HashTable.h
//  HashTable
//
//  Created by Dalton Rick on 10/28/15.
//  Copyright (c) 2015 Dalton Rick. All rights reserved.
//

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <iostream>
#include <cstdlib>

#define TABLE_SIZE 54

using namespace std;

class HashTable {
    
public:
    HashTable();
    
    //~HashTable();
    //Will write as part of Lab 6
    
    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size
    
    void addItem(string name, int index);
    //inserts a new item into the table
    // calls the hash function on the key title to determine the correct bucket
    
    //void removeItem(string key);
    //Will write as part of Lab 6
    //removes the item with the given key
    
    int numItemsAtIndex(int index);
    //Helper function to printTable
    //Counts the number of items in each bucket
    
    void printTable();
    //prints the first item of each bucket
    //includes the number of items stored at that bucket
    
    void printBucket(int index);
    //Will write as part of Lab 6
    //Prints all items stored at a particular bucket
    
    int findName(string name);
    //Searches for an author in the table using the key
    //returns the index under which the author is stored
    //returns -1 if the author is not foundk
    
private:
    
    struct Node
    {
        string name;
        int listIndex;
        Node* next;
        Node(): name(""), listIndex(-1), next(NULL){}
        Node(string ntitle, int nindex): name(ntitle), listIndex(nindex), next(NULL) {}
    };
    
        typedef struct Node* Nodeptr;
        Nodeptr Table[TABLE_SIZE];
    
};

HashTable::HashTable()
{
    
    for (int i=0; i<TABLE_SIZE; i++) {
        Table[i] = new Node();
    }
}
int HashTable::hash(string key){
    
    int index=0, sum = 0;
    
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % TABLE_SIZE; //dividing the summed ASCII values by 37 && storing remainder as my index
    return index;
}
void HashTable::addItem(string name, int index){
    
    
    int position = hash(name);
    
    if (Table[position]->name == "") {
        Table[position]->name = name;
        Table[position]->listIndex = index;
        
    }else if(Table[position]->next == NULL){
        
        Table[position]->next = new Node(name, index);
        
    }else{
        Nodeptr walker = Table[position]->next;
        while (walker->next) {
            walker = walker->next;
        }
        walker->next = new Node(name, index);
        
        
    }
}
int HashTable::numItemsAtIndex(int index){
    int count =1;
    
    Nodeptr walker = Table[index]->next;
    while (walker) {
        walker = walker->next;
        count++;
    }
    return count;
}
void HashTable::printTable(){
    
    for (int i=0; i < TABLE_SIZE; i++) {
        
        if (Table[i]->name !="") {
            cout << "Name: " << Table[i]->name << " Number of items in bucket: " << numItemsAtIndex(i) << endl;
        }
        
    }
    
}
void HashTable::printBucket(int index){
    
    Nodeptr walker = Table[index];
    
    while (walker) {
        cout << "Name: " << walker->name << endl;
        walker = walker->next;
    }
    
}
int HashTable::findName(string name){
    
    int index = hash(name);
    
    Nodeptr walker = Table[index];
    
    while (walker) {
        if (walker->name == name) {
            return walker->listIndex;
        }else{
            walker = walker->next;
        }
        
    }
    return -1;
}




#endif /* HASHTABLE_H_ */