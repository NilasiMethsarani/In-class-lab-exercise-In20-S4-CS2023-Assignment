# In-class-lab-exercise-In20-S4-CS2023-Assignment

#In-class-lab-06 Index: 200395P

Question 01

In this implementation, I have defined a class Stack that contains an array arr of integers and a variable top to keep track of the index of the top element in the stack. We have also defined the functions push, pop, isEmpty, isFull, stackTop, and display that correspond to the operations performed on a stack.

In the push function, I check if the stack is full, and if not, we increment the top variable and insert the element at the top of the stack. In the pop function, we check if the stack is empty, and if not, we remove the element at the top of the stack and decrement the top variable.

The isEmpty and isFull functions check if the stack is empty or full, respectively. The stackTop function returns the element at the top of the stack without removing it. Finally, the display function prints all the elements in the stack, starting from the top.

Question 02

The code provided is an implementation of a Stack data structure using a singly linked list in C++. The linked list is composed of a series of nodes, where each node contains an integer value and a pointer to the next node in the list.

The Stack class provides functions for adding and removing elements from the top of the stack, checking if the stack is empty, returning the top element, and displaying the contents of the stack. The push() function adds a new node to the beginning of the list to represent the new element being added to the stack. The pop() function removes the head node from the list to represent the top element being removed from the stack. The isEmpty() function checks if the head pointer is null to determine if the stack is empty. The isFull() function always returns false since linked list implementation of the stack does not have a fixed size. The stackTop() function returns the value of the head node to represent the top element without removing it. The display() function prints the contents of the list starting from the head node.

Question 03

In terms of time complexity, array and linked lists have different characteristics for different operations. Here's a comparison of the time complexity of some common operations on arrays and linked lists:

Accessing an element:

Array: O(1) Linked List: O(n) Inserting an element:

Array: Inserting at the end: O(1) amortized, O(n) worst-case (if the array needs to be resized) Inserting at the beginning or in the middle: O(n) Linked List: O(1) if inserting at the beginning, O(n) if inserting at the end or in the middle Deleting an element:

Array: Deleting at the end: O(1) Deleting at the beginning or in the middle: O(n) Linked List: O(1) if deleting at the beginning, O(n) if deleting at the end or in the middle Searching for an element:

Array: O(n) Linked List: O(n) From the above, we can see that arrays are generally more efficient than linked lists for accessing elements, while linked lists are more efficient for inserting and deleting elements in the middle or at the beginning of the list. However, arrays are more efficient for deleting elements at the end. Searching is O(n) for both data structures.
