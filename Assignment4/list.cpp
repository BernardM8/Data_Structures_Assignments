//Bernard Mulcahy
//Assignment 4 CS300 
//11/6/2020
//This submission is not complete due to a lack of time. 
#include "list.h"

// constructor
template<class T>
List<T>::List(){
     head = NULL; 
     tail = NULL;
} 

template<class T>
List<T>::~List(void)
{
    Node<T> *currNode = head, *nextNode = NULL;
    while (currNode != NULL)
    {
        nextNode = currNode->next;
        // destroy the current node
        delete currNode;
        currNode = nextNode;
    }
}

template<class T>
bool List<T>::IsEmpty()
{
    return head == NULL;
}

template<class T>
Node<T> *List<T>::InsertNode(int index, T x)
{
    if (index < 0)
        return NULL;

    int prevIndex = 0;
    Node<T> *prevNode = head;
    while (prevNode != NULL && index - 1 > prevIndex)
    {
        prevNode = prevNode->next;
        prevIndex++;
    }
    if (index > 0 && prevNode == NULL)
        return NULL;

    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    size++;
    if (index == size-1){
        tail = newNode;
    }
    return newNode;
}

template<class T>
int List<T>::FindNode(T x)
{
    Node<T> *currNode = head;
    int currIndex = 0;
    while (currNode && currNode->data != x)
    {
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
        return currIndex;
    return -1;
}

template<class T>
int List<T>::DeleteNode(T x)
{
    Node<T> *prevNode = NULL;
    Node<T> *currNode = head;
    int currIndex = 0;
    while (currNode != NULL && currNode->data != x)
    {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
    {
        if (prevNode)
        {
            prevNode->next = currNode->next;
            if (currNode->next==NULL){
            tail = prevNode;}
        }
        else
        {
            head = currNode->next;
            if (currNode->next ==NULL){
            tail = NULL;}
        }
        delete currNode;
        size--;
        return currIndex;
    }
    return -1;
}


template<class T>
void List<T>::AppendTail(T x)
{
    if (head == NULL){
        InsertNode(0,x);
    }else{
        Node<T> *newNode = new Node<T>;
        newNode->data=x;
        tail->next=newNode;
        tail = newNode;
        size++;
    }
}


template<class T>
string List<T>::OutputList()
{
    string output;
    Node<T> *currNode = head;
    while (currNode != NULL)
    {
        output+= (char)currNode->data;
        currNode = currNode->next;
    }
    return output;
}