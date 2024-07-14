#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack{
	char sbl[100];
	int top;
};

void create(struct stack *s){
	s->top=-1;
}

void push(struct stack *s,char a){
	s->sbl[++(s->top)]=a;
}

int isEmpty(struct stack *s){
	if (s->top==-1){
		return 1;
	}
	return 0;
}

void pop(struct stack *s){
	s->top--;
}

char popItem(struct stack *s){
	s->top--;
	return s->sbl[(s->top)+1];
}

char peek(struct stack *s){
	if (isEmpty(s)==1){
		return '[';
	}
	return s->sbl[s->top];
}

int length(char exp[]){
	int j=0;
	while (exp[j]!='\0'){
		j++;
	}
	return j;
}

int checkExpression(char exp[]){
	int n=length(exp);
	
	struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
	create(stack);
	for (int j=0; j<n; j++){
		if (exp[j]=='(' || exp[j]=='{' || exp[j]=='['){
			push(stack,exp[j]);
		}
		
		else if (exp[j]==')' || exp[j]=='}' || exp[j]==']'){
			if (isEmpty(stack)){
				return 0;
			}
			else{
				pop(stack);
			}
		}
	}
	
	if (isEmpty(stack)){
		return 1;
	}
	else{
		return 0;
	}
}	

void infixToPostfix(char exp[]){
	char postfix[100];
	int j=0;
	struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
	create(stack);
	int n=length(exp);
	
	for (int i=0;i<n;i++){
		if (exp[i] == '('){
			push(stack,exp[i]);
		}
		
		else if (isalnum(exp[i])){
			postfix[j]=exp[i];
			j++;
		}
		
		else if (exp[i] == '*' || exp[i] == '/'){
			push(stack,exp[i]);
		}
		
		else if (exp[i] == '+' || exp[i] == '-'){
			if (peek(stack) == '*' || peek(stack) == '/'){
				postfix[j]=popItem(stack);
				j++;
				push(stack,exp[i]);
			}
			else{
				push(stack,exp[i]);
			}
		}
		
		else if (exp[i] == ')'){
			while (peek(stack)!='('){
				postfix[j]=popItem(stack);
				j++;
			}
			pop(stack);
		}
	}
	
	while (isEmpty(stack)==0){
		postfix[j]=popItem(stack);
		j++;
	}
	
	postfix[j]='\0';
    printf("\n");
	printf("\nThe postfix expression : %s",postfix);
	
}

int main()
{
	char exp[100];
	printf("Enter an infix expression : ");
	scanf("%[^\n]",exp);
	if (checkExpression(exp)==1){
		printf("\nThe given expression is : %s",exp);
		infixToPostfix(exp);
		printf("\n\n");
	}
	else{
		printf("Expression is invalid\n");
	}
}
