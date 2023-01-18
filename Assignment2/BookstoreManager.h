//Name : Bernard Mulcahy
//Course : CS300 Assignment-2
//Date : October 17 2020
//Description : BookstoreManager header file

#include <string>
#include "Book.h"

using namespace std;

class BookstoreManager {

	private:
		int arraySize = 2;
        int bookCount;
		Book** bookList;		

	public:

		BookstoreManager();
		BookstoreManager(const BookstoreManager &otherBookstoreManager);
		~BookstoreManager();
		void checkArraySize();
		void deepCopy(const BookstoreManager &otherBookstoreManager);
		BookstoreManager operator=(const BookstoreManager &otherBookstoreManager);
	    void print();
		bool isEmpty();
		bool isFull();			
	    void listSize();
		bool checkValidEntry(Book bookobj);
		void insert(Book bookobj);
		void remove(Book bookobj);
		void removePublisher(string publisher);
		void search(Book bookObj);
		int binarySearch(int, int, int);
		void shiftElementsUp(int);
		int seqSearchPub(string);
		
};

