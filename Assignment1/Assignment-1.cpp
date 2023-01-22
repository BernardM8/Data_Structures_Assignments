//Name : Bernard M
//Course : CS300 Assignment-1
//Description : Phonebook application to search, delete, or add contacts

#include <iostream>
#include <fstream>
#include "Phonebook.h"
using namespace std;

//Method to print operation and check if the input entry is valid
char printAndCheckEntry(){
	bool check = true;
	while (check){
		//print operation choices
		cout<<"A(Add) | S (Search) | D(Delete) |L(List) |Q(Quit): ";
		string entryInput;
		cin>>entryInput;
		//check if entry is valid
		if (entryInput.size() ==1 ){
		   char decision = entryInput[0];
			if (decision == 'A'||decision == 'S'||decision == 'D'||decision == 'L'||decision == 'Q'){
				return decision;
				check = false;
			}else{
				cout<<"ERROR, you did not enter a valid entry"<<endl;
				cout<<"Choose single character entries with caps"<<endl;
			}
		}else{
			cout<<"ERROR, you did not enter a valid entry"<<endl;
			cout<<"Choose a single character of the following"<<endl;
		}
    }
}


// Main Program
int main(){
    //setup object array and variables 
	Phonebook* phonebook = new Phonebook();
    bool quit = false;
    cout<<endl<<"***MY PHONEBOOK APPLICATION***"<<endl;
    cout<<"Please choose an operation:"<<endl;

    //main while loop
    while (quit==false){
        //run method that prints operation and checks input validation
        char decision=printAndCheckEntry();
        //Add a contact 
        if (decision == 'A'){           
            string enteredFirstName, enteredLastName , enteredPhoneNum;
            cout<<"Enter full name: ";
            cin>>enteredFirstName>>enteredLastName;
            cout<<"Enter phone number: ";
            cin>>enteredPhoneNum;
            phonebook->addNewContact(enteredFirstName, enteredLastName, enteredPhoneNum);
            cout<<endl;
        //Search for phone number for given name
        } else if (decision == 'S'){
            string enteredFirstName, enteredLastName;
            cout<<"Enter full name: ";
            cin>>enteredFirstName>>enteredLastName;
            int lineFound =phonebook->searchForContact(enteredFirstName,enteredLastName);
            if (lineFound>=0){
                cout<<"Phone Number: "<<phonebook->getPhoneNumber(lineFound)<<endl<<endl;
            }else {
                cout<<"Entered name is not found"<<endl;
            }  
        //Delete contact for given name
        } else if (decision == 'D'){
            string enteredFirstName, enteredLastName;
            cout<<"Enter full name: ";
            cin>>enteredFirstName>>enteredLastName;
            int lineFound =phonebook->searchForContact(enteredFirstName,enteredLastName);
            if (lineFound>0){
            	phonebook->deleteEntry(lineFound);
                cout<<endl;                    
            } else {
                cout<<"Entered name is not found"<<endl;
            }
        //List or Display all contacts 
        } else if (decision == 'L'){ 
        	phonebook->print();
        //Quit by killing Main while loop
        } else if (decision == 'Q'){
            quit = true;
        } 
    }//end of main while loop

    //upload changes to txt file
    phonebook->writeContactsToText();
    //delete memory
    phonebook->~Phonebook();
    return 0;
}
