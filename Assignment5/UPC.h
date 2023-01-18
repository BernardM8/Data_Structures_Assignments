//Name : Bernard Mulcahy
//Course : CS300 Assignment-5
//Date : November 17 2020
//Description : UPC header object for the UPC barcode reader 

#ifndef UPC_H
#define UPC_H
#include<iostream>
#include <string>
using namespace std;

class UPC{
public:

    long data;
    std::string description;
    
//constructors
    UPC (long data):data(data){}
    UPC (long data, std::string description):data(data), description(description){}

//getters
    long getData(){ return data;}
    std::string getDescription(){ return description;}

//setters
    void setData(long input){data = input;}
    void setDescription(string input){description = input;}
};
#endif