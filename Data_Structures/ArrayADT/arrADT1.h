#include <stdio.h>
#include <stdlib.h>

struct arr {
    int size;
    int a[100];
};

void create(struct arr *p, int s, int arr[])
{
    p->size = s;
    for (int i = 0; i < p->size; i++) {
        p->a[i] = arr[i];
    }
}

void printArray(struct arr *p)
{
    for (int i = 0; i < p->size; i++) {
        printf("%d ", p->a[i]);
    }
}

void deleteAt(struct arr *p, int pos)
{
    for (int i=pos;i<(p->size)-1;i++){
        p->a[i]=p->a[i+1];
    }
    p->size=(p->size)-1;
}

void insertAtEvery(struct arr *p, int data)
{
    for (int i=p->size; i>=0; i--){
        p->a[2*(i+1) - 1] = p->a[i]; 
    }

    p->size = 2*p->size;

    for (int i=0; i<p->size; i=i+2){
        p->a[i] = data;
    }
} 

int search(struct arr *p, int data)
{
    for (int i = 0; i < (p->size); i++) {
        if (p->a[i] == data) {
            return i;
        }
    }
    return -1;
}

void findPeek(struct arr *p)
{
    printf("Peek elements : ");

    if ((p->a[0])>(p->a[1])){
        printf("%d ",p->a[0]);
    }

    for (int i=1;i<(p->size)-1;i++){
        if ((p->a[i])>(p->a[i-1]) && (p->a[i])>(p->a[i+1])){
            printf("%d ",p->a[i]);
        }
    }

    if ((p->a[(p->size)-1]) > (p->a[(p->size)-2])){
        printf("%d ",p->a[(p->size)-1]);
    }
    
    printf("\n");
}