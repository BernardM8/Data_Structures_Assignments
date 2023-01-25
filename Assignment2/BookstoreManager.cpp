//Name : Bernard M
//Course : CS300 Assignment-2
//Description : BookstoreManager class for OOP
#include <string>
#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

//default constructor O(1)
BookstoreManager::BookstoreManager(){
	Book** newBookList = new Book*[arraySize];
	this->bookList = newBookList;
}

//checks if array is full, if full reallocate the array and copy the data
void BookstoreManager::checkArraySize(){
	if (isFull()){
		arraySize=arraySize*2; 						//double size of array
		Book** tempBookList = new Book*[arraySize];
		//tempBookList = this->bookList;
		std::copy(bookList, bookList+bookCount ,tempBookList);
		delete bookList;
		//cout << "checkArraySize() bookCount=" <<bookCount<< endl;
		this->bookList = tempBookList;			//point booklist to resized array
	}
}

//Assignment operator O(n)
BookstoreManager& BookstoreManager::operator=(const BookstoreManager& otherBookstoreManager){
	//cout << "Assignment operator= trigger!" << endl;
	if (this != &otherBookstoreManager){
		this->arraySize = (otherBookstoreManager.arraySize);
		this->bookCount = otherBookstoreManager.bookCount;
		for (int i=0 ; i<bookCount; i++ ){
			this->bookList[i] = otherBookstoreManager.bookList[i];
		}
	}
	return *this;
}

//Copy Constructor
BookstoreManager::BookstoreManager(const BookstoreManager &otherBookstoreManager){
	this->arraySize = (otherBookstoreManager.arraySize);
	this->bookCount = otherBookstoreManager.bookCount;
	for (int i=0 ; i<bookCount; i++ ){
		this->bookList[i] = otherBookstoreManager.bookList[i];
	}
	//cout << "Copy Constructor" << endl;
}


//Destructor O(n)
BookstoreManager::~BookstoreManager(){
	for (int i=0 ; i<bookCount ; i++ ){
			this->bookList[i]->~Book();
		}
	//cout << "clear memory!" << endl;
}

//if array is empty return true otherwise return false O(1)
bool BookstoreManager::isEmpty(){
	if (bookCount>0){
		cout<<"false"<<endl;
		return false;
	}else {
		cout<<"true"<<endl;
		return true;}
}


//if array is full return true otherwise return false O(1)
bool BookstoreManager::isFull(){
	if(bookCount>=arraySize){
		cout<<"true"<<endl;
		return true;
	}else{
		cout<<"false"<<endl;
		return false;}
}


//prints the number of books in the array O(1)
void BookstoreManager::listSize(){
	cout<<bookCount<<endl;
}

//member function O(n)
void BookstoreManager::print(){
	for (int i=0 ; i<bookCount ;i++ ){
		cout<<bookList[i]->getTitle()<<endl;
		cout<<bookList[i]->getAuthors()<<endl;
		cout<<bookList[i]->getISBN()<<endl;
		cout<<bookList[i]->getPublisher()<<endl<<endl;
	}
}


//checks for duplicate or invalid entries O(n)
bool BookstoreManager::checkValidEntry(Book bookobj){
	for (int i=0 ; i<bookCount ;i++ ){
		if (bookList[i]->getISBN() == bookobj.getISBN()){
			return false;
		}
	}
	return true;
}


