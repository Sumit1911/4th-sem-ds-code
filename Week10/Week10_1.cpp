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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    if(data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
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

void postorder(Node *root) {
    if(root == NULL) 
      return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    Node* root = NULL;
    cout<<"Enter keys to insert into BST : "<<endl;
    takeInput(root);
    cout<<"PreOrder : "; preorder(root);
    cout<<endl<<"PostOrder : "; postorder(root);

    return 0;
}