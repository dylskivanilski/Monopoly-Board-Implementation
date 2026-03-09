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

## Entry 3 – Adding Player Movement

After the board structure was working, I implemented the `movePlayer` function. The player position is stored using a pointer (`playerNode`) that moves through the circular list.

The movement is done step-by-step instead of using indexing. Each step simply moves the pointer to `nextNode`.

One challenge was detecting when the player passes GO. I solved this by checking when the player moves from the tail node to the head node. When that happens, the `passGoCount` variable increases.

---


## Entry 4 – Fixing a Traversal Bug

While testing the print functions, I accidentally created an infinite loop because I used a normal `while` loop when printing the board.

Since the list is circular, it never reaches `nullptr`. To fix this I switched to a `do-while` loop that stops once the traversal returns to the head node.

This guarantees that each node is visited exactly once.

---
