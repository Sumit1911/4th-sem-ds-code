//swapping element

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int val;
    struct node* next;
};
struct node* list;

void print() {
    struct node* t;
    t = list;
    while (t!=NULL)
    {
        cout<<t->val<<" ";
        t = t->next;
    }
    cout<<"NULL";
    cout<<endl;
    
}

void rearrange() {
    struct node *p, *q;
    int temp;
    if(!list || !list->next) 
       return;
    p = list;
    q = list->next;
    while (q) {
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        p = q->next;
        q = p?p->next:0;
    }
    
}

int main() {
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    struct node* n2 = (struct node*)malloc(sizeof(struct node));
    struct node* n3 = (struct node*)malloc(sizeof(struct node));
    struct node* n4 = (struct node*)malloc(sizeof(struct node));
    struct node* n5 = (struct node*)malloc(sizeof(struct node));
    struct node* n6 = (struct node*)malloc(sizeof(struct node));
    struct node* n7 = (struct node*)malloc(sizeof(struct node));
    n1->val = 1; n1->next = n2;
    n2->val = 2; n2->next = n3;
    n3->val = 3; n3->next = n4;
    n4->val = 4; n4->next = n5;
    n5->val = 5; n5->next = n6;
    n6->val = 6; n6->next = n7;
    n7->val = 7; n7->next = NULL;
    list = n1;

    print();
    rearrange();
    print();
    return 0;
}