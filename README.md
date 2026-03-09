# Monopoly-Board-Implementation

## Overview

This project implements a simplified Monopoly board using a circular linked list in C++. The board represents a ring of spaces that the player traverses using pointer-based movement rather than array indexing.

The goal of this project is to demonstrate correct linked list manipulation, traversal logic, and edge case handling.

The simulation allows a player to move around the board, land on spaces, and track how many times they pass GO.

---

# Data Structures Used

## MonopolySpace Class

Represents a single space on the Monopoly board.

Attributes:

* propertyName – name of the space
* propertyColor – color group
* value – property cost
* rent – rent amount

Methods:

* Constructor for initializing spaces
* isEqual() for comparing spaces
* print() for displaying space information

---

## Node Template Class

A generic node used in the circular linked list.

Each node contains:

* data – the MonopolySpace stored in the node
* nextNode – pointer to the next node

---

## CircularLinkedList Template Class

This class manages the Monopoly board.

Pointers used:

* headNode – first space on the board
* tailNode – last space on the board
* playerNode – current player position

Other variables:

* nodeCount – tracks number of spaces
* passGoCount – tracks how many times the player passes GO

The circular structure is maintained by always ensuring that the tail node points back to the head node. This creates a ring structure that allows traversal around the board indefinitely.

---

# Board Limit

The Monopoly board has a strict limit of 40 spaces.

The program enforces this using the constant MAX_SPACES = 40.

If an attempt is made to add a space when the board already contains 40 nodes, the insertion fails and the board remains unchanged.

---

# Functions Implemented

## Core Functions

### addSpace(T value)

Adds a new space to the end of the circular list.

Behavior:

* Creates a new node
* Updates the tail pointer
* Maintains circular structure
* Rejects insertion if the board already contains 40 spaces

---

### addMany(vector<T> values)

Adds multiple spaces sequentially.

Behavior:

* Attempts to insert each space
* Stops when the board reaches capacity
* Returns the number of spaces successfully added

---

### movePlayer(int steps)

Moves the player pointer forward by a number of steps.

Traversal is done node-by-node rather than using indexing.

Passing GO is detected when the player moves from the tail node to the head node. Each time this occurs, the passGoCount variable is incremented.

---

### printFromPlayer(int count)

Prints a fixed number of spaces starting from the player's current position.

This prevents infinite loops by limiting traversal to a fixed number of nodes.

---

### printBoardOnce()

Traverses the circular list exactly once starting from the head node.

A do-while loop is used so that each node is printed exactly once before stopping when the traversal returns to the head.

---

# Advanced Features Implemented

## removeByName(string name)

Deletes the first matching property by name.

Handles the following edge cases:

* deleting the head node
* deleting the tail node
* deleting the only node in the list
* updating the player position if the player's node is removed

The circular structure is preserved after deletion.

---

## findByColor(string color)

Searches the board for properties that match a given color.

The circular list is traversed exactly once and matching property names are stored in a vector and returned.

---

# Edge Case Handling

The program correctly handles:

* operations on an empty board
* single-node circular lists
* deleting the head node
* deleting the tail node
* removing the node where the player is currently located
* reaching the maximum board capacity
* traversal from the tail node back to the head node

These checks ensure the circular structure remains valid and prevents pointer corruption.
