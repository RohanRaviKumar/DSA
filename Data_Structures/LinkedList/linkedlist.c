#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void create(struct node *h, int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    h->next=temp;
}

void add(struct node *h, int x)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    struct node *last=h;
    while (last->next!=NULL){
        last=last->next;
    }
    last->next=n;
}

void display(struct node *h)
{
    struct node *ptr;
    ptr=h->next;
    while (ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


int search(struct node *h,int x)
{
    struct node *ptr;
    ptr=h->next;
    while (ptr!=NULL){
        if (ptr->data==x){
            return ptr;
        }
        ptr=ptr->next;
    }
    return NULL;
}

int insertAfter(struct node *h,int key, int new)
{
    struct node *ptr;
    struct node *temp;
    ptr=search(h,key);
    if (ptr==NULL){
        return -1;
    }
    else{
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=new;
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

void delete(struct node *header,int ele)
{
    struct node *ptr,*prev;
    ptr=header->next;
    prev=header;
    while(ptr!=NULL){
        if (ptr->data==ele){
            prev->next=ptr->next;
            break;
        }
        else{
            prev=ptr;
            ptr=ptr->next;
        }
    }
}

int main()
{
    struct node *header;
    header=(struct node *)malloc(sizeof(struct node));
    header->next=NULL;
    create(header,3);
    printf("Array elements : ");
    display(header);
    add(header,5);
    add(header,8);
    add(header,10);
    printf("Array elements after appending : ");
    display(header);
    int check=insertAfter(header,8,9);
    if (check!=-1){
        printf("Array elements after inserting after : ");
        display(header);
    }
    else{
        printf("Key was not found in the array \n");
    }
    delete(header,8);
    printf("Array elements after deleting : ");
    display(header);
}

