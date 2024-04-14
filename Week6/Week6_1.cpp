#include<iostream>
using namespace std;

class Stack {
    public:
    int *arr;
    int size;
    int top;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(size-top>1) {
            arr[++top] = element;
        } else {
            cout<<"Stack overflow!"<<endl;
        }
    }

    void pop() {
        if(top>=0) {
            top--;
        } else {
            cout<<"Stack is Empty!"<<endl;
        }
    }

    int peek() {
        if(top>=0) {
            return arr[top];
        } else {
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }
    }

    int peek(int i) {
        if(top == -1 || i <= -1 || i > top) {
            return -1;
        }
        while(i--) {
            top--;
        }
        return arr[top];
    }

    void isEmpty() {
        if(top == -1) {
            cout<<"Stack is Empty!"<<endl;
        } else{
            cout<<"Stack is not Empty!"<<endl;
        }
    }

    void display() {
        while(top>=0) {
            cout<<arr[top]<<" ";
            top--;
        }
        cout<<endl;
    }

    void sizeStack() {
        int count = 0;
        while(top>=0) {
            count++;
            top--;
        }
        cout<<"Size of Stack is "<<count<<endl;
    }

};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    s.pop();
    s.isEmpty();
    
    s.display();
    cout<<s.peek()<<endl;
    cout<<s.peek(6)<<endl;
    s.sizeStack();

    return 0;
}