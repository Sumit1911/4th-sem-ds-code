#include<iostream>
using namespace std;

class Node{
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

void f(Node* head) {
    if(head) {
        // cout<<head->data<<" "; 
        f(head->next);
        cout<<head->data<<" "; 
    }
}

Node* head;
void reverse(Node* prev, Node* cur) {
    if(cur) {
        reverse(cur, cur->next);
        cur->next = prev;
    } else {
        head = prev;
    }
}

int main() {
    Node* x4 = new Node(4);
    Node* x3 = new Node(3, x4);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);
    head = x1;

    f(head);
    cout<<endl;
    reverse(nullptr, head);

    f(head);

    return 0;
}