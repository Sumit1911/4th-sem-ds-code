#include <iostream>
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
	public:
	int minEle;
	Node* top;
    
	Stack () {
		top = nullptr;
	}

	void push(int data) {
		Node* temp = new Node(data);
		if(temp == nullptr) {
			cout<<"Stack Overflow!"<<endl;
			return;
		}
		if(top == nullptr) {
			temp->data = data;
			temp->next = top;
			top = temp;
			minEle = data;
		} else {
			if(data>minEle) {
				temp->data = data;
				temp->next = top;
				top = temp;
			} else {
				temp->data = 2*data - minEle;
				temp->next = top;
				top = temp;
				minEle = data;
			}
		}
	}
	int peek() {
		return top->data;
	}

	void pop() {
		if(peek() >= minEle) {
			minEle = minEle;
		} else {
			minEle = 2*minEle - peek();
		}
		top = top->next;
	}

	void getMin() {
		if(top == nullptr) {
			cout<<"Stack is Empty!";
		} else {
			cout<<"Min Elem in the Stack : "<<minEle<<endl;
		}
	}
	
};

int main() {
	Stack s;

	s.push(3);
	s.push(5);
	s.push(2);
	s.push(1);
	s.getMin();

	return 0;
}
