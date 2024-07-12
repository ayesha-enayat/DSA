#include<iostream>
using namespace std;


const int  N = 5;
int stack[5];
int top=-1;

//push function
void push(){
    int x ;
     if(top == N-1){
        cout <<" stack is overflow";
        cout<< endl;
    }
    else{
        cout<<"enter data : ";
        cin>>x;
        top++;
        stack[top]=x; 
    }
    
    }

//pop function
void pop(){
    int item;
    if(top == -1){
        cout<<" stack is underflow";
    }
    else{
        item=stack[top];
        top--;
        cout<< "popping value : " << item;
    }
}
// peek function
void peek(){
    if(top == -1){
        cout<<"underflow";
    }
    else{
        cout<< "top of the stack is : " << stack[top];
    }
}

//display function
void display(){
    int i;
    for(i=top ;i>=0 ;i--)
    {
        cout<< stack[i] << " ";
    }
}
int main(){
    int variable;
    
    while(variable!=0){
    cout<<endl;
    cout<<"1 (push a value)"<<endl ;
    cout<<"2 (pop a value)"<<endl ;
    cout<<"3 (get value of top)" <<endl ;
    cout<<"4 (display )"<<endl;
    cout<<"enter your choice:";
    cin>>variable;
     cout<<endl;


    switch(variable){
    
    case 1 :
    push();
    cout<<endl;
    break;
    case 2 :
    pop();
     cout<<endl;
    break;
    case 3: 
    peek();
     cout<<endl;
    break;
     case 4:
     cout<<"stack : " ;
    display();
     cout<<endl;
    break;

    default:cout<<"invalid input ";
    break;
   
     
    }
    }
}