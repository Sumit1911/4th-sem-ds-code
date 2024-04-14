#include <iostream>
using namespace std;

// Definition for a singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Function to check if the linked list is in non-decreasing order
bool isNonDecreasing(Node* head) {
    Node* curr = head;

    // Traverse the linked list
    while (curr != nullptr && curr->next != nullptr) {
        // If current node's data is greater than the next node's data, return false
        if (curr->data > curr->next->data)
            return false;
        curr = curr->next;
    }

    // If traversal completes without encountering a decreasing order, return true
    return true;
}

// Function to insert a new node at the beginning of a linked list
void push(Node* &head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the linked list
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);

    cout << "Linked list: ";
    printList(head);

    // Check if the linked list is in non-decreasing order
    if (isNonDecreasing(head))
        cout << "The linked list is in non-decreasing order." << endl;
    else
        cout << "The linked list is not in non-decreasing order." << endl;

    return 0;
}
