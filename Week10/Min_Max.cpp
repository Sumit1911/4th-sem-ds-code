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

int minVal(Node* root) {
    Node* temp = root; // Change: Initialize temp to root
    if(root == NULL) {
        cout<<"empty"<<endl;
        return -1; // Change: Return a default value for an empty tree
    }
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

Node* deletingNode(Node* root, int val) {
    if(root == NULL) {
        return root;
    }
    if(root->data == val) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        if(root->left != NULL && root->right != NULL) {
            int replacementVal = minVal(root->right);
            root->data = replacementVal;
            root->right = deletingNode(root->right, replacementVal);
            return root;
        }
    }
    else if(root->data > val) {
        root->left = deletingNode(root->left, val);
        return root;
    } else {
        root->right = deletingNode(root->right, val);
        return root;
    }
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main() {
    Node* x1 = new Node(8);
    Node* x2 = new Node(3);
    Node* x3 = new Node(10);
    Node* x4 = new Node(1);
    Node* x5 = new Node(6);
    Node* x6 = new Node(14);
    Node* x7 = new Node(4);
    Node* x8 = new Node(7);
    Node* x9 = new Node(13);
    
    Node* root = x1;
    x1->left = x2;
    x1->right = x3;
    x2->left = x4;
    x2->right = x5;
    x3->right = x6;
    x5->left = x7;
    x5->right = x8;
    x6->left = x9;

    inorder(root);
    cout<<endl;

    root = deletingNode(root, 5);
    inorder(root);

    return 0;
}
