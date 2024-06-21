#include <iostream>
#include <queue>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from array representation
TreeNode* buildTreeFromArray(int arr[], int size, int index) {
    // Base case: if index is out of bounds or the element is -1 (indicating a null node)
    if (index >= size || arr[index] == -1) {
        return nullptr;
    }

    // Create a new node with the value at the current index
    TreeNode* root = new TreeNode(arr[index]);

    // Recursively build left and right subtrees
    root->left = buildTreeFromArray(arr, size, 2 * index + 1);
    root->right = buildTreeFromArray(arr, size, 2 * index + 2);

    return root;
}

// Function to find the minimum and maximum values in a binary tree represented by an array
pair<int, int> findMinMax(TreeNode* root) {
    if (root == nullptr) {
        return make_pair(INT_MAX, INT_MIN);
    }

    queue<TreeNode*> q;
    q.push(root);
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            TreeNode* node = q.front();
            q.pop();
            min_val = min(min_val, node->val);
            max_val = max(max_val, node->val);

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    return make_pair(min_val, max_val);
}

int main() {
    // Example array representation of a binary tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Build binary tree from array
    TreeNode* root = buildTreeFromArray(arr, size, 0);

    // Find minimum and maximum values
    pair<int, int> min_max = findMinMax(root);

    cout << "Minimum value: " << min_max.first << endl;
    cout << "Maximum value: " << min_max.second << endl;

    return 0;
}
