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

    void push(int data) {
        Node* temp = new Node(data);
        if(temp == nullptr) {
            cout<<"Stack Overflow!"<<endl;
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

bool checkString(string str1, string str2) {
    Stack s1, s2;

    for(int i=0; i<str1.length(); i++) {
        if(str1[i]>='a' && str1[i]<='z' || str1[i]>='A' && str1[i]<='Z') {
            s1.push(str1[i]);
        } else {
            if(str1[i] == '#') {
                s1.pop();
            }
        }
    }
    
    for(int i=0; i<str2.length(); i++) {
        if(str2[i]>='a' && str2[i]<='z' || str2[i]>='A' && str2[i]<='Z') {
            s2.push(str2[i]);
        } else {
            if(str2[i] == '#') {
                s2.pop();
            }
        }
    }

    while(!s1.isEmpty() && !s2.isEmpty()) {
        if(s1.peek() != s2.peek()) {
            return false;
        }
        s1.pop(); 
        s2.pop();
    }
    return true;
}

int main() {
    string str1 = "abb##c";
    string str2 = "abc";
    cout<<"First string : "<<str1<<endl<<"Second string : "<<str2<<endl;
    int result = checkString(str1, str2);
    if(result == 1) {
        cout<<"Both String are equal!"<<endl;
    } else {
        cout<<"Both String are not equal!"<<endl;
    }
    
    return 0;
}