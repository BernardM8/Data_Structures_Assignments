//Name : Bernard Mulcahy
//Course : CS300 Assignment-5
//Date : November 17 2020
//Description : UPC barcode reader application main

#include <iostream>
#include <fstream>   
#include <vector>
#include <sstream>
#include "UPC.h" 
#include "BST.h"  
#include "BST.cpp" 
#include <time.h>
#include <string.h>
using namespace std;

//method to read txt file and store into UPC and build BST
BST<UPC> buildTree(string fileName){  
	BST<UPC> tree;
	string line;
	string partial;
    ifstream file;
    file.open(fileName);//file name is test.txt
	getline(file, line);//read past first line
    while(getline(file, line)){	//read each line into line string
		stringstream LineStream(line);
		long upc;
		string description;
		for (int i=0; i<=4; i++){
			getline(LineStream, partial,'\t');
			if (i==2){ //trigger upc12
				upc = stol(partial);
			}		
			if (i==4){ //trigger name/description
				description=partial;	
			}
		}
		UPC item(upc, description);
		tree.insert(item);	
    }
	file.close();
	//tree.printInOrder();
	//tree.exportDot("mytree.dot");
	return tree;
}

//method to search BST and log clock
void performSearchBST(BST<UPC> tree, UPC key){
	clock_t t;
	t = clock();	
	bool result = tree.findUPC(key); //find key 
	t = clock() - t;
	cout << "time: " << t << " miliseconds" << endl;
}

//check that user entry is a number, and not greater in length than 12
bool validateEntry(string str){
	if (str.length()>12){return false;}
	for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false; //when one non numeric value is found, return false
      return true;
}


//Started code for Assignment5
//You are allowed to add, but not remove statements 
int main() {
	string filename = "Grocery_UPC_Database.txt";
	BST<UPC> tree = buildTree(filename);  //build binary search tree of UPC objects
	string code;
	cout << "Please enter a UPC code(! to quit): ";
	cin >> code;
	while (code != "!") {
		if (validateEntry(code)){ //check if user input is valid
        	long entry = stol(code); //convert user inputted string to type long int
			UPC key(entry);
			performSearchBST(tree, key);	
		}else{
			cout << "\nYour entry was not valid! ";
		}
		cout << "\nPlease enter a UPC code(! to quit): ";
		cin >> code;
	}
	return 0;
} 
