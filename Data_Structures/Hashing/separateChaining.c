#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct HashTableADT{
    int s;
    struct node *list[100];
};

void init(struct HashTableADT *h, int size){
    h->s = size;
    for (int i=0; i<size; i++){
        h->list[i] = (struct node *)malloc(sizeof(struct node));
        h->list[i]->next = NULL;
    }
}

void insert(struct HashTableADT *h, int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next =NULL;
    temp->data = x;

    int f = x%(h->s);
    struct node *ptr = h->list[f];

    while (ptr->next!=NULL){
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void display(struct node *h){
    struct node *ptr = h->next;

    while (ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

void displayHashTable(struct HashTableADT *h){
    for (int i=0; i<h->s; i++){
        printf("%d : ",i);
        display(h->list[i]);
        printf("\n");
    }
}

int searchElement(struct HashTableADT *h, int key){
    int f = key%(h->s);

    struct node *ptr = h->list[f];
    while (ptr!=NULL){
        if (ptr->data == key){
            return 1;
        }
        ptr = ptr->next;
    }
    return -1;
}

int main()
{
    struct HashTableADT *hash = (struct HashTableADT *)malloc(sizeof(struct HashTableADT));
    init(hash,10);
    insert(hash,23);
    insert(hash,45);
    insert(hash,69);
    insert(hash,87);
    insert(hash,48);
    insert(hash,67);
    insert(hash,54);
    insert(hash,66);
    insert(hash,63);

    displayHashTable(hash);

    printf("Finding element 66 : %d\n",searchElement(hash,66));
    printf("Finding element 93 : %d\n",searchElement(hash,93));
    
}