#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void create(struct node *h)
{
    h->next = NULL;
}

void insertAtEnd(struct node *h, int x)
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

void insertAtFront(struct node *h, int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=h->next;
	h->next=temp;
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

int searchElt(struct node *h,int x)
{
    struct node *ptr;
    ptr=h->next;
    while (ptr!=NULL){
        if (ptr->data==x){
            return ptr->data;
        }
        ptr=ptr->next;
    }
    return -1;
}

int length(struct node *h)
{
	if (h==NULL){
		return 0;
	}
	int len=0;
	struct node *ptr;
	ptr=h->next;
	while (ptr!=NULL){
		len++;
		ptr=ptr->next;
	}
	return len;
}

int findMiddleElt(struct node *h)
{
	int l=length(h);
	struct node *ptr=h->next;
	for (int i=0;i<(l/2);i++){
		ptr=ptr->next;
	}
	return ptr->data;
}

void reverse(struct node *h)
{
	struct node *prev,*cur,*nextn;
	prev=NULL;
    cur=nextn=h->next;
	while (nextn!=NULL)
	{
        nextn=nextn->next;
        cur->next=prev;
        prev=cur;
        cur=nextn;
	}
    h->next=prev;
}
 
void delete(struct node *header,int ele)
{
    struct node *ptr,*prev;
    ptr=header->next;
    prev=header;
    while(ptr!=NULL){
        if (ptr->data==ele){
            prev->next=ptr->next;
            free(ptr);
            break;
        }
        else{
            prev=ptr;
            ptr=ptr->next;
        }
    }
}

int detectLoop(struct node* list)
{
    struct node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}