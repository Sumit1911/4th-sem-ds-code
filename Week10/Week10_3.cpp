#include<iostream>
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

//insert value into BST
Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    if(data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

//delete value from BST
int minVal(Node* root) {
    Node* temp = root; // Change: Initialize temp to root
    if(root == NULL) {
        cout<<"empty"<<endl;
        return -1; // Change: Return a default value for an empty tree
    }
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}
int maxVal(Node* root) {
    Node* temp = root;
    if(root == NULL) {
        cout<<"Empty"<<endl;
        return -1;
    }
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

Node* deletingNode(Node* root, int val) {
    if(root == NULL) {
        return root;
    }
    if(root->data == val) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        if(root->left != NULL && root->right != NULL) {
            int replacementVal = minVal(root->right);
            root->data = replacementVal;
            root->right = deletingNode(root->right, replacementVal);
            return root;
        }
    }
    else if(root->data > val) {
        root->left = deletingNode(root->left, val);
        return root;
    } else {
        root->right = deletingNode(root->right, val);
        return root;
    }
}
//perform InOrder Traversal
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//search the key in BST
bool searchInBST(Node* root, int d) {
    if(root == NULL) 
      return false;
    if(root->data == d) 
      return true;
    if(d < root->data) {
        return searchInBST(root->left, d);
    } else {
        return searchInBST(root->right, d);
    }
}

//finding inorder predecessor
int inorderPredecessor(Node* root) {
    if(root == NULL) {
        return -1;
    }
    if(root->left != NULL && root->right != NULL) {
        int data = minVal(root->right);
        return data;
    }
}
//finding inorder successor
int inorderSuccessor(Node* root) {
    if(root == NULL) {
        return -1;
    }
    if(root->left != NULL && root->right != NULL) {
        int data = maxVal(root->left);
        return data;
    }
}

//kth smallest elem
int KthSmallest(Node* root, int& i, int k) {
    if(root == NULL) {
        return -1;
    }
    int left = KthSmallest(root->left, i, k);

    if(left != -1){
        return left;
    }
    i++;
    if(i == k) {
        return root->data;
    }

    return KthSmallest(root->right, i, k);
}
//count #node in range 
int countNodeInRange(Node* root, int s, int e) {
    if(root == NULL) {
        return 0; 
    }
    int count = 0;
    if(root->data >= s && root->data <= e) {
        count++;
    }
    if(root->data > s) {
        count += countNodeInRange(root->left, s, e);
    }

    if(root->data < e) {
        count += countNodeInRange(root->right, s, e);
    }

    return count;
}



int main() {
    Node* x1 = new Node(8);
    Node* x2 = new Node(3);
    Node* x3 = new Node(10);
    Node* x4 = new Node(1);
    Node* x5 = new Node(6);
    Node* x6 = new Node(14);
    Node* x7 = new Node(4);
    Node* x8 = new Node(7);
    Node* x9 = new Node(13);
    
    Node* root = x1;
    x1->left = x2;
    x1->right = x3;
    x2->left = x4;
    x2->right = x5;
    x3->right = x6;
    x5->left = x7;
    x5->right = x8;
    x6->left = x9;

    // insertIntoBST(root, 1);

    inorder(root);
    cout<<endl;

    root = deletingNode(root, 5);
    inorder(root);

    // Searching value in the BST
    if(searchInBST(root, 2)) {
        cout<<endl<<"2 exist in the BST"<<endl;
    } else {
        cout<<endl<<"2 doesn't exist in the BST"<<endl;
    }

    int predecessor = inorderPredecessor(root);
    cout<<"Inorder Predecessor : "<<predecessor<<endl;
    int successor = inorderSuccessor(root);
    cout<<"Inorder Successor : "<<successor<<endl;
    
    int i = 0;
    cout<<"Kth smallest elem : "<<KthSmallest(root, i , 2);
    cout<<endl<<"#node in given Range : "<<countNodeInRange(root, 1, 5);
    return 0;
}