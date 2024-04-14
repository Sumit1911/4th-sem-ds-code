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

void print(Node* head){
    while(head!=nullptr) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

Node* moveToFront(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    prev = temp->next;
    // cout<<prev->next;
    prev->next = head;
    head = prev;
    temp->next = nullptr;
    // head = temp->next->next;

    return head;
}

int main() {
    Node* x4 = new Node(5);
    Node* x3 = new Node(3, x4);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);
    Node* head = x1;

    print(head);
    head = moveToFront(head);
    print(head);

    return 0;
}