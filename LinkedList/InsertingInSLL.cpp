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

void insertingAtBeginning() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->i = 5;
    newNode->link = head;
    head = newNode;
}

void insertingAtEnd() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->i = 5;
    struct node* t;
    t = head;
    while (t->link!=NULL) {
        t = t->link;
    }
    t->link = newNode;
    newNode->link = NULL;
}

void insertingAtIntermediate() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->i = 5;
    struct node* t;
    t = head;
    int pos = 3;
    int counter = 1;
    while (t->link!=NULL && counter!=pos-1) {
        counter++;
        t = t->link;
    }
    newNode->link = t->link;
    t->link = newNode;
}

int main() {
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    struct node* n2 = (struct node*)malloc(sizeof(struct node));
    struct node* n3 = (struct node*)malloc(sizeof(struct node));
    struct node* n4 = (struct node*)malloc(sizeof(struct node));
    n1->i = 1; n1->link = n2;
    n2->i = 2; n2->link = n3;
    n3->i = 3; n3->link = n4;
    n4->i = 4; n4->link = NULL;
    head = n1;
    print();
    insertingAtBeginning(); 
    print(); 
    // insertingAtEnd();
    // print();
    // insertingAtIntermediate();
    // print();

    return 0;
}