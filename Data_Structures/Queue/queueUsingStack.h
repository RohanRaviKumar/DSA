#include <stdio.h>
struct stack
{
     int top;
     int a[100];
     int size;
};
void create(struct stack *s,int size)
{
    s->size=size;
    s->top=-1;
}
int isFull(struct stack *s)
{
    if(s->top<(s->size-1))
        return 0;
    return 1;
}
void push(struct stack *s,int data)
{
    s->a[++s->top]=data;
}
int isEmpty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
int pop(struct stack *s)
{
    return(s->a[s->top--]);
}
int peek(struct stack *s)
{
    if(isEmpty(s))
        return -1;
    else
        return s->a[s->top];
}

int queueIsFull(struct stack *s1, struct stack *s2){
    if(s1->top + s2->top < s1->size-2)
        return 0;
    return 1;
}

int queueIsEmpty(struct stack *s1, struct stack *s2){
    if(s1->top == -1 && s2->top == -1)
        return 1;
    return 0;
}

void enqueue(struct stack *s1, struct stack *s2, int data){
    if(queueIsFull(s1, s2)){
        printf("QUEUE IS FULL");
    }
    else{
        push(s1, data);
    }
}

int dequeue(struct stack *s1, struct stack *s2){
    if(queueIsEmpty(s1, s2)){
        printf("QUEUE IS EMPTY");
    }
    else{
        if(isEmpty(s2)){
            while(!isEmpty(s1)){
                push(s2, pop(s1));
            }
        }
        return pop(s2);
    }
}

int peekQueue(struct stack *s1, struct stack *s2){
    if(queueIsEmpty(s1, s2)){
        printf("QUEUE IS EMPTY");
    }
    else{
        if(isEmpty(s2)){
            while(!isEmpty(s1)){
                push(s2, pop(s1));
            }
        }
        return peek(s2);
    }
}
