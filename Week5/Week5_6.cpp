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

int lengthLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void print(Node* head) {
    while(head != nullptr) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

void intersect(Node* head1, Node* head2, int pos) {
    Node* temp1 = head1;
    while(--pos) {
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while(temp2->next!=nullptr) {
        temp2 = temp2->next;
    } 
    temp2->next = temp1;
}

int intersectionLL(Node* head1, Node* head2) {
    int l1 = lengthLL(head1);
    int l2 = lengthLL(head2);

    int dis = 0;
    Node* temp1;
    Node* temp2;
    if(l1>l2) {
        dis = l1-l2;
        temp1 = head1;
        temp2 = head2;
    } else {
        dis = l2-l1;
        temp1 = head2;
        temp2 = head1;
    }

    while(dis--) {
        temp1 = temp1->next;
        if(temp1 == nullptr) {
            return -1;
        }
    }
    while(temp1 != nullptr && temp2 != nullptr) {
        if(temp1->data == temp2->data) {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

int main() {
    Node* x5 = new Node(5);
    Node* x4 = new Node(4, x5);
    Node* x3 = new Node(3, x4);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);
    Node* head1 = x1;
      
    Node* y3 = new Node(11);
    Node* y2 = new Node(10, y3);
    Node* y1 = new Node(9, y2);
    Node* head2 = y1;
    
    intersect(head1, head2, 3);
    print(head1);
    print(head2);
    cout<<intersectionLL(head1, head2);

    return 0;
}