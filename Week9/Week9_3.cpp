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

void count_leaf_nonLeaf(Node *root, int &leaf, int &nonLeaf) {
    if(root == nullptr) {
        return;
    }
    if(root->left == nullptr && root->right == nullptr) {
        leaf++;
    } else {
        nonLeaf++;
    }
    count_leaf_nonLeaf(root->left, leaf, nonLeaf);
    count_leaf_nonLeaf(root->right, leaf, nonLeaf);
}

int main() {
    Node *x1 = new Node('A');
    Node *x2 = new Node('B');
    Node *x3 = new Node('C');
    Node *x4 = new Node('D');
    Node *x5 = new Node('E');
    Node *x6 = new Node('F');
    Node *x7 = new Node('G');

    Node *head = x1;
    x1->left = x2;
    x1->right = x3;
    x2->left = x4;
    x2->right = x5;
    x3->left = x6;
    x3->right = x7;

    int leaf = 0, nonLeaf = 0;
    count_leaf_nonLeaf(head, leaf, nonLeaf);

    cout<<"Leaf Node: "<<leaf<<endl;
    cout<<"Non-Leaf Node : "<<nonLeaf<<endl;

    return 0;
}