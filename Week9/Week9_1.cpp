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

void preorder(Node *head) {
    if(head != nullptr) {
        cout<<head->data;
        preorder(head->left);
        preorder(head->right);
    }
}
void inorder(Node *head) {
    if(head != nullptr) {
        preorder(head->left);
        cout<<head->data;
        preorder(head->right);
    }
}
void postorder(Node *root) {
    if(root != nullptr) {
        preorder(root->left);
        preorder(root->right);
        cout<<root->data;
    }
}

int main() {
    Node *x1 = new Node('A');
    Node *x2 = new Node('B');
    Node *x3 = new Node('C');

    Node *head;
    head = x1;
    x1->left = x2;
    x1->right= x3;

    cout<<"PreOrder: ";preorder(head);
    cout<<endl<<"InOrder: ";inorder(head);
    cout<<endl<<"PostOrder: ";postorder(head);

    return 0;
}