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

class Stack{
    public:
    Node* top;
    Stack() {
        top = nullptr;
    }

    void push(char data) {
        Node* temp = new Node(data);
        if(temp == nullptr) {
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        temp->data = data;
        temp->next = top;
        top = temp;
    }
    void pop() {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    char peek() {
        if(top == nullptr) {
            cout<<"Stack Underflow!"<<endl;
        }
        return top->data;
    }
    bool isEmpty() {
        if(top == nullptr) {
            return true;
        } else {
            return false;
        }
    }
};

bool validString(string str) {
    Stack s;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(s.isEmpty()) {
                return false;
            }
            char top = s.peek();
            s.pop();
            if(str[i] == ')' && top != '(' || str[i] == '}' && top != '{' || str[i] == ']' && top != '[') {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string str = "[{)}]";
    cout<<"Given String : "<<str<<endl;
    if(validString(str)) {
        cout<<"Valid String!"<<endl;
    } else {
        cout<<"Result : Invalid String!"<<endl;
    }
    
    
    return 0;
}