#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int data[100];
};

void initialize(struct stack *s, int l){
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


void pop(struct stack *s){
    if (isEmpty(s)){
        printf("Stack is empty. Unable to find elements\n");
    }
    else{
        s->top--;
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
    struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
    initialize(stack,3);
    printf("Peek : %d\n",peek(stack));
    push(stack,2);
    push(stack,4);
    push(stack,6);
    push(stack,8);
    pop(stack);
    printf("Peek : %d\n",peek(stack));
    printf("Peek : %d\n",peek(stack));
    pop(stack);
    pop(stack);
    printf("Peek : %d\n",peek(stack));
    pop(stack);
    pop(stack);
    push(stack,100);
    printf("Peek : %d\n",peek(stack));
}

