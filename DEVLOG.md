# Development Log

## Entry 1 – Setting Up the Board Structure

The first thing I worked on was creating the basic classes needed for the board. I implemented the `MonopolySpace` class to store information about each property (name, color, value, and rent). After that, I created a generic `Node` class that can store a space and point to the next node.

Then I started building the `CircularLinkedList` class that will represent the Monopoly board. The key design idea was that the board should act like a ring, so the tail node always points back to the head node.
