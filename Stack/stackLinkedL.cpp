#include <iostream>
#include<cstdlib>


using namespace std;

struct stNode {
    int rollno;
    stNode* next;
};


stNode* top = NULL;


void push() {
    int rollno;

    cout << "Enter roll number: ";
    cin >> rollno; 

    stNode* newNode = (stNode*)malloc(sizeof(stNode));
    newNode->rollno = rollno;
    newNode->next = top;
    top = newNode;
}


int pop() {
    stNode* temp = top;
    if (temp == NULL) {
        cout << "Stack is empty\n";
        return -1; 
    }

    int rollno = top->rollno;
    top = top->next;
    free(temp);
    return rollno;
}

bool isEmpty() {
    return top == NULL;
}


void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }

    stNode* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->rollno << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                int popped;
                 popped = pop();
                if (popped != -1) {
                    cout << "Popped element: " << popped << endl;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    while (!isEmpty()) {
        pop();
    }

    return 0;
}