#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int i;
    struct node* link;
};

struct node* head;

void print() {
    struct node* t;
    t = head;
    while (t!=NULL){
        printf("%d ", t->i);
        t = t->link;
    }
    printf("NULL");
    cout<<endl;
}
//inserting new node at the begin
void insertingAtBeginning() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->i = 1;
    newNode->link = head;
    head = newNode;
}
//inserting new node at the end
void insertingAtEnd() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->i = 3;
    struct node* t;
    t = head;
    while (t->link!=NULL) {
        t = t->link;
    }
    t->link = newNode;
    newNode->link = NULL;
}
//Inserting new node in intermediate of the node
void insertingAtIntermediate() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->i = 2;
    struct node* t;
    t = head;
    int pos = 2;
    int counter = 1;
    while (t->link!=NULL && counter!=pos-1) {
        counter++;
        t = t->link;
    }
    newNode->link = t->link;
    t->link = newNode;
}

int main() {
    insertingAtBeginning(); 
    print(); 
    insertingAtEnd();
    print();
    insertingAtIntermediate();
    print();
    return 0;
}