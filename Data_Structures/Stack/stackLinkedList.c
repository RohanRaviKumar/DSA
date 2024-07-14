#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

void createStack(struct stack *s, int data){
    struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
    temp->data=data;
    temp->next=s->next;
    s->next=temp;
}

void pop(struct stack *s){
    if (s->next != NULL){
        struct stack *ptr=s->next;
        s->next=ptr->next;
    }
    else{
        printf("Stack is empty\n");
    }
}

int peek(struct stack *s){
    if (s->next==NULL){
        return -1;
    }
    return s->next->data;
}

void display(struct stack *s){
    struct stack *ptr=s->next;
    printf("Stack elements : ");
    
    while (ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
    stack->next=NULL;
    createStack(stack,10);
    createStack(stack,15);
    pop(stack);
    display(stack);
    printf("Peek : %d\n",peek(stack));
    createStack(stack,23);
    createStack(stack,1);
    display(stack);
    printf("Peek : %d\n",peek(stack));
    pop(stack);
    printf("Peek : %d\n",peek(stack));
    pop(stack);
    printf("Peek : %d\n",peek(stack));
    pop(stack);
    printf("Peek : %d\n",peek(stack));
    createStack(stack,22);
    display(stack);
    printf("Peek : %d\n",peek(stack));
}