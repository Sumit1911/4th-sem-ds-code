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

Node* insertIntoBST(Node *root, int d) {
    if(root == NULL) {
        root = new Node(d);
        return root;
    }
    if(d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void preorder(Node *root) {
    if(root == NULL) 
      return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root) {
    if(root == NULL) 
      return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root) {
    if(root == NULL) 
      return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    Node *root = NULL;
    cout<<"Enter keys to insert in BST : "<<endl;
    takeInput(root);

    cout<<"PreOrder : "; preorder(root);
    cout<<endl<<"InOrder : "; inorder(root);
    cout<<endl<<"PostOrder : "; postorder(root);

    return 0;
}