//Name : Bernard M
//Course : CS300 Assignment-2
//Description : BookstoreManager header file

#include <string>
#include "Book.h"

using namespace std;

class BookstoreManager {

	private:
		int arraySize = 4;
        int bookCount = 0;
		Book** bookList;		

	public:

		BookstoreManager();
		void checkArraySize();
		BookstoreManager& operator=(const BookstoreManager& otherBookstoreManager);
		BookstoreManager(const BookstoreManager &otherBookstoreManager);
		~BookstoreManager();

		bool isEmpty();
		bool isFull();			
	    void listSize();
	    void print();
	    bool checkValidEntry(Book bookobj);
		void insert(Book bookobj);
		void shiftElementsUp(int result);
		void remove(Book bookobj);
		void removePublisher(string publisher);
		void search(Book bookObj);
		int binarySearch(int, int, int);
		
};

