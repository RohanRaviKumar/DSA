#include <stdio.h>
#include <stdlib.h>

struct PQ{
	int ele[100];
	int size;
};

void init(struct PQ *p){
	p->size=0;
	p->ele[0]=1000;
}

void insert(struct PQ *p, int x){
	int i;
	for (i=++p->size; p->ele[i/2] < x; i=i/2){
		p->ele[i]=p->ele[i/2];
	}
	p->ele[i]=x;
}

void print(struct PQ *p){
	printf("\nHeap array : ");
	for (int i=1; i<p->size+1; i++){
		printf("%d ",p->ele[i]);
	}
}

int deleteMax(struct PQ *p){
	int i, child;
	int max=p->ele[1];
	int last=p->ele[p->size--];
	
	for (i=1; i*2 <= p->size; i=child){
		child = i*2;
		if (p->ele[child+1] > p->ele[child]){
			child++;
		}
		if (last < p->ele[child]){
			p->ele[i]=p->ele[child];
		}
		else{
			break;
		}
	}
	p->ele[i]=last;
	return max;
}