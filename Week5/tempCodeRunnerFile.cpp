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

Node* checkNodDec(Node* head) {
    Node* temp = head;
    int check = 1;

    while (temp->next != nullptr) {
        if (temp->data > temp->next->data) {
            check = 0;
            break;
        }
        temp = temp->next;
    }

    if (check) {
        cout << "This LL is Non-Decreasing" << endl;
    } else {
        cout << "This LL is not Non-Decreasing" << endl;
    }
}


int main() {
    Node* x5 = new Node(5);
    Node* x4 = new Node(4, x5);
    Node* x3 = new Node(3, x4);
    Node* x2 = new Node(2, x3);
    Node* x1 = new Node(1, x2);
    Node* head = x1;

    print(head);
    checkNodDec(head);

    return 0;
}