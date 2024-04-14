#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front, rear;

    Queue(int size) {
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int element) {
        rear = (rear+1)%size;
        if(front == rear) {
            cout<<"Queue Overflow"<<endl;
            if(rear == 0) {
                rear = size-1;
            } else {
                rear = rear-1;
            }
        } else {
            arr[rear] = element;
        }
    }

    int dequeue() {
        if(front == rear) {
            cout<<"Queue Underflow"<<endl;
        } else {
            front = (front+1)%size;
            int item = arr[front];
            return item;
        }

    }

    int frontQ() {
        int temp = front;
        temp = (front+1)%size;
        int item = arr[temp];
        return item;
    }

    bool isEmpty() {
        if(front == rear) {
            return true;
        }
        return false;
    }

    int sizeQ() {
        int temp = front;
        int count = 0;
        while(temp!=rear) {
            count++;
            temp = (temp+1)%size;
        }
        return count;
    }

    void display() {
        int temp = front;
        while(temp!=rear) {
            temp++;
            cout<<arr[temp]<<" ";
        }
        cout<<endl;
    }

};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<"Element from dequeue : "<<q.dequeue()<<endl;
    cout<<"Element from front : "<<q.frontQ()<<endl;
    cout<<"Element is empty : "<<q.isEmpty()<<endl;
    q.display();
    cout<<"Size : "<<q.sizeQ()<<endl;

    return 0;
}