//Name : Bernard M
//Course : CS300 Assignment-2
//Description : headerfile for Book
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book{
    
    private:
        string title;
    	string authors;
    	string publisher;
		int ISBN;

    public:

        //Book();
        Book(int);
        Book(string,int,string,string);
        ~Book();
        void print();

        //Getters
        string getTitle();
		string getAuthors();
		string getPublisher(); 
		int getISBN(); 

    	//setters
    	void setTitle(string t);
		void setAuthors(string a);
		void setPublisher(string p);
		void setISBN(int i);

};
#endif
