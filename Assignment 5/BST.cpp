//Name : Bernard Mulcahy
//Course : CS300 Assignment-5
//Date : November 17 2020
//Description : Binary search tree for UPC barcode reader 

#include "BST.h"
#include<cstddef>
#include <cstdlib>
#include<iostream>
#include <sstream>
#include <string.h>
using namespace std;

template <class T>
BST<T>::BST(){
    root = NULL;
}


template <class T>
void BST<T>::insert(UPC item){
    insert2(root, item);
}

template <class T>
void insert2(Node<T> *&root, UPC item){
    if(root == NULL){
        root = new Node<T>(item);
    }
    else if (item.getData() > root->storedItems.getData()){
        insert2(root->right, item);
    }else {
        insert2(root->left, item);
    }
}


template <class T>
bool BST<T>::findUPC(T item){
    return findUPC2(root, item);
}

template <class T>
bool findUPC2(Node<T> *root, T item){	 		
    // if item is found 
    if (root->storedItems.getData() == item.getData()) {
        cout<<endl<<"UPC Code:"<<root->storedItems.getData()<<endl;
        cout<<"Description: "<<root->storedItems.getDescription()<<endl;
        return true; }
    // If item greater, ignore left half 
    else if (root->storedItems.getData() < item.getData()) {
        //cout<<"greater = "<<root->storedItems.getData()<<endl;
        if (root->right !=NULL){
            return findUPC2(root->right, item);
        }else{
            cout<<"Not found"<<endl;
            return false;
        }
    }		
    // If item is smaller, ignore right half 
    else {
        //cout<<"less = "<<root->storedItems.getData()<<endl;
        if (root->left !=NULL){
            return findUPC2(root->left, item);
        }else{
            cout<<"Not found"<<endl;
            return false;
        }
    }  
} 

//_________________________Items below are not necessary__________________
//used to print values or graph tree structure

template <class T>
void BST<T>::printInOrder(){
    printInOrder2(root);
}

template <class T>
void printInOrder2(Node<T> *root){
    if(root !=NULL){
       printInOrder2(root->left);
       cout<<"UPC = "<< root->storedItems.getData() <<endl;  
       cout<<"Description = "<< root->storedItems.getDescription() <<endl;
       printInOrder2(root->right);
    }
}


template <class T>
void bst_print_dot_null(Node<T> *&node, int nullcount, FILE *stream)
{
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %s -> null%d;\n", addressToString(node).c_str(), nullcount);
}

template <class T>
void bst_print_dot_aux(Node<T> *&node, FILE *stream)
{
    static int nullcount = 0;

    if (node->left)
    {
        fprintf(stream, "    %s -> %s;\n", addressToString(node).c_str(), addressToString(node->left).c_str());
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    %s -> %s;\n", addressToString(node).c_str(), addressToString(node->right).c_str());
        bst_print_dot_aux(node->right, stream);
    }
    else
        bst_print_dot_null(node, nullcount++, stream);
}

template <class T>
string addressToString(Node<T> *&root)
{
    stringstream ss;
    ss << root;
    string name = ss.str();
    return "a" + name + "_" + to_string(root->storedItems.getData());
}

template <class T>
string createLabels(Node<T> *&tree)
{
    if (tree == NULL)
        return "";

    string address = addressToString(tree);

    string label = address + " [label=\"" + to_string(tree->storedItems.getData()) + "\"]\n";

    return createLabels(tree->left) + label + createLabels(tree->right);
}


template <class T>
void BST<T>::exportDot(string filename)
{
    FILE *file = fopen(filename.c_str(), "w");
    bst_print_dot(root, file);
}

template <class T>
void bst_print_dot(Node<T> *tree, FILE *stream)
{
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, createLabels(tree).c_str());
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %s;\n", addressToString(tree).c_str());
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}


/*
template <class T>
bool BST<T>::find(T item){
    return find2(root,item);
}

template <class T>
bool find2(Node<T> *root, T item){
    if (root=NULL){        
        return false;
    }
    if (root->data ==item){   
        return true;
    }
    else if (root->data < item){
        return find2(root->right, item);
    } else {
        return find2(root->left, item);
    }
}


template <class T>
T &BST<T>::findMax(){
    if (root=NULL){ 
            cout <<"tree is empty"<< endl;
            exit(0);
        }
        return findMax2(root);
}
template <class T>
T &findMax2(Node<T> *root){
    if (root->right==NULL){ 
        return root->data;
    }
    return findMax2(root->right);
}


template <class T>
T &BST<T>::findMin(){
    if (root=NULL){ 
        cout <<"tree is empty"<< endl;
        exit(0);
    }
    return findMin2(root);
}

template <class T>
T &findMin2(Node<T> *root){
    if (root->left==NULL){ 
        return root->data;
    }
    return findMin2(root->left);
}



template <class T>
bool BST<T>::erase(T item){
    return erase2(item, root);
}

template <class T>
bool erase2(T item, Node<T> *&rootInSubtree){
    if (rootInSubtree == NULL){
        return false;}
    if (item == rootInSubtree->data){
        if (rootInSubtree->isLeaf()){
            delete rootInSubtree;
            rootInSubtree = NULL;
        }
        else if(rootInSubtree->isLFull()){
            rootInSubtree->data = findMin2(rootInSubtree->right);
            erase2(item, rootInSubtree->right);
        }else{
            Node<T> *toDelete = rootInSubtree;
            if (rootInSubtree->left==NULL){
                rootInSubtree = rootInSubtree->right;
            }else{
                rootInSubtree = rootInSubtree->left;
            }
            delete toDelete;
        }
        return true;
    }
    else if (item<rootInSubtree->data){
        return erase2(item, rootInSubtree->left); 
    } else {
        return erase2(item, rootInSubtree->right); 
    }
}



*/