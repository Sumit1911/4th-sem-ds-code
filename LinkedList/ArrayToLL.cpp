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

/**Length of LL */
int lengthOfLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

/**Search element in LL */
int searchInLL(Node* head, int elem) {
    Node* temp = head;
    while (temp) {
        if(temp->data == elem) {
            return 1;
        }
        temp = temp->next;
    }
    return -1; 
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    // cout<<head->data<<" ";
    // cout<<head->next->data<<" ";
    // cout<<head->next->next->data<<" ";
    // cout<<head->next->next->next->data;

    /**Traversal the LL */
    Node* temp = head;
    while (temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl<<lengthOfLL(head)<<endl;

    int check = searchInLL(head, 10);
    if(check == 1) {
        cout<<"Yes element exist"<<endl;
    } else {
        cout<<"No element not exist"<<endl;
    }
    
    return 0;
}