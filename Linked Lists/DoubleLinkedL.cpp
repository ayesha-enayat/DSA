#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
  int rollNo;
  Node* next;
  Node* prev;
};

// Insertion in a doubly linked list
void insertion(Node* &head) {
  int data;
  int choice = 1;
  while (choice == 1) {
    Node* newNode = new Node();
    cout << "Enter your roll no: ";
    cin >> data;
    newNode->rollNo = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      Node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->prev = temp;
    }

    cout << "Press 1 to continue: ";
    cin >> choice;
  }
}

// Sorted insertion in a doubly linked list
void sortedInsertion(Node* &head) {
  int choice = 1;
  int data;

  while (choice == 1) {
    Node* newNode = new Node();
    cout << "enter your data: ";
    cin >> data;
    newNode->rollNo = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL || head->rollNo >= newNode->rollNo) {
      newNode->next = head;
      if (head != NULL) {
        head->prev = newNode;
      }
      head = newNode;
    } else {
      Node* temp = head;
      while (temp->next != NULL && temp->next->rollNo < newNode->rollNo) {
        temp = temp->next;
      }
      newNode->next = temp->next;
      if (temp->next != NULL) {
        temp->next->prev = newNode;
      }
      temp->next = newNode;
      newNode->prev = temp;
    }

    cout << "press 1 to continue : ";
    cin >> choice;
  }
}

// Display function
void display(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->rollNo << "->";
    temp = temp->next;
  }
  cout << "NULL";
}

// Update value of a node
void update(Node* &head) {
  int data;
  int pos = 1;
  cout << "enter Roll no you want to update: ";
  cin >> data;
  cout << "enter position: ";
  cin >> pos;

  int count = 1;
  Node* temp = head;
  while (temp != NULL && count < pos) {
    temp = temp->next;
    count++;
  }

  if (temp == NULL) {
    cout << "Invalid position" << endl;
    return;
  }

  temp->rollNo = data;
}

// Function to search for a value in the linked list
void search(Node* head) {
  int flag = 0;
  int data;
  cout << "enter value you want to search: ";
  cin >> data;

  Node* temp = head;
  while (temp != NULL) {
    if (temp->rollNo == data) {
      flag = 1;
      break;
    }
    temp = temp->next;
  }

  if (flag == 1)
    cout << "Element found\n";
  else
    cout << "Element not found\n";
}
// Function to delete a node by roll number
void deleteByRollNo(Node* &head) {
    int rollNoToDelete;
    cout << "Enter roll number you want to delete: ";
    cin >> rollNoToDelete;
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->rollNo == rollNoToDelete) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        cout << "Node with roll number " << rollNoToDelete << " deleted." << endl;
        return;
    }

    while (temp != NULL && temp->rollNo != rollNoToDelete) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node with roll number " << rollNoToDelete << " not found." << endl;
        return;
    }

    prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = prev;
    delete temp;
    cout << "Node with roll number " << rollNoToDelete << " deleted." << endl;
}

// Function to delete the entire linked list
void deleteList(Node* &head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
//get lenth of a list
int getLength(Node* head){
    int count=0;
    Node* temp;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<"length is " << " " << count;
    cout<<endl;
}
int main(){
    Node* head=NULL;
    int variable;
    
    while(variable!=0){
    cout<<endl;
    cout<<"1 (insert a value in a linked list)"<<endl ;
    cout<<"2 (Sorted insert a value in a linked list)"<<endl ;
    cout<<"3 (update a value of node)"<<endl;
   	cout<<"4 (delete a node by roll no)"<<endl;
    cout<<"5 (print length of linked list )"<<endl;
    cout<<"6 (search a value in a linked list)"<<endl;
    cout<<"7 (delete a linked list)"<<endl;
    cout<<"8 (print a linked list)"<<endl;
   

    cout<<"enter:";
    cin>>variable;
    // cout<<endl;


    switch(variable){
    
    case 1 :
    insertion(head);
    display(head);
    cout<<endl;
    break;
    case 2 :
    sortedInsertion(head);
    display(head);
     cout<<endl;
    break;
     case 3:
    update(head);
    display(head);
     cout<<endl;
    break;
    case 4:
    deleteByRollNo(head);
    display(head);
    cout << endl;
    break;
	case 5:
    getLength(head);
    break;
    case 6:
    search(head);
    break;
    case 7:
    deleteList(head);
    cout << "Linked list deleted." << endl;
    head = NULL; 
    break;
    case 8:
    display(head);
    break;

    
    default:cout<<"invalid input ";
   
     
    }
    }
    
}