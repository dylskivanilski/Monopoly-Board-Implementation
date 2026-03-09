#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

static const int MAX_SPACES = 40;

// ---------------------
// represents one board space
// ---------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace(){
        propertyName="";
        propertyColor="";
        value=0;
        rent=0;
    }

    MonopolySpace(string n,string c,int v,int r){
        propertyName=n;
        propertyColor=c;
        value=v;
        rent=r;
    }

    bool isEqual(MonopolySpace other){
        return propertyName == other.propertyName;
    }

    void print(){
        cout << propertyName << " | "
             << propertyColor << " | $"
             << value << " | Rent "
             << rent << endl;
    }
};
/*
DAY 1 NOTES
-----------
Today I started the project by defining what a Monopoly board space should store.
I created the MonopolySpace class with the property name, color group, value,
and rent. I also added a print function so spaces can display their information.
*/
