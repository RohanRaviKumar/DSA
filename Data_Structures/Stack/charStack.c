#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    char data[100];
};

void create(struct stack *s, int limit){
    s->size=limit;
    s->top=-1;
}

int isFull(struct stack *s){
    if (s->top == s->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *s, char exp){
    if (isFull(s)){
        printf("Stack is full\n");
    }
    else{
        s->data[++(s->top)]=exp;;
    }
}

void display(struct stack *s){
    printf("\nStack elements : ");
    for (int i=0;i<s->top+1;i++){
        printf("%c ",s->data[i]);
    }
}

int isEmpty(struct stack *s){
    if (s->top == -1){
        return 1;
    }
    return 0;
}

char pop(struct stack *s){
    if (isEmpty(s)){
        return '-';
    }
    return s->data[s->top -- ];
}

char peek(struct stack *s){
    if (isEmpty(s)){
        return '-';
    }
    return s->data[s->top];
}

int main()
{
    struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
    create(stack,3);
    push(stack,'a');
    push(stack,'b');
    push(stack,'c');
    printf("Popped element : %c",pop(stack));
    display(stack);
}
