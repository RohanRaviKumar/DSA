#include <stdio.h>
#include <stdlib.h>

struct arr {
    int a[100];
    int size;
};

void create(struct arr *p, int s, int arr[]) {
    p->size = s;
    for (int i = 0; i < p->size; i++) {
        p->a[i] = arr[i];
    }
}

void printArray(struct arr *p) {
    for (int i = 0; i < p->size; i++) {
        printf("%d ", p->a[i]);
    }
}

void insertfront(struct arr *p, int data) {
    p->size = (p->size) + 1;
    for (int i = (p->size) - 1; i > -1; i--) {
        p->a[i] = p->a[i - 1];
    }
    p->a[0] = data;
}

void insertlast(struct arr *p, int data) {
    p->a[(p->size)] = data;
    p->size = (p->size) + 1;
}

void insertmiddle(struct arr *p, int pos, int data) {
    p->size = (p->size) + 1;
    for (int i = (p->size); i > pos; i--) {
        p->a[i] = p->a[i - 1];
    }
    p->a[pos] = data;
}

void deletefirst(struct arr *p) {
    for (int i = 0; i < (p->size); i++) {
        p->a[i] = p->a[i + 1];
    }
    p->size = (p->size) - 1;
}

void deletelast(struct arr *p) 
{ 
    p->a[(p->size)-1]=0;
    p->size = (p->size) - 1;
}

void deletemiddle(struct arr *p, int pos) {
    for (int i = pos; i < (p->size) - 1; i++) {
        p->a[i] = p->a[i + 1];
    }
    p->size = (p->size) - 1;
}

void search(struct arr *p, int data) {
    int flag = 0;
    for (int i = 0; i < (p->size); i++) {
        if (p->a[i] == data) {
        printf("Element Found at Index %d", i);
        flag = 1;
        }
    }
    if (flag == 0) {
        printf("Element Not Found");
    }
}