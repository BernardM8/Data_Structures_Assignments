//Name : Bernard M
//Course : CS300 Assignment-2
//Description : Book store application to search, remove, or insert books

#include <string>
#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"
using namespace std;

int main() {
BookstoreManager bookstoreManager; 

//prints true if the bookstore is empty
bookstoreManager.isEmpty();

//insert 4 books
string title, authors, publisher, isbnStr;
int isbn;
for(int i=0;i<4;i++){
    cout<<"Enter book title: ";
    //cin>>title;
    getline(std::cin, title);
    cout<<"Enter authors: ";
    //cin>>authors;
    getline(std::cin, authors);
    cout<<"Enter isbn: ";
    //cin>>isbn;
    getline(std::cin, isbnStr);
    cout<<"Enter publisher: ";
    //cin>>publisher;
    getline(std::cin, publisher);
    isbn=stoi(isbnStr);
    Book aBook(title, isbn, authors, publisher);
    bookstoreManager.insert(aBook);
    cout<<endl;
}

//print bookstore
bookstoreManager.print();

//search for books
cout<<"Searching…"<<endl;
cout<<"ISBN:";
cin>>isbn;
Book b2(isbn);
bookstoreManager.search(b2);

//remove a book
cout<<"Removing…"<<endl;
cout<<"ISBN:";
cin>>isbn;
Book b1(isbn);
bookstoreManager.remove(b1);

//print bookstore
bookstoreManager.print();

//remove books from a particular publisher
cout<<"Removing publisher"<<endl;
cout<<"Publisher:";
cin>>publisher;
bookstoreManager.removePublisher(publisher);

//print bookstore
bookstoreManager.print();

//prints the number of books
bookstoreManager.listSize();

return 0;
}
