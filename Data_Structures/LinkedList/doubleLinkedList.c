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

struct node* search(struct node *h, int x){
    struct node *ptr=h->right;
    while (ptr!=NULL){
        if (ptr->data == x){
            return ptr;
        }
        ptr=ptr->right;
    }
    return NULL;
}

void insertMiddle(struct node *h, int key, int ele){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    struct node *ptr;
    ptr=search(h,key);
    if(ptr==NULL){
        printf("Not found\n");
    }

    else if (ptr->right==NULL){
        temp->right=NULL;
        temp->left=ptr;
        ptr->right=temp;
    }

    else{
        struct node *nextn=ptr->right;
        ptr->right=temp;
        temp->left=ptr;
        temp->right=nextn;
        nextn->left=temp;
    }
}

void display(struct node *h){
    struct node *ptr=h->right;
    struct node *end;
    printf("\nArray elements forward : ");
    while (ptr!=NULL){
        printf("%d  ",ptr->data);
        end=ptr;
        ptr=ptr->right;
    }
    printf("\nArray elements backward : ");
    while(end!=h){
        printf("%d  ",end->data);
        end=end->left;
    }
}

int searchItem(struct node *h, int c){
    struct node *ptr=h->right;
    int occ=0;
    while (ptr!=NULL){
        if (ptr->data == c){
            occ++;
        }
        ptr=ptr->right;
    }
    return occ;
}

void deleteItem(struct node *h, int key){
    struct node *ptr=h;
    struct node *cur=h->right;
    struct node *nextn=cur->right;

    while (cur->right != NULL){
        if (cur->data == key){
            ptr->right=nextn;
            nextn->left=ptr;
            break;
        }

        cur=cur->right;
        ptr=ptr->right;
        nextn=nextn->right;
    }
}

int duplicates(struct node* h)
{
    struct node *ptr = h->right;
    while (ptr->right != NULL){
        int c = searchItem(h,ptr->data);
        if (c>0){
            return 1;
        }
    }
    return 0;
}

struct node* add(struct node* n1,struct node* n2)
{
    struct node* res=(struct node*)malloc(sizeof(struct node));
    struct node *p1,*p2;
    p1=n1->right;
    p2=n2->right;
    res->left=NULL;
    res->right=NULL;
    int sum,carry=0;
    while(p1->right!=NULL)
    {
        p1=p1->right;
        p2=p2->right;
    }

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
    struct node *header;
    header=(struct node *)malloc(sizeof(struct node));
    header->left=NULL;
    header->right=NULL;
    insertEnd(header,6);
    insertFront(header,2);
    insertMiddle(header,2,1);
    insertMiddle(header,2,1);
    
    display(header);
    printf("\n\nNumber of occurences of 1 is : %d\n",searchItem(header,1));  

    if (duplicates(header) == 1){
        printf("\n\nDuplicates are present in the linked list");
    }
    else{
        printf("\n\nDuplicates are not present in the linked list");
    }

    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *n2=(struct node *)malloc(sizeof(struct node));

    n1->left = NULL;
    n1->right = NULL;

    n2->left = NULL;
    n2->right = NULL;

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