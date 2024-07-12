#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data=val;
    left=NULL;
    right=NULL;
   }
};
//insertion in a bst
Node* insert(Node* root, int value) {
  if (root == nullptr) {
    return new Node(value);
  }

  if (value < root->data) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }

  return root;
}
//search in a bst
Node* search(Node* root, int value) {
  if (root == nullptr || root->data == value) {
    return root;
  }

  if (value < root->data) {
    return search(root->left, value);
  } else {
    return search(root->right, value);
  }
}
//get min node in a bst
Node* getMinNode(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  while (root->left != nullptr) {
    root = root->left;
  }
  return root;
}
//get max node in a bst
Node* getMaxNode(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  while (root->right != nullptr) {
    root = root->left;
  }
  return root;

   
}
//delete a node in a bst
Node* deleteNode(Node* root, int value) {
  if (root == nullptr) {
    return root;
  }

  if (value < root->data) {
    root->left = deleteNode(root->left, value);
  } else if (value > root->data) {
    root->right = deleteNode(root->right, value);
  } else {

    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    Node* temp = getMaxNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }

  return root;
}
//inorder traversal of a bst
void inorder(Node* root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}
//preorder traversal of a bst
void preorder(Node* root) {
  if (root != nullptr) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
//postorder traversal of a bst
void postorder(Node* root) {
  if (root != nullptr) {
  postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}


int main() {
  Node* root = nullptr;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
 
  cout<<"inorder traversal is : " ;
  inorder(root);
  cout<<endl;
   cout<<"preorder traversal is : " ;
  preorder(root);
  cout<<endl;
   cout<<"postorder traversal is : " ;
  postorder(root);
  cout<<endl;


  Node* found = search(root, 890);
  if (found != nullptr) {
    cout << "Found: " << found->data << endl;
  } else {
    cout << "Value not found!" << endl;
  }


  root = deleteNode(root, 30);

  cout << "Inorder traversal after deletion: ";
  inorder(root);
  cout << endl;

  return 0;
}


