#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class StackArray {
private:
    int* stack;
    int size;
    int top;

public:
    StackArray(int capacity) {
        size = capacity;
        stack = new int[size];
        top = -1;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack overflow\n";
            return;
        }

        top++;
        stack[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return;
        }

        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (top == NULL) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack underflow\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    const int size = 10;
    StackArray stackArray(size);
    StackLinkedList stackLinkedList;

    
    // Push random values to both stacks
    // Push random values to both stacks
    srand(time(NULL));
    auto startArrayPush = chrono::high_resolution_clock::now();
    stackArray.push(8);
    stackArray.push(10);
    stackArray.push(5);
    stackArray.push(11);
    stackArray.push(15);
    stackArray.push(23);
    stackArray.push(6);
    stackArray.push(18);
    stackArray.push(20);
    stackArray.push(17);
    auto stopArrayPush = chrono::high_resolution_clock::now();
    auto durationArrayPush = chrono::duration_cast<chrono::nanoseconds>(stopArrayPush - startArrayPush);
    cout << "Time taken to push values to array implementation: " << durationArrayPush.count() << " nanoseconds" << endl;


    auto startLinkedList = chrono::high_resolution_clock::now();
    stackLinkedList.push(8);
    stackLinkedList.push(10);
    stackLinkedList.push(5);
    stackLinkedList.push(11);
    stackLinkedList.push(15);
    stackLinkedList.push(23);
    stackLinkedList.push(6);
    stackLinkedList.push(18);
    stackLinkedList.push(20);
    stackLinkedList.push(17);
    auto stopLinkedList = chrono::high_resolution_clock::now();

    
   
    auto durationLinkedList = chrono::duration_cast<chrono::microseconds>(stopLinkedList - startLinkedList);
     cout << "Time taken to push values to LinkList implementation: " << durationLinkedList.count() <<  " microseconds" << endl;
    

    // Display both stacks
    auto startArrayDisplay = chrono::high_resolution_clock::now(); // Start time for array display
    stackArray.display();
    auto stopArrayDisplay = chrono::high_resolution_clock::now(); // Stop time for array display
    auto durationArrayDisplay = chrono::duration_cast<std::chrono::microseconds>(stopArrayDisplay - startArrayDisplay);
    cout << "Time taken by array display operation: " << durationArrayDisplay.count() << " microseconds" << endl;

    auto startLinkedListDisplay = chrono::high_resolution_clock::now(); // Start time for linked list display
    stackLinkedList.display();
    auto stopLinkedListDisplay = chrono::high_resolution_clock::now(); // Stop time for linked list display
    auto durationLinkedListDisplay = chrono::duration_cast<std::chrono::microseconds>(stopLinkedListDisplay - startLinkedListDisplay);
    cout << "Time taken by linked list display operation: " << durationLinkedListDisplay.count() << " microseconds" << endl;

   
}
