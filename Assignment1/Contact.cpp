//Name : Bernard M
//Course : CS300 Assignment-1
//Description : Contact class for OOP

#include <iostream>
#include "Contact.h"
using namespace std;

Contact::Contact() {

}

Contact::Contact(string f, string l, string p){
	firstName=f;
	lastName=l;
	phoneNumber=p;
    //cout << "Create: " << firstName << ", " << lastName << ", " << phoneNumber <<endl;    	
}

Contact::~Contact(){
    //cout << "Destroy: " << firstName << ", " << lastName << ", " << phoneNumber <<endl;
}
    
void Contact::print(){
    //cout << firstName << ", " << lastName << ", " << phoneNumber <<endl;
}

string Contact::getFirstName(){
	return firstName;
}
string Contact::getLastName(){
	return lastName;
}
string Contact::getPhoneNumber(){
	return phoneNumber;
}

void Contact::setContactList(string first, string last, string phone){
	firstName = first;
	lastName = last;
	phoneNumber = phone;
}
