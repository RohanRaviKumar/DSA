#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};

void insertEnd(struct node *h, int x){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    if (h->right==NULL){
        temp->right=NULL;
        temp->left=h;
        h->right=temp;
    }
    else{
        struct node *ptr=h->right;
        while (ptr->right!=NULL){
            ptr=ptr->right;
        }
        ptr->right=temp;
        temp->left=ptr;
        temp->right=NULL;
    }
}

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

struct node* add(struct node* n1,struct node* n2)
{
        struct node* res=(struct node*)malloc(sizeof(struct node));
        struct node *p1,*p2,*end1,*end2;
        p1=n1->right;
        p2=n2->right;
        res->left=NULL;
        res->right=NULL;
        int sum,carry=0;
        while(p1!=NULL)
        {
            end1=p1;
            end2=p2;
            p1=p1->right;
            p2=p2->right;
        }
        p1=end1;
        p2=end2;
        while(p1!=n1)
        {
            sum=p1->data+p2->data+carry;
            insertFront(res,sum%10);
            carry=sum/10;
            p1=p1->left;
            p2=p2->left;
        }
        if(carry!=0)
        {
            insertFront(res,carry);
        }
        return res;
}

void displayNum(struct node *n){
    struct node *ptr=n->right;
    while (ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->right;
    }
}

int main()
{
    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *n2=(struct node *)malloc(sizeof(struct node));
    n1->left=NULL;
    n2->right=NULL;
    n2->left=NULL;
    n2->right=NULL;
    insertEnd(n1,9);
    insertEnd(n1,9);
    insertEnd(n1,9);
    insertEnd(n1,9);
    insertEnd(n2,9);
    insertEnd(n2,9);
    insertEnd(n2,9);
    insertEnd(n2,9);
    struct node *sum=add(n1,n2);
    printf("\n\nSum of the numbers ");
    displayNum(n1);
    printf(" and ");
    displayNum(n2);
    printf(" is : ");
    displayNum(sum);
    printf("\n\n");
}