#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void print(Node* head) {
    while(head != nullptr) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int lengthLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int middleNode(Node* head) {
    int mid = lengthLL(head)/2+1;
    Node* temp = head;
    while(--mid) {
        temp = temp->next;
    }
    return temp->data;
}

int main() {
    Node* x3 = new Node(3);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);
    Node* head = x1;
    // Node* x4 = new Node(4);
    // Node* x3 = new Node(3, x4);
    // Node* x2 = new Node(2, x3);
    // Node* x1 = new Node(1, x2);
    // Node* head = x1;

    print(head);
    cout<<"The middle node is : "<<middleNode(head);

    return 0;
}