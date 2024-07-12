#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {
    int rollNo;
    Node* next;
};

// Insertion in a circular linked list
void insertion(Node* &head) {
    int data;
    int choice=1 ; 
    while (choice==1) {
        Node* newNode = new Node();
        cout << "Enter your roll no : ";
        cin >> data;
        newNode->rollNo = data;
        newNode->next = head; 

        if (head == NULL) {
            head = newNode; 
            newNode->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Press 1 to continue: ";
        cin >> choice;
    }
}

// Deletion from a circular linked list
void deleteByRollNo(Node* &head, int rollNoToDelete) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    do {
        if (temp->rollNo == rollNoToDelete) {
            if (temp == head) {
                head = head->next;
            }
            prev->next = temp->next;
            delete temp;
            cout << "Node with roll number " << rollNoToDelete << " deleted." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Node with roll number " << rollNoToDelete << " not found." << endl;
}

// Function to delete the entire circular linked list
void deleteList(Node* &head) {
    if (head == NULL) {
        cout << "List is already empty." << endl;
        return;
    }

    Node* current = head;
    Node* next;

    do {
        next = current->next;
        delete current;
        current = next;
    } while (current != head);

    head = NULL;
    cout << "Circular linked list deleted." << endl;
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->rollNo << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << " (Back to head)" << endl;
}

int main() {
    Node* head = NULL;
    int variable;

    do {
        cout << endl;
        cout << "1 (insert a value in a circular linked list)" << endl;
        cout << "2 (delete a node by roll no)" << endl;
        cout << "3 (delete the entire circular linked list)" << endl;
        cout << "4 (print the circular linked list)" << endl;
        cout << "0 (exit)" << endl;

        cout << "Enter: ";
        cin >> variable;

        switch(variable) {
            case 1:
                insertion(head);
                break;
            case 2:
                int rollNoToDelete;
                cout << "Enter roll no to delete: ";
                cin >> rollNoToDelete;
                deleteByRollNo(head, rollNoToDelete);
                break;
            case 3:
                deleteList(head);
                break;
            case 4:
                display(head);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
    } while (variable != 0);

    return 0;
}
