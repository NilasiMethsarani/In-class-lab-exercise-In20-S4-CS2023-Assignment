#include <iostream>
using namespace std;

class Node {
public:
    int data;           // data stored in the node
    Node* next;         // pointer to the next node
};

class Stack {
private:
    Node* head;         // pointer to the head of the linked list
public:
    Stack() { head = NULL; }
    void push(int value);       // inserts a new element into the stack
    int pop();                  // removes the top element from the stack and returns it
    bool isEmpty();             // checks if the stack is empty
    bool isFull();              // checks if the stack is full
    int stackTop();             // returns the top element without removing it
    void display();             // prints all elements of the stack
};

void Stack::push(int value) {
    Node* newNode = new Node;   // create a new node
    if (newNode == NULL) {      // check if there's Stack Overflow
        cout << "Stack Overflow" << endl;
    }
    else {
        newNode->data = value;  // set the data of the new node
        newNode->next = head;   // point the new node to the previous head
        head = newNode;         // set the new node as the new head
    }
}

int Stack::pop() {
    int value = -1;             // initialize the return value
    if (head == NULL) {         // check if there's Stack Underflow
        cout << "Stack Underflow" << endl;
    }
    else {
        value = head->data;     // save the data of the head node
        Node* temp = head;      // save the address of the head node
        head = head->next;      // point to the next node
        delete temp;            // delete the previous head node
    }
    return value;
}

bool Stack::isEmpty() {
    return head == NULL;        // return true if the stack is empty, false otherwise
}

bool Stack::isFull() {
    Node* newNode = new Node;   // try to create a new node
    bool full = newNode == NULL;// if the new node is NULL, there's no memory available
    delete newNode;             // delete the new node
    return full;
}

int Stack::stackTop() {
    if (head == NULL) {         // check if the stack is empty
        return -1;
    }
    return head->data;          // return the data of the head node
}

void Stack::display() {
    Node* current = head;       // start from the head node
    while (current != NULL) {   // go through each node until we reach the end
        cout << current->data << " "; // print the data of the current node
        current = current->next;      // move to the next node
    }
    cout << endl;
}

int main() {
    Stack stack;

    // push elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    cout << "Elements in the stack are: ";
    stack.display();

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Elements in the stack are: ";
    stack.display();

    cout << "Top element is " << stack.stackTop() << endl;

    return 0;
}
