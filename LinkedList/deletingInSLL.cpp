#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int i;
    struct node* link;
};

struct node* head;

//deleting from the beginning
void deleteFromBegin() {
    if(head==NULL)
      return;
    else if(head->link==NULL) {
        free(head);
        head = NULL;
        return;
    } else {
        struct node *t = head;
        head = head->link;
        free(t);
    }
}
//deleting from the end
void deleteFromEnd() {
    struct node *t = head;
    if(head==NULL)
        return;
    else if(t->link==NULL) {
        free(t->link);
        t = NULL;
        return;
    } else {
        while (t->link->link!=NULL) {
            t = t->link;
        }
        free(t->link);
        t->link = NULL;
    }
}
//deleting from the intermediate
void deleteFromIntermediate() {
    if(head==NULL)
      return;
    else if(head->link==NULL) {
        free(head);
        head = NULL;
        return;
    } else {
        struct node *t = head;
        int pos = 2, counter = 1;
        while (t->link->link!=NULL && counter!=pos-1) {
            counter++;
            t = t->link;
        }
        struct node *t1 = t->link;
        t->link = t1->link;
        free(t1);
        // t->link = t->link->link;
        
    }
}

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
    // deleteFromBegin();
    // print();
    // deleteFromEnd();
    // print();
    deleteFromIntermediate();
    print();
    return 0;
}