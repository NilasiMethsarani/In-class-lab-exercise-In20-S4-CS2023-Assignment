#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
    private:
        int arr[MAX_SIZE];
        int top;

    public:
        // Constructor to initialize the stack
        Stack() {
            top = -1;
        }

        // Function to push an element onto the stack
        void push(int value) {
            if (top == MAX_SIZE - 1) {  // Check if the stack is full
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                arr[top] = value;
            }
        }

        // Function to pop an element from the stack
        void pop() {
            if (top == -1) {  // Check if the stack is empty
                cout << "Stack Underflow" << endl;
            } else {
                cout << "Popped element: " << arr[top] << endl;
                top--;
            }
        }

        // Function to check if the stack is empty
        bool isEmpty() {
            return (top == -1);
        }

        // Function to check if the stack is full
        bool isFull() {
            return (top == MAX_SIZE - 1);
        }

        // Function to return the element at the top of the stack
        int stackTop() {
            return arr[top];
        }

        // Function to display all the elements in the stack
        void display() {
            if (top == -1) {  // Check if the stack is empty
                cout << "Stack is empty" << endl;
            } else {
                cout << "Elements in the stack are: ";
                for (int i = top; i >= 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    s.display();  // Output: Elements in the stack are: 20 15 10 5

    s.pop();//Popped element: 20
    s.pop();//Popped element: 15

    s.display();  // Output: Elements in the stack are: 10 5

    cout << "Top element is " << s.stackTop() << endl;  // Output: Top element is 10

    return 0;
}
