#include<iostream>
using namespace std;
#include<cstring>

struct BTNode{

    char data;
     BTNode *rch;
     BTNode *lch;

};
 BTNode *root;
 BTNode *stack[100];
int top = 0;

 BTNode* createNode(char var){

    BTNode *temp  = ( BTNode*)malloc(sizeof( BTNode));

    temp->data = var;
    temp->rch = NULL;
    temp->lch = NULL;

    return temp;
}

void push( BTNode *po){

    stack[top] = po;
    top++;

}

 BTNode* pop(){

    struct BTNode *pos = stack[top-1];
    top--;
    return pos;
}

void Inorder( BTNode *r){
    if(r!= NULL){
        Inorder(r->lch);
      cout<< r->data;
        Inorder(r->rch);
    }
}

void Postorder(BTNode* r)
{
    if (r != NULL){
        Postorder(r->lch);
        Postorder(r->rch);
    cout<<r->data;
    }
}

void Preorder(BTNode* r)
{
    if (r != NULL){
        cout<<r->data;
        Postorder(r->lch);
        Postorder(r->rch);
    }
}

int main(){

    char exp[100];
    printf("Enter Postfix Expression : ");
    gets(exp);

    struct BTNode *ptr;

    for(int i = 0; i < strlen(exp); i++){
        if(exp[i] >= 65 && exp[i] <= 92){
            ptr = createNode(exp[i]);
            push(ptr);
            
        }
        else if(exp[i] >= 97 && exp[i] <= 122){
            ptr = createNode(exp[i]);
            push(ptr);
         
        }
        else if(exp[i] >= 48 && exp[i] <= 57){
            ptr = createNode(exp[i]);
            push(ptr);
      
        }
        else{
            struct BTNode *par = createNode(exp[i]);
            
            struct BTNode *right = pop();
            
            struct BTNode *left = pop();
            
            par->rch = right;
            par->lch = left;

            push(par);

        }
    }

    struct BTNode *root = stack[top-1];

    Inorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    Preorder(root);
}