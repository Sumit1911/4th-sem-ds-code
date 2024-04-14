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
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count; 
}

Node* removeNthFromEnd(Node* head, int n) {
    int s = lengthLL(head) - n + 1;
    if(s == lengthLL(head)) {
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete temp->next;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    int count = 0;
    while(temp->next != NULL) {
        count++;
        if(count == s) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* x4 = new Node(4);
    Node* x3 = new Node(3, x4);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);
    Node* head = x1;

    print(head);
    
    head = removeNthFromEnd(head, 1);
    print(head);

    return 0;
}