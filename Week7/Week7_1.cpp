#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next1 = next;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Stack {
    public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(char data) {
        Node* temp = new Node(data);
        if(temp == nullptr) {
            cout<<"Stack Overflow"<<endl;
        }
        temp->data = data;
        temp->next = top;
        top = temp;
    }
    void pop() {
        if(top == nullptr) {
            cout<<"Stack Underflow"<<endl;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    char peek() {
        if(top == nullptr) {
            cout<<"Stack Underflow"<<endl;
        }
        Node* temp = top;
        return temp->data;
    }

    bool isEmpty() {
        if(top == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void display() {
        Node* temp = top;
        if(top == nullptr) {
            cout<<"Stack Underflow"<<endl;
        }

        while(temp != nullptr) {
            cout<<temp->data;
            temp = temp->next;
        }
        cout<<endl;
    }
};

int charPrecedence(char c) {
    if(c == '^') 
        return 3;
    else if(c == '*' || c == '/') 
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

void infixToPostfix(string str) {
    Stack s;
    for(int i=0; i<str.length(); i++) {
        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]>='0' && str[i]<='9') {
            cout<<str[i];
        } else if(str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                cout<<s.peek();
                s.pop();
            }
            s.pop();
        } else {
            while(!s.isEmpty() && charPrecedence(s.peek())>charPrecedence(str[i])) {
                cout<<str[i];
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.isEmpty()) {
        cout<<s.peek();
        s.pop();
    }
};

int main() {
    string str = "3+2*1";
    infixToPostfix(str);
    
    return 0;
}