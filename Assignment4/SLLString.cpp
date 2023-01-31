//Bernard M
//Assignment 4 CS300 
//Description : SLLString class for OOP
#include "SLLString.h"
#include "Node.h"
#include <algorithm>


//Default constructor
SLLString::SLLString(){
	Node<char>* node = new Node<char>();
	this->head = node;
}


//Function to add a new node to the Linked List
Node<char>* SLLString::add(char data){
	Node<char>* newnode = new Node<char>;
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}


//Single parameter constructor
SLLString::SLLString(string n){
	Node<char> *currNode = new Node<char>;
	SIZE=n.size();
	for (size_t i=0;i<n.size(); i++){
		if (i==0){
			head = add(n[i]);
			currNode = head;
		}else{
			currNode->next = add(n[i]);
			currNode = currNode->next;
		}
	}
}


//Destructor.
SLLString::~SLLString(){
}


//copy constructor taking another SLLString
SLLString::SLLString(const SLLString& other){
	SIZE=other.SIZE;
	head=other.head;
}


// assignment operator
SLLString& SLLString::operator=(const SLLString& other){
	SLLString temp(other);
	std::swap(temp.SIZE, SIZE);
	std::swap(temp.head, head);
	return *this;
}


// concatenation operator
SLLString& SLLString::operator+= (const SLLString& other){
	Node<char>* current = this->head;
	SIZE +=other.SIZE;
	if (head == NULL){
	  head=other.head;
	}else{
		while (current!= NULL) {
			if(current->next ==NULL){
				current->next= other.head;
				break;
			}
			current = current->next;
		}
	}
	return *this;
}


// get length of this string.
int SLLString::length(){
	return SIZE;
}


//get character at index n.
char& SLLString::operator[](const int n){
	Node<char>* current = head;
	for (int i=0;i<n; i++){
		if (i==n){
			current = head;
		}else{
			current = current->next;
		}
	}
	return current->data;
}


// find the index of the first occurrence of substring in the current string. Returns -1 if not found.
int SLLString::findSubstring(string s){
	Node<char>* current = this->head;
	int result=-1;
	int i=0;	//to iterate linkedlist
	int j=0;	//to iterate matched string char's
	int strLen=s.size();
	while (current!= NULL) {
		if (current->data==s[0]){
			result = i;
			j++;
		}else if(current->data==s[j]){
			j++;
			if(j==strLen){
				return result;
			}
		}
		current = current->next;
		i++;
	}
	return result;
}


//erase all occurrences of character c from the current string.
void SLLString::erase(char c){
	Node<char>* current = this->head;
	Node<char>* prevNode = NULL;
		while (current!= NULL) {
			if (current->data==c){
				//erase data and reconnect nodes
				current->data = 0;
				prevNode->next=current->next;
				SIZE--;
				current = current->next;
			}else{
				prevNode = current;
				current = current->next;
			}
		}
}


//support cout << operator
ostream& operator<<(ostream &out, const SLLString& list){
	Node<char>* current = list.head;
	while (current!= NULL) {
		cout << current->data;
		current = current->next;
	}
	return out;
}



