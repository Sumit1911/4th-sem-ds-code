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

void print(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

//Insert at beginning
Node* insertAtBegin(Node* head, int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* newNode = new Node(val, head);
    return newNode;
}

//Insert at end
Node* insertAtLast(Node* head, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//insert at kth position
Node* insertAtK(Node* head, int elem, int k) {
    if(head==NULL) {
        if(k==1) {
            return new Node(elem);
        } else {
            return head;
        }
    }
    if(k==1) {
        return new Node(elem, head);
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        if(count == (k-1)) {
            Node* x = new Node(elem, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;   
}

//insert specific element
Node* insertBeforeVal(Node* head, int elem, int val) {
    if(head==NULL) {
        return NULL;
    }
    if(head->data == val) {
        return new Node(elem, head);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(elem, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;   
}

//search for a value
int searchVal(Node* head, int val) {
    // int count
    while(head->next != NULL) {
        if(head->data == val) {
            return 1;
        }
        head = head->next;
    }
    return -1;
}

//Delete elements
Node* deleteElem(Node* head, int elem) {
    if(head == NULL) {
        return head;
    }
    if(head->data == elem) {
        Node* temp = head;
        head = temp->next;
        delete head;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if(temp->data == elem) {
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
    Node* x4 = new Node(40);
    Node* x3 = new Node(30, x4);
    Node* x2 = new Node(20, x3);
    Node* x1 = new Node(10, x2);

    Node* head = x1;

    print(head);
    head = insertAtBegin(head, 100);
    cout<<"Insert at first : ";
    print(head);

    head = insertAtLast(head, 100);
    cout<<"Insert at last : ";
    print(head);

    head = insertAtK(head, 100, 2);
    cout<<"Insert at kth pos. : ";
    print(head);

    head = insertBeforeVal(head, 100, 40);
    cout<<"Insert 100 before 40 : ";
    print(head);

    head = deleteElem(head, 30);
    cout<<"After Delete Elem : ";
    print(head);

    int result = searchVal(head, 30);
    cout<<result<<endl;

    return 0;
}