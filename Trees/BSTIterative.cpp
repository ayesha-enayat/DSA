// #include<stdio.h>
// #include<stdlib.h>

// struct BST{

//     int data;
//     struct BST *rch;
//     struct BST *lch;
// };
// struct BST *root;

// int mmax, mmin;

// void insert(int val){

//     struct BST *temp = (struct BST*)malloc(sizeof(struct BST));
//     printf("%d\n", val);

//     temp->rch = NULL;
//     temp->lch = NULL;

//     temp->data = val;

//     if(root == NULL){
//         root = temp;
//         mmax = root->data;
//         mmin = root->data;
//     }

//     else{
//         struct BST *curr, *parent;
//         curr = root;

//         while(curr != NULL){
//             parent = curr;

//             if(val < mmin){
//                 mmin = val;
//             }
//             else if (val > mmax){
//                 mmax = val;
//             }

//             if(temp->data > parent->data){
//                 curr = curr->rch;
//                 printf("right ");
//             }
//             else{
//                 curr = curr->lch;
//                 printf("left ");
//             }
//         }

//         if(temp->data > parent->data){
//             parent->rch= temp;
//             printf("parent : %d\n\n", parent->data);
//         }
//         else{
//             parent->lch = temp;
//             printf("parent : %d\n\n", parent->data);
//         }

//     }

// }

// void searchin(){

//     int tos, flag = 0;

//     printf("Enter element to search: ");
//     scanf("%d", &tos);

//     struct BST *ptr = root;

//     while(ptr != NULL){

//         if(ptr->data == tos){
//             flag++;
//             break;
//         }
//         else{
//             if(tos > ptr->data){
//                 ptr = ptr->rch;
//             }
//             else{
//                 ptr = ptr->lch;
//             }
//         }
//     }

//     if(flag == 0){
//         printf("Value Not Found\n\n");
//     }
//     else{
//         printf("Value Found\n\n");
//     }
// }

// struct BST* minVal(struct BST* node)
// {
//     struct BST* curr = node;

//     while (curr && curr->lch != NULL)
//         curr = curr->lch;

//     return curr;
// }

// struct BST* delVal(struct BST* curr, int val){

//     if(curr == NULL){
//         printf("Empty Tree!");
//         return curr;
//     }

//     if(val < curr->data){
//         curr->lch = delVal(curr->lch, val);
//     }
//     else if(val > curr->data){
//         curr->rch = delVal(curr->rch, val);
//     }
//     else{
//         if(curr->lch == NULL){
//             struct BST *temp = curr->rch;
//             free(curr);
//             return temp;
//         }
//         else if(curr->rch == NULL){
//             struct BST *temp = curr->lch;
//             free(curr);
//             return temp;
//         }

//          struct BST *temp = minVal(curr->rch);

//         curr->data = temp->data;
//         curr->rch = delVal(root->rch, temp->data);
//     }

//    return curr;

// };

// void Inorder(struct BST* node)
// {
//     if (node == NULL){
//         return ;
//     }
//     Inorder(node->lch);
//     printf("%d ", node->data);
//     Inorder(node->rch);
// }

// void Postorder(struct BST* node)
// {
//     if (node == NULL){
//           return  ;
//     }

//     Postorder(node->lch);
//     Postorder(node->rch);
//     printf("%d ", node->data);
// }

// void Preorder(struct BST* node)
// {
//     if (node == NULL){
//           return  ;
//     }

//     printf("%d ", node->data);
//     Postorder(node->lch);
//     Postorder(node->rch);

// }

// int main(){

//     insert(23);
//     insert(15);
//     insert(16);
//     insert(5);
//     insert(90);
//     insert(54);
//     insert(100);

//     searchin();
//     searchin();

//     delVal(root, 16);

//     searchin();

//     printf("Max : %d\n\n", mmax);
//     printf("Min : %d\n", mmin);

//     printf("\nInorder : ");
//     Inorder(root);

//     printf("\n\nPostorder : ");
//     Postorder(root);

//     printf("\n\nPreorder : ");
//     Preorder(root);

// }
#include <iostream>
using namespace std;


struct BST{
    int data;
    BST *rch;
    BST *lch;
};

BST *root = nullptr;
int mmax, mmin;

void insert(int val){
    BST *temp = new BST;
    cout << val << std::endl;

    temp->rch = nullptr;
    temp->lch = nullptr;
    temp->data = val;

    if(root == nullptr){
        root = temp;
        mmax = root->data;
        mmin = root->data;
    } else {
        BST *curr, *parent;
        curr = root;

        while(curr != nullptr){
            parent = curr;

            if(val < mmin){
                mmin = val;
            } else if (val > mmax){
                mmax = val;
            }

            if(temp->data > parent->data){
                curr = curr->rch;
                std::cout << "right ";
            } else {
                curr = curr->lch;
                cout << "left ";
            }
        }

        if(temp->data > parent->data){
            parent->rch= temp;
            cout << "parent : " << parent->data << endl << endl;
        } else {
            parent->lch = temp;
            cout << "parent : " << parent->data << endl << endl;
        }
    }
}

void searchin(){
    int tos;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> tos;

    BST *ptr = root;

    while(ptr != nullptr){
        if(ptr->data == tos){
            found = true;
            break;
        } else {
            if(tos > ptr->data){
                ptr = ptr->rch;
            } else {
                ptr = ptr->lch;
            }
        }
    }

    if(!found){
        cout << "Value Not Found" << endl << endl;
    } else {
        cout << "Value Found" << endl << endl;
    }
}

BST* minVal(BST* node){
    BST* curr = node;

    while (curr && curr->lch != nullptr)
        curr = curr->lch;

    return curr;
}

BST* delVal(BST* curr, int val){
    if(curr == nullptr){
       cout << "Empty Tree!";
        return curr;
    }

    if(val < curr->data){
        curr->lch = delVal(curr->lch, val);
    } else if(val > curr->data){
        curr->rch = delVal(curr->rch, val);
    } else {
        if(curr->lch == nullptr){
            BST *temp = curr->rch;
            delete curr;
            return temp;
        } else if(curr->rch == nullptr){
            BST *temp = curr->lch;
            delete curr;
            return temp;
        }

        BST *temp = minVal(curr->rch);
        curr->data = temp->data;
        curr->rch = delVal(root->rch, temp->data);
    }
    return curr;
}

void Inorder(BST* node){
    if (node == nullptr){
        return ;
    }
    Inorder(node->lch);
    cout << node->data << " ";
    Inorder(node->rch);
}

void Postorder(BST* node){
    if (node == nullptr){
        return ;
    }

    Postorder(node->lch);
    Postorder(node->rch);
   cout << node->data << " ";
}

void Preorder(BST* node){
    if (node == nullptr){
        return ;
    }

    cout << node->data << " ";
    Preorder(node->lch);
    Preorder(node->rch);
}

int main(){
    insert(23);
    insert(15);
    insert(16);
    insert(5);
    insert(90);
    insert(54);
    insert(100);
    delVal(root, 16);
    cout<<"After deletion inorder traversal is :";
  
    Inorder(root);

    searchin();
    searchin();

  


    searchin();

    cout << "Max : " << mmax << std::endl << std::endl;
    cout << "Min : " << mmin << std::endl;

    cout << "\nInorder : ";
    Inorder(root);

    cout << "\n\nPostorder : ";
    Postorder(root);

    cout << "\n\nPreorder : ";
    Preorder(root);

    

    return 0;
}
