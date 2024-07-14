#include <stdio.h>
#include <stdlib.h>

struct stack{
	int size;
	int top;
	int data[100];
};

void createStack(struct stack *s, int l){
	s->size=l;
	s->top=-1;
}

int stackIsFull(struct stack *s){
	if (s->top==s->size -1){
		return 1;
	}
	return 0;
}

void push(struct stack *s, int data){
	if (!stackIsFull(s)){
		s->data[++s->top]=data;
	}
	else{
		printf("Stack is full. Unable to push\n");
	}
}

int stackIsEmpty(struct stack *s){
	if (s->top==-1){
		return 1;
	}
	return 0;
}

int pop(struct stack *s){
	if (stackIsEmpty(s)){
		return -1;
	}
	else{
		return s->data[s->top--];
	}
}

int peek(struct stack *s){
	if (stackIsEmpty(s)){
		return -1;
	}	
	else{
		return s->data[s->top];
	}
}

void displayStack(struct stack *s){
	printf("Stack elements : ");
	for (int k=0; k<s->top+1; k++){
		printf("%d ",s->data[k]);
	}
	printf("\n");
}