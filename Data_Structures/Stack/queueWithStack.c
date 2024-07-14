#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	struct stack *s1=(struct stack *)malloc(sizeof(struct stack));
	struct stack *s2=(struct stack *)malloc(sizeof(struct stack));
	int size,choice,data;
	printf("Enter size : ");
	scanf("%d",&size);
	create(s1,size);
	create(s2,size);
	while(choice+1)
	{
		printf("\n-1: EXIT\n0: ENQUEUE\n1: DEQUEUE\nChoice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case -1:
			break;
			case 0:
			printf("Enter element : ");
			scanf("%d",&data);
			enqueue(s1,s2, data);
			break;
			case 1:
			if(!queueIsEmpty(s1, s2))
			printf("Element Removed = %d\n",dequeue(s1, s2));
			else printf("QUEUE IS EMPTY");
			break;
			default:
			printf("Invalid choice\n");
		}
	}
}