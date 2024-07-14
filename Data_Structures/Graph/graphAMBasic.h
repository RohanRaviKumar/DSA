#include "queue.h"
#include "stack.h"

int visited[100];
int v=-1;

struct AM{
	int a[10][10];
	int r,c;
};

void create(struct AM *a, int s){
	a->r=a->c = s;
    for (int i=0; i<s; i++){
        for (int j=0; j<s; j++){
            a->a[i][j]=0;
        }
    }
}

void connect(struct AM *a, int v1, int v2){
	if (v1 > a->r || v2> a->r){}

	else{
		a->a[v1-1][v2-1] = 1;
	}
}

void display(struct AM *a){
	for (int i=0; i<a->r; i++){
		for (int j=0;j<a->c; j++){
			printf("%3d",a->a[i][j]);
		}
		printf("\n");
	}
}

void visit(int x){
	visited[++v]=x;
}

int checkVisited(int x){
	for (int i=0; i<=v; i++){
		if (x==visited[i]){
			return 1;
		}
	}
	return 0;
}

void printVisited(){
    printf("Visited array : ");
    for (int i=0; i<=v; i++){
        printf("%d ",visited[i]);
    }
    printf("\n");
}

void BFS(struct AM *a, int x){
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	createQueue(q,a->r);
	visit(x);
	enqueue(q,x);
	while (queueIsEmpty(q) == 0){
		int z = dequeue(q);
		for (int j=0; j<a->c; j++){
			if (a->a[z-1][j] == 1 && checkVisited(j+1)==0){
				visit(j+1);
				enqueue(q,j+1);
			}
		}
	}

	for (int i=0; i<=v; i++){
		printf("%d ",visited[i]);
	}
	printf("\n");
	v=-1;
}

void DFS(struct AM *a, int x){
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	createStack(s,a->r);
	visit(x);
	push(s,x);

	while (stackIsEmpty(s) == 0){
		int t = peek(s);
		int flag = 0;
		for (int j=0; j<a->c; j++){
			if (a->a[t-1][j] == 1 && checkVisited(j+1) == 0){
				visit(j+1);
				push(s,j+1);
				flag = 1;
				break;
			}
		}

		if (flag == 0){
			pop(s);
		}	
	}

	for (int i=0; i<=v; i++){
		printf("%d ",visited[i]);
	}
	printf("\n");
	v=-1;
}