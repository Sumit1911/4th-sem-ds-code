#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isBST(Node* root, Node* min, Node* max) {
  if(root == NULL)
    return true;
  if(min != NULL && root->data <= min->data)
    return false;
  if(max != NULL && root->data >= max->data)
    return false;
  bool left = isBST(root->left, min, root);
  bool right = isBST(root->right, root, max);
  return left && right;
}

int main() {
    Node* x1 = new Node(5);
    Node* x2 = new Node(2);
    Node* x3 = new Node(8);
    
    Node* root = x1;
    x1->left = x2;
    x1->right = x3;

    if(isBST(root, NULL, NULL)) {
        cout<<"Valid BST"<<endl;
    } else {
        cout<<"In-Valid BST"<<endl;
    }
    return 0;
}