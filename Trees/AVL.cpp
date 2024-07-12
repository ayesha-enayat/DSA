#include<iostream>
using namespace std;


struct AVL{

    int data;
    struct AVL *rch;
    struct AVL *lch;
    int height;

};
//struct AVL* root;

int maxn(int h1, int h2){

    int maxnode;

    if(h1 > h2){
        maxnode = h1;
    }
    else{
        maxnode = h2;
    }

    return maxnode;
};

int height( AVL *node){

    if(node==NULL){
        return 0;
    }
    return node->height;
}

 AVL* SR(AVL *curr){
         AVL *t1 = curr->lch;
         AVL *t2 = t1->rch;

        t1->rch = curr;
        curr->lch = t2;

        curr->height = maxn(height(curr->lch), height(curr->rch)) + 1;
        t1->height = maxn(height(t1->lch), height(t1->rch)) + 1;

        return t1;
}

AVL* SL( AVL* curr){

         AVL *t1 = curr->rch;
         AVL *t2 = t1->lch;

        t1->lch = curr;
        curr->rch = t2;

        curr->height = maxn(height(curr->lch), height(curr->rch)) + 1;
        t1->height = maxn(height(t1->lch), height(t1->rch)) + 1;

        return t1;
}

 AVL* insert( AVL* node, int value){

     AVL* temp = ( AVL*)malloc(sizeof( AVL));

    if(node == NULL){
        temp->data = value;
        temp->rch = NULL;
        temp->lch = NULL;
        temp->height = 1;

        return(temp);
    }

    else{
        if(value < node->data){
            node->lch = insert(node->lch, value);
            if(height(node->lch)- height(node->rch) > 1){
                    if(value < node->lch->data){
                        node = SR(node);
                    }
                    else{
                        node->lch = SL(node->lch);
                        node = SR(node);
                    }
            }
        }
        else{
            node->rch = insert(node->rch, value);
            if(height(node->lch)- height(node->rch) < -1){
                if(value > node->lch->data){
                        node = SL(node);
                    }
                    else{
                        node->rch = SR(node->lch);
                        node = SL(node);
                    }
            }
        }

        node->height = maxn(height(node->lch), height(node->rch)) + 1;

        return node;
    }
}

void Preorder(struct AVL* node){
    if(node == NULL){
        return;
    }
    cout<< node->data << " ";
    Preorder(node->lch);
    Preorder(node->rch);
}
void Inorder(struct AVL* node){
    if(node == NULL){
        return;
    }
    
    Preorder(node->lch);
    cout<< node->data << " ";
    Preorder(node->rch);
}
void Postorder(struct AVL* node){
    if(node == NULL){
        return;
    }
    
    Preorder(node->lch);
    Preorder(node->rch);
    cout<< node->data << " ";
}

int main()
{
    struct AVL *root = NULL;

    root = insert(root, 12);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 5);
    cout<<"preorder traversal is : " ;
    Preorder(root);
    cout<<endl;
    cout<<"inorder traversal is :  " ;
    Inorder(root);
    cout<<endl;
    cout<<"postorder traversal is : " ;
    Postorder(root);
    cout<<endl;

   
}