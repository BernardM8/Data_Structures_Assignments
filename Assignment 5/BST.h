//Name : Bernard Mulcahy
//Course : CS300 Assignment-5
//Date : November 17 2020
//Description : Node header file for UPC barcode reader 

#ifndef BST_H
#define BST_H
#include "node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class BST{

    Node<T> *root;

public:
    BST();
    void insert(UPC item);
    bool findUPC(T item);
    void printInOrder();

    void exportDot(string filename);
    //bool find(T item);
    // T &findMax();
    // T &findMin();
    // bool erase(T item);
};
#endif