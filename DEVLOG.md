# Development Log

## Entry 1 – Setting Up the Board Structure

The first thing I worked on was creating the basic classes needed for the board. I implemented the `MonopolySpace` class to store information about each property (name, color, value, and rent). After that, I created a generic `Node` class that can store a space and point to the next node.

Then I started building the `CircularLinkedList` class that will represent the Monopoly board. The key design idea was that the board should act like a ring, so the tail node always points back to the head node.
---

## Entry 2 – Implementing addSpace

Next I implemented the `addSpace` function to insert spaces into the circular list. At first I forgot to reconnect the tail back to the head after inserting a new node, which broke the circular structure. The board would stop traversing once it reached the tail.

The fix was making sure that after every insertion the following relationship is preserved:

tailNode -> nextNode = headNode

Once that was fixed, I tested adding multiple spaces and confirmed the list stayed circular.

---
