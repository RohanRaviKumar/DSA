#include <stdio.h>
#include <stdlib.h>

struct queue{
	int a[100];
	int f,r,size;
};


void createQueue(struct queue *q, int s){
	q->size=s;
	q->f = q->r = -1;
}

void enqueue(struct queue *q, int x){
	if (q->f==-1 && q->r==-1){
		q->f++;
		q->r++;
		q->a[q->r] = x;
	}
	else if ((q->r+1)%(q->size) == q->f){
		printf("The queue is full. Cannot push\n");
	}
	else{
		q->r=(q->r+1)%(q->size);
		q->a[q->r] = x;
	}
}

int dequeue(struct queue *q){
	if (q->f == -1 && q->r == -1){
		return -1;
	}
	else if(q->f == q->r){
		int d;
		d=q->a[q->f];
		q->f=-1;
		q->r=-1;
		return d;
	}
	else{
		int d;
		d=q->a[q->f];
		q->f = (q->f +1)%(q->size);
		return d;
	}
}

int queueIsEmpty(struct queue *q){
	if (q->f==-1 && q->r==-1){
		return 1;
	}
	return 0;
}

void displayQueue(struct queue *q){
	printf("Queue elements : ");
	if (q->r < q->f){
		for (int i=q->f; i<q->size; i++){
			printf("%d ",q->a[i]);
		}
		for (int i=0; i<q->r; i++){
			printf("%d ",q->a[i]);
		}
	}
	else if (q->f==-1 && q->r == -1){
		for (int k=q->f; k<q->r+1; k++){
			printf("%d ",q->a[k]);
		}
	}
	
	else{
		for (int k=q->f; k<q->r+1; k++){
			printf("%d ",q->a[k]);
		}
	}
	printf("\n");
}
