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
    
    // destructor so memory isn't leaked
    ~CircularLinkedList(){
        clear();
    }


    // ---------------------
    // add one board space
    // ---------------------
    bool addSpace(T value){

        if(boardFull()){
            cout<<"Board already full\n";
            return false;
        }

        Node<T>* newNode = new Node<T>(value);

        if(headNode == nullptr){

            headNode = newNode;
            tailNode = newNode;
            playerNode = newNode;

            newNode->nextNode = headNode;
        }
        else{

            tailNode->nextNode = newNode;
            tailNode = newNode;

            // keep circle intact
            tailNode->nextNode = headNode;
        }

        nodeCount++;
        return true;
    }

/*
DAY 5 NOTES
-----------
Today I implemented the addSpace function that allows properties
to be inserted into the board. I handled the special case where
the first node becomes the head, tail, and starting player position.
*/

    // ---------------------
    // add many spaces
    // ---------------------
    int addMany(vector<T> values){

        int spacesAdded = 0;

        for(T v : values){
            if(addSpace(v))
                spacesAdded++;
            else
                break;
        }

        return spacesAdded;
    }

/*
DAY 6 NOTES
-----------
Today I added the addMany function so multiple spaces can be
inserted at once when building the board. This makes board
setup much faster.
*/

    // ---------------------
    // move player pointer
    // ---------------------
    void movePlayer(int steps){

        if(playerNode == nullptr){
            cout<<"Board empty\n";
            return;
        }

        for(int i=0;i<steps;i++){

            // if we move from tail -> head we passed GO
            if(playerNode == tailNode)
                passGoCount++;

            playerNode = playerNode->nextNode;
        }

        cout<<"Player landed on: ";
        playerNode->data.print();
    }

/*
DAY 7 NOTES
-----------
Today I implemented the player movement system. The movePlayer
function advances the player pointer through the circular list
based on the number of dice steps rolled.
*/

    int getPassGoCount(){
        return passGoCount;
    }

    // ---------------------
    // show next spaces
    // ---------------------
    void printFromPlayer(int count){

        if(playerNode == nullptr) return;

        Node<T>* currentNode = playerNode;

        for(int i=0;i<count;i++){
            currentNode->data.print();
            currentNode = currentNode->nextNode;
        }
    }

/*
DAY 8 & 9 NOTES
-----------
I added logic to track how many times the player passes
the GO space. This happens when the player moves from the
tail node back to the head node. Also created a function to preview upcoming board spaces
from the player's current position. This helps visualize
future positions during the simulation.
*/
