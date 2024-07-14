#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void insertFront(struct node *h, int x){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    if (h->right == NULL){
        h->right=temp;
        temp->left=h;
        temp->right=NULL;
    }
    else{
        struct node *ptr;
        ptr=h->right;
        temp->right=ptr;
        ptr->left=temp;
        h->right=temp;
        temp->left=h;
    }
}


void display(struct node *h){
    struct node *ptr=h->right;
    while (ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->right;
    }
}

void SepOddEven(struct node *l){
    struct node *pos=(struct node *)malloc(sizeof(struct node));
    struct node *neg=(struct node *)malloc(sizeof(struct node));
    pos->left=NULL;
    pos->right=NULL;
    neg->left=NULL;
    neg->right=NULL;
    struct node *ptr=l->right;
    while (ptr!=NULL){
        if (ptr->data %2 == 0){
            insertFront(pos,ptr->data);
        }
        else{
            insertFront(neg,ptr->data);
        }
        ptr=ptr->right;
    }
    printf("\nEven elements : ");
    display(pos);
    printf("\nOdd elements : ");
    display(neg);
}

int main()
{
    struct node *list=(struct node *)malloc(sizeof(struct node));
    list->left=NULL;
    list->right=NULL;
    insertFront(list,10);
    insertFront(list,-11);
    insertFront(list,19);
    insertFront(list,20);
    insertFront(list,-100);
    insertFront(list,0);
    insertFront(list,91);
    printf("List elements : ");
    display(list);
    SepOddEven(list);
}