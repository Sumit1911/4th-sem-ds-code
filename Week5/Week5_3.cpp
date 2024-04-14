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

Node* mergeTwoLL(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* dNode = new Node(-1, NULL);
    Node* temp = dNode;

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data < temp2->data) {
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
    }
    if(temp1) {
        temp->next =temp1;
    } else {
        temp->next = temp2;
    }

    return dNode->next;

}

void print(Node* head) {
    while(head != nullptr) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}


int main() {
    Node* x3 = new Node(3);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);
    Node* head1 = x1;

    Node* y3 = new Node(6);
    Node* y2 = new Node(5, y3);
    Node* y1 = new Node(4, y2);
    Node* head2 = y1;

    print(head1);
    print(head2);

    head1 = mergeTwoLL(head1, head2);
    print(head1);

    return 0;
}