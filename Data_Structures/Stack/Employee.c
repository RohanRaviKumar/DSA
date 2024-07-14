#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp{
	char jid[2];
	int time;
};

struct queue{
	struct emp e[100];
	int size;
	int front, rear;
};

void create(struct queue* q, int size){
	q->size = size;
	q->front = q->rear = -1;
}

int isFull(struct queue* q){
	if(q->rear + 1 >= q->size) return 1;
	else return 0;
}

int isEmpty(struct queue* q){
	if(q->rear == -1 && q->front == -1) return 1;
	else if(q->front > q->rear){
		q->front = q->rear = -1;
		return 1;	
	}
	else return 0;
}

void enqueue(struct queue* q, struct emp job){
	if(isFull(q)){
		printf("\nQueue is full");
	}
	else{
		if(q->rear == -1){
			q->front++;
		}
		q->rear++;
		strcpy(q->e[q->rear].jid, job.jid);
		q->e[q->rear].time = job.time;
	}
}

struct emp* dequeue(struct queue* q){
	if(isEmpty(q)){
		printf("\nQueue is empty");
		return NULL;
	}
	else{
		return &(q->e[q->front++]);
	}
}

int waitingTime(struct queue* q){
	if(isEmpty(q)) return 0;
	int sum = 0;
	for(int i = q->front ; i <= q->rear ; i++){
		sum += q->e[i].time;
	}
	return sum;
}

void allocateJob(struct queue* q1, struct queue* q2, struct emp job){
	if(waitingTime(q1) <= waitingTime(q2)) enqueue(q1, job);
	else enqueue(q2, job);
} 

int main(){
	int choice = 1;
	printf("\nEnter size of queue1: ");
	int size1;
	scanf("%d", &size1);
	printf("\nEnter size of queue2: ");
	int size2;
	scanf("%d", &size2);
	struct queue *q1 = (struct queue*) malloc(sizeof(struct queue));
	struct queue *q2 = (struct queue*) malloc(sizeof(struct queue));
	create(q1, size1);
	create(q2, size2);
	while(choice){
		
		printf("\n\n1. Enqueue\n2. Dequeue Queue 1\n3. Dequeue Queue 2\n0. Exit\nEnter choice: ");
		scanf("%d", &choice); 
		switch(choice){
			case 1: {
				struct emp job;
				printf("\nEnter job ID: ");
				scanf("%s", &job.jid);
				printf("\nEnter time: ");
				scanf("%d", &job.time);
				allocateJob(q1, q2, job);
				break;
			}
			case 2: {
				struct emp *deq = dequeue(q1);
				if(deq != NULL){
					printf("\n%s is removed", deq->jid);
				}
				break;
			}
			case 3: {
				struct emp *deq = dequeue(q2);
				if(deq != NULL){
					printf("\n%s is removed", deq->jid);
				}
				break;
			}
		}
	}
}