/*asks user to enter new book info, and it adds the book to the array in sorted
order if array is full, it’ll double the size of the array O(n)*/
void BookstoreManager::insert(Book bookobj){
	checkArraySize();
	//check if entry has duplicate isbn
	bool valid=checkValidEntry(bookobj);
	if (valid){
		//if list is empty add book
		if (bookCount==0){
			bookList[0] = new Book(bookobj.getTitle(),bookobj.getISBN(),bookobj.getAuthors(),bookobj.getPublisher());
			bookCount++;
		//add book if isbn is greater than last isbn book in list
		} else if (bookobj.getISBN() > bookList[bookCount-1]->getISBN()){
			bookList[bookCount] = new Book(bookobj.getTitle(),bookobj.getISBN(),bookobj.getAuthors(),bookobj.getPublisher());
			bookCount++;
		//shift element values and add book
		} else {
			for (int i=bookCount ; i>=0 ; i--){
				int check;
				if (i==0){check = 0;}
				else {check = bookList[i-1]->getISBN();}
				// create last element obj book and store with previous values
				if ((bookCount) == i){
					bookList[bookCount] = new Book(bookList[bookCount-1]->getTitle(),bookList[bookCount-1]->getISBN(),
								bookList[bookCount-1]->getAuthors(),bookList[bookCount-1]->getPublisher());
				// insert/overwrite target input into object book
				} else if (bookobj.getISBN() == i|| bookobj.getISBN() <= bookList[i]->getISBN() && bookobj.getISBN() > check){
					bookList[i]->setTitle(bookobj.getTitle());
					bookList[i]->setISBN(bookobj.getISBN());
					bookList[i]->setAuthors(bookobj.getAuthors());
					bookList[i]->setPublisher(bookobj.getPublisher());
					bookCount++;
					break;
				// shift object values up
				}else{
					bookList[i]->setTitle(bookList[i-1]->getTitle());
					bookList[i]->setISBN(bookList[i-1]->getISBN());
					bookList[i]->setAuthors(bookList[i-1]->getAuthors());
					bookList[i]->setPublisher(bookList[i-1]->getPublisher());
				}
			}	
		}
	}else{
		cout<<" Error ISBN already exists!"<<endl;
	}
}


//method to overwite result element and shift elements up O(n)
void BookstoreManager::shiftElementsUp(int result){
	for (int i=result ; i<=bookCount-1 ;i++ ){
		//delete last element
		if (i == bookCount-1){
			delete bookList[i+1];
			bookCount--;
		//shift elements up
		}else{
			bookList[i]->setTitle(bookList[i+1]->getTitle());
			bookList[i]->setISBN(bookList[i+1]->getISBN());
			bookList[i]->setAuthors(bookList[i+1]->getAuthors());
			bookList[i]->setPublisher(bookList[i+1]->getPublisher());
		}
	}
}

/*asks user to enter ISBN info, and it removes the book from the array; shifts the
other elements up in the array. Prints “Not Found” if search fails.*/
void BookstoreManager::remove(Book bookobj){
	int searchValue = bookobj.getISBN();
	int max = bookCount-1;
	int min = 0;
	int result = binarySearch(min, max, searchValue);
	if (result<0){
		cout<<"Not Found"<<endl;
	}else{
		shiftElementsUp(result);
	}
}


/*asks user to enter publisher name, and it removes all the books with the same
publisher from the array; shifts the other elements up in the array.
Prints “Not Found” if search fails. O(n)*/
void BookstoreManager::removePublisher(string publisher){
	int count=0;
	for (int i=0 ; i<bookCount ;i++ ){
		//cout<<"i = "<<i<<endl;
		if (publisher == bookList[i]->getPublisher()){
			//cout<<"trigger on element i = "<<i<<endl;
			shiftElementsUp(i);
			if (i!=bookCount){i--;}
			//cout<<"i after shift = "<<i<<endl;
			count++;
		}
	}
	//cout<<"count = "<<count<<endl;
	if (count==0){
			cout<<"Not Found"<<endl;
		}
}


//asks user to enter ISBN or title, and prints the content of the book
//prints “Not Found”, if book is not found.   O(log n )with binary search
void BookstoreManager::search(Book bookObj){
	int searchValue = bookObj.getISBN();
	int max = bookCount-1;
	int min = 0;
	int result = binarySearch(min, max, searchValue);
	if (result<0){
		cout<<"Not Found"<<endl;
	}else{
		cout<<bookList[result]->getTitle()<<endl;
		cout<<bookList[result]->getAuthors()<<endl;
		cout<<bookList[result]->getISBN()<<endl;
		cout<<bookList[result]->getPublisher()<<endl;
	}
}


//Binary search function O(log n)
int BookstoreManager::binarySearch( int min, int max, int x) {
	while (min <= max) {
		int mid = min + (max - min) / 2;
		// if x is found at mid
		if (bookList[mid]->getISBN() == x) {
			//cout<<"mid at if = "<<mid<<endl;
			return mid; }
		// If x greater, ignore left half
		else if (bookList[mid]->getISBN() < x) {
			min = mid + 1;
			//cout<<"min at elseif = "<<min<<endl;
			//cout<<"mid at elseif = "<<mid<<endl;
		// If x is smaller, ignore right half
		}else{
			//cout<<"max at else = "<<max<<endl;
			//cout<<"mid at else = "<<mid<<endl;
			max = mid - 1;}
	}
	//solution is not found
	return -1;
}



		


