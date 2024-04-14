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

class Queue{
    public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int data) {
        Node* temp = new Node(data);
        if(front == nullptr) {
            front = temp;
            rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
            temp->next = front;
        }
    }

    int dequeue() {
        Node* temp = front;
        if(front == rear) {
            return front->data;
        }
        front = front->next;
        rear->next = front;
        return temp->data;
    }

    int frontQ() {
        Node* temp = front;
        if(front == rear) {
            return front->data;
        }
        front = front->next;
        rear->next = front;
        return temp->data;
    }

    bool isEmpty() {
        if(front == nullptr) {
            return true;
        }
        return false;
    }

    void size() {
        int count = 0;
        if(front == rear) {
            count++;
            cout<<"Size : "<<count<<endl;
            return;
        }
        Node* temp = front;
        while(temp->next != front) {
            count++;
            temp = temp->next;
        }
        count++;
        cout<<"Size : "<<count<<endl;
    }

    void display() {
        Node* temp = front;
        while(temp!=rear) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        if(temp == rear) {
            cout<<temp->data;
        }
        cout<<endl;
    }

};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<"Element from dequeue : "<<q.dequeue()<<endl;
    cout<<"Element from front : "<<q.frontQ()<<endl;
    cout<<"Empty : "<<q.isEmpty()<<endl;

    q.display();
    q.size();

    return 0;
}