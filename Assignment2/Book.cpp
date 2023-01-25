//Name : Bernard M
//Course : CS300 Assignment-2
//Description : Book class for OOP

#include <iostream>
#include "Book.h"
using namespace std;

//Book();//Default constructor

Book::Book(int isbn){//1 parameter constructor
	this->ISBN = isbn;
} 

Book::Book(string title, int isbn, string authors, string publisher){ //4 parameter constructor  
	this->title = title;
	this->ISBN = isbn;
	this->authors = authors;
	this->publisher = publisher;
}

Book::~Book(void){//Destructor
    //cout<<"deleting Book object"<<endl;
}

void Book::print(){//member function
	cout<<"title :"<<title<<"ISBN :"<<ISBN<<"authors :"<<authors<<"publisher :"<<publisher<<endl;
};

//getter
string Book::getTitle(){ 
    return title; 
}
string Book::getAuthors(){ 
    return authors; 
}
string Book::getPublisher(){ 
    return publisher; 
}
int Book::getISBN(){ 
    return ISBN; 
}

//setter
void Book::setTitle(string t){
    title = t;
}
void Book::setAuthors(string a){
    authors = a;
}
void Book::setPublisher(string p){
    publisher = p;
}
void Book::setISBN(int i){
    ISBN = i;
}
