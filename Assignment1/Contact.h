//Name : Bernard M
//Course : CS300 Assignment-1
//Description : Contact class for OOP
#ifndef Contact_H
#define Contact_H
#include <iostream>
#include <string>
using namespace std;

class Contact {
    private:
		//variables
    	string firstName;
    	string lastName;
    	string phoneNumber;

    public:
    	Contact(); //default constructor
    	Contact(string first, string last, string phone); //3 parameter constructor  	
    	~Contact();//Destructor
    	void print();//member function

    	//getter
		string getFirstName();
		string getLastName();
		string getPhoneNumber();

    	//setter
    	void setContactList(string first, string last, string phone);
		
};
#endif
