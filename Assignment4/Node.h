//Bernard M
//Assignment 4 CS300 
//Header file for Node class
#ifndef NODE
#define NODE

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};
#endif
