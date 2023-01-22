//Name : Bernard M
//Course : CS300 Assignment-1
//Description : Phonebook class for OOP

#include "Phonebook.h"
#include "Contact.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;


//default constructor reads .txt file and store values to object array
Phonebook::Phonebook(){
	Contact** contactList = new Contact*[250000];
	int count = 0;
		std::ifstream file("phonebook.txt");
		if(file.is_open()){
			std::string strLine = "";
			string firstName, lastName ,phoneNumber;
			while (std::getline(file,strLine)){
				std::istringstream iss(strLine);
				iss>>firstName>>lastName>>phoneNumber;
				contactList[count] = new Contact(firstName,lastName,phoneNumber);
				count++;
			}
			file.close();
		}
		lineCount=count;
		fullContactList=contactList;
};

//Destructor
Phonebook::~Phonebook(){
	for (int i = 0; i <lineCount; ++i){
		fullContactList[i]->~Contact();
	}
	//cout << "Phonebook Destroyed" <<endl;
}

//print member function
void Phonebook::print(){
	for (int i = 0; i <lineCount; ++i){
		cout<<fullContactList[i]->getFirstName()<<" "<<fullContactList[i]->getLastName()<<" "<<fullContactList[i]->getPhoneNumber()<<endl;
	}
	 cout<<endl;
};

//getter of phone number
string Phonebook::getPhoneNumber(int lineNumber){
	string phoneNumber = fullContactList[lineNumber]->getPhoneNumber();
	return phoneNumber;
}

//method to search for name, outputs array number if found, otherwise outputs -1
int Phonebook::searchForContact(string first, string last){
	for (int i = 0; i != lineCount; ++i){
		if (first==fullContactList[i]->getFirstName()&& last==fullContactList[i]->getLastName()){
			return i;
		}
	}
	return -1;
}

//method to add a new contact
void Phonebook::addNewContact(string first, string last, string phone){
	fullContactList[lineCount] = new Contact(first,last, phone);
	lineCount++;
}

//method to write contacts to .txt file
void Phonebook::writeContactsToText(){
	std::ofstream outfile("phonebook.txt");
		for (int j = 0; j < lineCount; j++){
			if (j < lineCount-1){
				outfile<<fullContactList[j]->getFirstName()<<" "<<fullContactList[j]->getLastName()<<" "<<fullContactList[j]->getPhoneNumber()<<endl;
			}else if (j < lineCount) {//so there is no extra line that's empty
				outfile<<fullContactList[j]->getFirstName()<<" "<<fullContactList[j]->getLastName()<<" "<<fullContactList[j]->getPhoneNumber();
			}
		}
		outfile.close();
}

//method to delete a contact
void Phonebook::deleteEntry(int lineFound){
	while (lineFound<lineCount-1){ //loop & overwrite current object array data with next data
		fullContactList[lineFound]->setContactList(fullContactList[lineFound+1]->getFirstName(),
				fullContactList[lineFound+1]->getLastName(), fullContactList[lineFound+1]->getPhoneNumber());
	    lineFound++;
	}
	delete fullContactList[lineFound];
	lineCount--;
}

