#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from array representation
Node* buildTreeFromArray(int arr[], int size, int index) {
    // Base case: if index is out of bounds or the element is -1 (indicating a null node)
    if (index >= size || arr[index] == -1) {
        return nullptr;
    }

    // Create a new node with the value at the current index
    Node* root = new Node(arr[index]);

    // Recursively build left and right subtrees
    root->left = buildTreeFromArray(arr, size, 2 * index + 1);
    root->right = buildTreeFromArray(arr, size, 2 * index + 2);

    return root;
}

// Function to print inorder traversal of binary tree
void PreOrder(Node* root) {
    if (root == nullptr) 
      return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main() {
    // Example array representation of a binary tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Build binary tree from array
    Node* root = buildTreeFromArray(arr, size, 0);

    // Print inorder traversal to verify the tree
    PreOrder(root);
    cout << endl;

    return 0;
}
