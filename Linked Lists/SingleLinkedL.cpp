#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {
    int rollNo;
    Node* next;
};

// Insertion in a single linked list
void insertion(Node* &head) {
    int data;
    int choice=1 ; 
    while (choice==1) {
        Node* newNode = new Node();
        cout << "Enter your roll no : ";
        cin >> data;
        newNode->rollNo = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode; 
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Press 1 to continue: ";
        cin >> choice;
      
    }
}
//sorted insertion in a singly linked list
void sortedInsertion(Node* &head) {
    int choice = 1;  
    int data;

    while (choice==1) {
        Node* newNode = new Node();
        cout << "enter your data: ";
        cin >> data;
        newNode->rollNo = data;
        newNode->next = NULL;

        if (head == NULL || head->rollNo >= newNode->rollNo) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            Node* curr = NULL;
            while (temp != NULL && temp->rollNo < newNode->rollNo) {
                curr = temp;
                temp = temp->next;
            }
            curr->next = newNode;
            newNode->next = temp;
        }

        cout << "press 1 to continue : ";
        cin >> choice;
    }

    cout << endl;
}
//insert a node at head
void insertAtHead(Node* &head){
	int data;
	 Node* newNode = new Node();
        cout << "enter value that you want to insert at head : ";
        cin >>data;
        newNode->rollNo = data;
        newNode->next = head;
        head=newNode;		
}
//insert a node at tail
void insertAtTail(Node* &head){
	int data;
	 Node* newNode = new Node();
        cout << "enter value that you want to insert at tail : ";
        cin >>data;
        newNode->rollNo = data;
        newNode->next=NULL;
         Node* temp = head;
        while (temp->next != NULL) {
        temp = temp->next;
        }
            temp->next = newNode;
        }
       


//display function 
void display(Node* head){
	Node* temp=head;
	while(temp != NULL){
		cout<< temp->rollNo <<"->";
			temp=temp->next;
	}

	cout<<"NULL";
	
}

//update value of a node
void update(Node* &head){
	int data;
	int pos=1;
	cout<<"enter Roll no you want to update : ";
	cin>>data;
	cout<<"enter position : ";
	cin>>pos;
	if(pos==1){
		head->rollNo=data;
		return;
		}
	Node* newNode=new Node();
	newNode->rollNo=data;
	Node* temp=head;
	int curr_pos=1;
	while(curr_pos != pos){
		temp=temp->next;
		curr_pos++;
		
	}
	temp->rollNo=data;
	
	
	
}


// Function to search for a value in the linked list
void search(Node* head){
	int flag=0;
	int data;
	cout<<"enter value you want to search :";
	cin>>data;
	if(head==NULL){
		cout<<"list is empty";
	}
	Node* temp=head;
	while(temp!=NULL){
		if(data==temp->rollNo){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1){
		cout<<"value found";
		
}
	else{
		cout<<" value not found";
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

// Function to delete a node by roll number
void deleteByRollNo(Node* &head) {
	int rollNoToDelete;
	cout<<"enter rollno you want to delete :";
	cin>>rollNoToDelete;
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->rollNo == rollNoToDelete) {
        head = temp->next;
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
    delete temp;
    cout << "Node with roll number " << rollNoToDelete << " deleted." << endl;
}

//function to delete a linked list
void deleteList(Node* &head) {
  while (head != NULL) {
    Node* temp = head;
    head = head->next;
   	free(temp);
  }
 
  head = NULL;
}
   

int main(){
    Node* head=NULL;
    int variable;
    
    while(variable!=0){
    cout<<endl;
    cout<<"1 (insert a value in a linked list)"<<endl ;
    cout<<"2 (Sorted insertion  in a linked list)"<<endl ;
    cout<<"3 (insert a node at head)" <<endl ;
    cout<<"4 (insert a node at tail)"<<endl;
    cout<<"5 (update a value of node)"<<endl;
   	cout<<"6 (delete a node by roll no)"<<endl;
    cout<<"7 (print length of liked list )"<<endl;
    cout<<"8 (search a value in a linked list)"<<endl;
    cout<<"9 (delete a linked list)"<<endl;
    cout<<"10 (print a linked list)"<<endl;
   

    cout<<"enter:";
    cin>>variable;
    // cout<<endl;


    switch(variable){
    
    case 1 :
    insertion(head);
    cout<<"linked list is : ";
    display(head);
    cout<<endl;
    break;
    case 2 :
    sortedInsertion(head);
    cout<<"sorted linked list is ";
    display(head);
     cout<<endl;
    break;
    case 3: 
    insertAtHead(head);
    cout<<"After insert a node at head linked list is : " ;
    display(head);
     cout<<endl;
    break;
     case 4:
    insertAtTail(head);
     cout<<"After insert a node at tail linked list is : " ;
    display(head);
     cout<<endl;
    break;
     case 5:
    update(head);
     cout<<"After update a value  linked list is : " ;
    display(head);
     cout<<endl;
    break;
    case 6:
    deleteByRollNo(head);
     cout<<"After deletion  linked list is : " ;
    display(head);
    cout << endl;
    break;
	case 7:
    getLength(head);
    break;
    case 8:
    search(head);
    break;
    case 9:
    deleteList(head);
    cout << "Linked list deleted." << endl;
    head = NULL; 
    break;
    case 10:
    cout<<"linked list is : " ;
    display(head);
    cout<<endl;
    break;

    
    default:cout<<"invalid input ";
   
     
    }
    }
    
}


    
    
    
    
   

     

