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

void display(Node* head) {
    Node* temp = head;
    while(temp) {  //while(temp!=nullptr)
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node *x4, *x3, *x2, *x1;
    x4 = new Node(4);
    x3 = new Node(3, x4);
    x2 = new Node(2, x3);
    x1 = new Node(1, x2);
    Node* head = x1;

    display(head);

    return 0;
}