#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *prev, *next;

    Node(Node* prev1, int data1, Node* next1) {
        prev = prev1;  //or prev->prev;
        data = data1;
        next = next1;
    }
    Node(int data1) {
        prev = nullptr;  //or prev->prev;
        data = data1;
        next = nullptr;
    }
};

void display(Node* head) {
    Node* temp = head;
    while(temp!=nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* insertBegin(Node* head) {
    Node* newNode = new Node(5);
    newNode->next = head;
    head = newNode;
    head->next->prev = head;

    return head;
}

Node* insertEnd(Node* head) {
    Node* newNode = new Node(5);
    Node* temp = head;
    while(temp->next!=nullptr) {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;

    return head;
}

Node* insertInter(Node* head, int pos) {
    Node* temp = head;
    Node* newNode = new Node(5);
    int count = 1;
    while(count != pos) {
        count++;
        temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

int main() {
    Node *x4, *x3, *x2, *x1;
    x4 = new Node(x3, 4, nullptr);
    x3 = new Node(x2, 3, x4);
    x2 = new Node(x1, 2, x3);
    x1 = new Node(nullptr, 1, x2);
    Node* head = x1;

    display(head);
    // head = insertBegin(head);
    // head = insertEnd(head);
    head = insertInter(head, 2);
    display(head);

    return 0;
}