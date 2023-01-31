//Bernard M
//Assignment 4 CS300 
//Header file for SLLSTring class
#include "list.h"
#include "Node.h"
using namespace std;

class SLLString
{
private:
    Node<char>* head; // the head pointer to the SLL.
	int SIZE = 0;

public:
	SLLString(); //Default constructor
    SLLString(string n); //single parameter constructor taking a string as parameter.
    Node<char>* add(char data);// Function to add a new node to the Linked List
    ~SLLString(); // Destructor.

	SLLString(const SLLString& other); //copy constructor taking another SLLString

    SLLString& operator=(const SLLString& other); // assignment constructor
	SLLString& operator+= (const SLLString& other); // concatenation
	int length(); // get length of this string.
	
	char& operator[](const int n); //get character at index n.
	int findSubstring(string s); // find the index of the first occurrence of substring in the current string. Returns -1 if not found.
	void erase(char c); //erase all occurrences of character c from the current string.
	friend ostream &operator<<(ostream &out, const SLLString &list); //support cout << operator.
};
