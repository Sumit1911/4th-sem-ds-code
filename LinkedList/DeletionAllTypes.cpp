#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Multi Constructor
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;  // or mover = mover->next
    }
    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//deleting first node of LL
Node* removesHead(Node* head) {
    if(head == NULL)
    return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

//deleting last node of LL
Node* removesTail(Node* head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

//deleting kth node of LL
Node* removeK(Node* head, int k) {
    if(head == NULL) 
    return head;

    if(k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count = 0; 
    Node* temp = head; 
    Node* prev = NULL;
    while (temp!=NULL) {
        count++;
        if(count == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head; 
}
//deleting value of LL
Node* removeEl(Node* head, int el) {
    if(head == NULL) 
    return head;

    if(head->data == el) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head; 
    Node* prev = NULL;
    while (temp!=NULL) {
        if(temp->data == el) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head; 
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    print(head);

    // head = removesHead(head);
    // print(head);

    // head = removesTail(head);
    // print(head);

    // head = removeK(head, 3);
    // print(head);

    head = removeEl(head, 8);
    print(head);
    
    return 0;
}