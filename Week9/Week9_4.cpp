#include<iostream>
using namespace std;

class Node {
    public:
    Node *left;
    int data;
    Node *right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}

bool heightBalanced(Node *root) {
    if(root == NULL) {
        return true;
    }
    bool left = heightBalanced(root->left);
    bool right = heightBalanced(root->right);

    bool diff = abs(height(root->left)-height(root->right)) <= 1;

    if(left && right && diff) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    Node *root = n1;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    if(heightBalanced(root)) {
        cout<<"Height Balanced!"<<endl;
    } else {
        cout<<"Height Unbalanced!"<<endl;
    }

    return 0;
}