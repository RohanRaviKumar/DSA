#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int data[100];
};

void create(struct stack *s, int l){
    s->size=l;
    s->top=-1;
}

int isFull(struct stack *s){
    if (s->top==s->size -1){
        return 1;
    }
    return 0;
}

void push(struct stack *s, int data){
    if (!isFull(s)){
        s->data[++s->top]=data;
    }
    else{
        printf("Stack is full. Unable to push\n");
    }
}

int isEmpty(struct stack *s){
    if (s->top==-1){
        return 1;
    }
    return 0;
}


int pop(struct stack *s){
    if (isEmpty(s)){
        return -1;
    }
    else{
        return (s->data[(s->top)--]);
    }
}

int peek(struct stack *s){
    if (isEmpty(s)){
        return -1;
    }
    else{
        return s->data[s->top];
    }
}

void decToBin(struct stack *s, int n){
    while (n>0){
        push(s,n%2);
        n=n/2;
    }

    printf("Decimal number in binary is : ");
    while (!isEmpty(s)){
        printf("%d",pop(s));
    }
    printf("\n");
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    create(s,100);
    int num;
    printf("Enter a decimal number to convert to binary : ");
    scanf("%d",&num);
    decToBin(s,num);
}