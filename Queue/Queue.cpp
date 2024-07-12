#include <iostream>
#include <cstdlib>


using namespace std;

struct stNode {
  int data; 
  stNode* next;
};

stNode* front = NULL; 
stNode* rear = NULL;  
bool isEmpty() {
  return front == NULL;
}

void enqueue(int data) {
  stNode* newNode = (stNode*)malloc(sizeof(stNode));
  newNode->data = data;
  newNode->next = NULL;

  if (isEmpty()) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}


int dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty\n";
    return -1;
  }

  stNode* temp = front;
  int data = temp->data;
  front = front->next;

  if (front == NULL) { 
    rear = NULL;
  }

  free(temp);
  return data;
}





void display() {
  if (isEmpty()) {
    cout << "Queue is empty\n";
    return;
  }

  stNode* temp = front;
  cout << "Queue elements: ";
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  int choice, data;

  do {
    cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter data to enqueue: ";
        cin >> data;
        enqueue(data);
        break;
      case 2:
        data = dequeue();
        if (data != -1) {
          cout << "Dequeued element: " << data << endl;
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
    dequeue();
  }

  return 0;
}
