#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
void printPathsRecursive(Node* root, vector<int>& path) {
    if (!root) return;
    path.push_back(root->data);
    if (!root->left && !root->right) {
        cout << "Path: ";
        for (int i = 0; i < path.size() - 1; ++i) {
            cout << path[i] << " -> ";
        }
        cout << path[path.size() - 1] << endl;
    }
    printPathsRecursive(root->left, path);
    printPathsRecursive(root->right, path);
    path.pop_back();
}
void printPaths(Node* root) {
    vector<int> path;
    printPathsRecursive(root, path);
}

int main() {
    vector<int> arrayRepresentation = {1, 2, 3, 4, 5, -1, 7}; 
    Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    Node* n4=new Node(4);
    Node* n5=new Node(5);
    Node* n6=new Node(6);
    Node* n7=new Node(7);
    Node* n8=new Node(8);
    Node* n9=new Node(9);
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n7;
    n4->left=n8;
    n5->left = n9;
    cout << "Printing all paths from the root to the leaves:\n";
    printPaths(n1);
    return 0;
}
