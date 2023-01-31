//Bernard Mulcahy
//Assignment 4 CS300 
//11/6/2020
//This submission is not complete due to a lack of time. 
#ifndef LIST
#define LIST

#include <iostream>

#include "Node.h"
using namespace std;

template <class T>
class List
{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size = 0;

    public:
        List();         // constructor
        ~List();        // destructor
        bool IsEmpty();
        Node<T> *InsertNode(int index, T x);
        int FindNode(T x);
        int DeleteNode(T x);
        //void DisplayList();
        string OutputList();
        void AppendTail(T x);
};
#endif