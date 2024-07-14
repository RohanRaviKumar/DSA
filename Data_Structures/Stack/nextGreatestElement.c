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

int main()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    printf("Enter the number of elements in the array : ");
    int num;
    scanf("%d",&num);
    int arr[num];
    for (int i=0;i<num;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    create(s,num);
    push(s,arr[0]);
    for (int j=1; j<num; j++){
        if (arr[j] > peek(s)){
            printf("Next greatest element of %d : %d\n",pop(s),arr[j]);
            push(s,arr[j]);
        }
        else{
            push(s,arr[j]);
        }
    }

    while (!isEmpty(s)){
        printf("Next greatest element of %d is -1\n",pop(s));
    }
}