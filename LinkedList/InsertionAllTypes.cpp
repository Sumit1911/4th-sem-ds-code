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

//insertion at starting of LL
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}

//insertion at last 
Node* insertTail(Node* head, int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

//inserting at kth position
Node* insertPosition(Node* head, int el, int k) {
    if(head == NULL) {
        if(k==1) {
            return new Node(el);
        } else {
            return head;
        }
    } 
    if(k == 1){
        return new Node(el, head);
    }
    int count = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        count++;
        if(count == (k-1)) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//inserting at before the value
Node* insertBeforeVal(Node* head, int el, int val) {
    if(head == NULL) {
       return NULL;
    } 
    if(head->data == val){
        return new Node(el, head);
    }
    
    Node* temp = head;
    while (temp->next != NULL)
    {
        if(temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    print(head);

    // head = insertHead(head, 100);
    cout<<"Insert at first : "
    // print(head);

    // head = insertTail(head, 100);
    // print(head);


    // head = insertPosition(head, 100, 2);
    // print(head);

    head = insertBeforeVal(head, 100, 5);
    print(head);

    return 0;
}