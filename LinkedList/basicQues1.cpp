//move last node to front of sll
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
    while (t!=NULL) {
        printf("%d ", t->i);
        t = t->link;
    }
    printf("NULL");
    cout<<endl; 
}
void moveLastToFront() {
    struct node* t;
    t = head;
    while (t->link!=NULL) {
        t = t->link;
    }

    struct node *p, *q;
    if(!head || !head->link) 
       return;
    p = head;
    q = t;
    int temp = p->i;
    p->i = q->i;
    q->i = temp;
    p = q->link;
    // q = p?p->link:0;
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

    // print();
    moveLastToFront();
    print();

    return 0;
}