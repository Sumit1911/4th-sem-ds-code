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
    int peek() {
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



int postfixEval(string str) {
    Stack s;
    for(int i=0; i<str.length(); i++) {
        if(str[i]>='0' && str[i]<='9') {
            s.push(str[i] - '0');
        } else {
            if(str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
                int a = s.peek(); s.pop();
                int b = s.peek(); s.pop();
                
                switch (str[i]) {
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(a-b);
                        break;
                    case '*':
                        s.push(a*b);
                        break;
                    case '/':
                        s.push(a/b);
                        break;
                }
            }
        }
    }
    return s.peek();
};

int main() {
    string str = "46+2/5*9";
    cout<<postfixEval(str);
    
    return 0;
}