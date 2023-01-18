//#include <cstddef>
#include "UPC.h"
#ifndef NODE_H
#define NODE_H

template <class T>
struct Node{  
    //T data;
    //T description;

    UPC storedItems;
    Node<T> *left;
    Node<T> *right;

//constructors
    Node(UPC storedItems):storedItems(storedItems), left(NULL), right(NULL){}
    //Node(T data, T description):data(data), description(description), left(NULL), right(NULL){}
    
//getters
    //long getUPC(){return storedItems.getData;}
    //string getDesciptUPC(){return storedItems.getDescription();}
//setters
    //void setUPC(long input){storedItems.setData(input);}
    //void setDesciptUPC(string input){storedItems.setDescription(input);}

//member functions   
    bool isLeaf(){ return left==NULL && right ==NULL;} 
    bool isFull(){ return left!=NULL && right !=NULL;}
};
#endif