#include<iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int stackSize, top;

    Stack(int size) {
        stackSize = size;
        arr = new int[size];
        top = -1;
    }

    void push(int elem) {
        if(top < stackSize - 1) {
            arr[++top] = elem;
        } else {
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        } else {
            cout<<"Stack is empty"<<endl;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        } else {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

class Queue{
public:
    int *arr;
    int size;
    int front, rear;

    Queue(int size) {
        arr = new int[size];
        this->size = size;
        front = 0;
        rear = 0;
    }

    void enqueue(int element) {
        rear = (rear + 1) % size;
        if(front == rear) {
            cout<<"Queue Overflow"<<endl;
            rear = (rear == 0) ? size - 1 : rear - 1;
        } else {
            arr[rear] = element;
        }
    }

    int dequeue() {
        if(front == rear) {
            cout<<"Queue Underflow"<<endl;
            return -1;
        } else {
            front = (front + 1) % size;
            int item = arr[front];
            return item;
        }
    }

    int frontQ() {
        if(front == rear) {
            cout<<"Queue is empty"<<endl;
            return -1;
        } else {
            return arr[(front + 1) % size];
        }
    }

    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Before Reverse : ";
    cout<<s.peek()<<" "; s.pop();
    cout<<s.peek()<<" "; s.pop();
    cout<<s.peek(); cout<<endl;

    Queue q(5);
    while(!s.isEmpty()) {
        q.enqueue(s.peek());
        s.pop();
    }

    cout<<"After Reverse : ";
    while(!q.isEmpty()) {
        cout<<q.dequeue()<<" ";
    }
    cout<<endl;

    return 0;
}
