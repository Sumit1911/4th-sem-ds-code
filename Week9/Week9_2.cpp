#include<iostream>
using namespace std;

class Node {
    public:
    Node *left;
    char data;
    Node *right;

    Node(char data1) {
        left = nullptr;
        data = data1;
        right = nullptr;
    }
};

int height(Node *root) {
    if(root == nullptr) {
        return 0;
    }
    return (1 + max(height(root->left), height(root->right)));
}

int main() {
    Node *x1 = new Node('A');
    Node *x2 = new Node('B');
    Node *x3 = new Node('C');

    Node *head;
    head = x1;
    x1->left = x2;
    x1->right= x3;

    cout<<"height of tree : "<<height(head);

    return 0;
}