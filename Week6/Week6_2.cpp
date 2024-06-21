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

class Stack {
    Node* top;
    public:
    Stack() {
        top = nullptr;
    }
    
    void push(int data) {
        Node* temp = new Node(data);
        if(temp == nullptr) {
            cout<<"Stack Overflow"<<endl;
            return;
        } 
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    void pop() {
        Node* temp;
        if(top == nullptr) {
            cout<<"Stack Underflow"<<endl;
        }
        temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if(top == nullptr) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return top->data;
    }

    int peep(int i) {
        Node* temp = top;
        if(temp == nullptr) {
            return -1;
        }
        if(i == 1) {
            return top->data;
        }
        int count = 0;
        while(temp != nullptr) {
            count++;
            if(count == i) {
                return temp->data;
            }
            temp = temp->next;
        }
        return -1;
    }

    bool isEmpty() {
        if(top == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    int size() {
        int count = 0;
        Node* temp = top;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = top;
        if(top == nullptr) {
            cout<<"Stack Underflow"<<endl;
        }

        while(temp != nullptr) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


int main() {
    Stack s;
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(10);
    s.pop();

    cout<<s.peek()<<endl;

    s.display();

    cout<<s.peep(2)<<endl;
    cout<<s.isEmpty()<<endl;

    cout<<"Size of Stack : "<<s.size();

    return 0;
}