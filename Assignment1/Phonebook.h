//Name : Bernard M
//Course : CS300 Assignment-1
//Description : Phonebook class header file for OOP
#ifndef Phonebook_H
#define Phonebook_H
#include "Contact.h"
#include <iostream>
#include <string>

class Phonebook {
    private:

		//variables
		Contact** fullContactList;
		int lineCount;

    public:

		Phonebook();

		~Phonebook();

		void print();

		string getPhoneNumber(int lineNumber);

		void addNewContact(string first, string last, string phone);

		int searchForContact(string first, string last);

		void writeContactsToText();

		void deleteEntry(int lineFound);

};
#endif
