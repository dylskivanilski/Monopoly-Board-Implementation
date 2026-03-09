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


// ---------------------
// node for circular list
// ---------------------
template <typename T>
class Node{
public:
    T data;
    Node<T>* nextNode;

    Node(T v){
        data=v;
        nextNode=nullptr;
    }
};

/*
DAY 2 NOTES
-----------
Today I started building the data structure for the board.
I created a Node class that will be used for the circular linked list.
Each node stores a MonopolySpace and a pointer to the next space.
*/

// ---------------------
// circular linked list board
// ---------------------
template <typename T>
class CircularLinkedList{

/*
DAY 3 NOTES
-----------
Today I began implementing the CircularLinkedList class that will represent
the Monopoly board. I added the private member variables including headNode,
tailNode, and playerNode to track the structure of the board and the player's
current position.
*/

private:

    Node<T>* headNode;
    Node<T>* tailNode;
    Node<T>* playerNode;

    int nodeCount;
    int passGoCount;

    bool boardFull(){
        return nodeCount >= MAX_SPACES;
    }

public:

    CircularLinkedList(){
        headNode=nullptr;
        tailNode=nullptr;
        playerNode=nullptr;
        nodeCount=0;
        passGoCount=0;
    }
    
/* 
DAY 4 NOTES
-----------
Today I worked on initializing the board structure correctly.
The constructor sets all pointers to nullptr and resets counters
so the board starts empty before spaces are added.
*/
    
