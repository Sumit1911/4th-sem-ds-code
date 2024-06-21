#include <iostream>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if the tree is balanced and return the height of the tree.
pair<bool, int> checkAVL(node* root) {
    if (!root) {
        return {true, 0};  // An empty tree is balanced and has height 0.
    }

    // Recursively check the left subtree.
    auto left = checkAVL(root->left);
    if (!left.first) {
        return {false, 0};  // If the left subtree is not balanced, return false.
    }

    // Recursively check the right subtree.
    auto right = checkAVL(root->right);
    if (!right.first) {
        return {false, 0};  // If the right subtree is not balanced, return false.
    }

    // Check if the current node is balanced.
    if (abs(left.second - right.second) > 1) {
        return {false, 0};  // If the height difference is more than 1, return false.
    }

    // Calculate the height of the current subtree.
    int height = (left.second > right.second ? left.second : right.second) + 1;

    // Return true and the height of the current subtree.
    return {true, height};
}

// Main function to check if the tree is an AVL tree.
bool isAVLTree(node* root) {
    return checkAVL(root).first;
}

int main() {
    // Example usage:
    // Constructing a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    // Check if the tree is an AVL tree.
    if (isAVLTree(root)) {
        cout << "The tree is an AVL tree." << endl;
    } else {
        cout << "The tree is not an AVL tree." << endl;
    }

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
