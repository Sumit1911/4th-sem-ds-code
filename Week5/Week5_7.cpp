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
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int lengthOfLL(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

//Reverse LL
Node* reverseLL(Node* head) {
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void checkPalindrome(Node* head) {
    Node* rev = reverseLL(head);
    Node* temp = head;
    int palindrome = 1; // Assume palindrome initially

    while(temp != nullptr && rev != nullptr) {
        if(temp->data != rev->data) {
            palindrome = 0;
            break; 
        }
        temp = temp->next;
        rev = rev->next;
    }

    if(palindrome) {
        cout<<"This LL is Palindrome"<<endl;
    } else {
        cout<<"This LL is not Palindrome"<<endl;
    }
}


int main() {
    Node* x5 = new Node(1);
    Node* x4 = new Node(2, x5);
    Node* x3 = new Node(3, x4);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);

    Node* head = x1;

    print(head);
    checkPalindrome(head);

    return 0;
}