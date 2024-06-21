#include <iostream>
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

void printBST(Node* root) {
    if (root == NULL)
        return;
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

Node* trimBST(Node* root, int L, int R) {
    if (root == NULL)
        return NULL;

    // If current node is less than L, trim right subtree
    if (root->data < L)
        return trimBST(root->right, L, R);
    
    // If current node is greater than R, trim left subtree
    if (root->data > R)
        return trimBST(root->left, L, R);

    // Recursively trim left and right subtrees
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    return root;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    cout << "BST before trimming: ";
    printBST(root);
    cout << endl;

    int L = 5, R = 15;
    root = trimBST(root, L, R);

    cout << "BST after trimming to range [" << L << ", " << R << "]: ";
    printBST(root);
    cout << endl;

    return 0;
}
