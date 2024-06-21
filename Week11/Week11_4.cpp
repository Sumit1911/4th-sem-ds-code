#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    int height;
    node(int x) : val(x), left(NULL), right(NULL), height(1) {}
};

int height(node* n) {
    return n ? n->height : 0;
}

int getBalance(node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;

    return x;
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;

    return y;
}

node* insert(node* root, int key) {
    if (!root) {
        return new node(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    } else {
        return root;
    }

    root->height = (height(root->left) > height(root->right) ? height(root->left) : height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->val) {
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->val) {
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node* sortedArrayToAVL(vector<int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    node* root = new node(arr[mid]);

    root->left = sortedArrayToAVL(arr, start, mid - 1);
    root->right = sortedArrayToAVL(arr, mid + 1, end);

    root->height = (height(root->left) > height(root->right) ? height(root->left) : height(root->right)) + 1;

    return root;
}

void inOrder(node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    node* root = sortedArrayToAVL(arr, 0, arr.size() - 1);

    cout << "In-order traversal of the constructed AVL tree is: ";
    inOrder(root);
    cout << endl;

    return 0;
}
