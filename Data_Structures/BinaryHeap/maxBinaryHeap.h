#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct job{
	char ID;
	int sal;
};

struct PQ {
	struct job j[100];
	int size;
};

void init(struct PQ *p){
	p->size=0;
	p->j[0].ID = '\0';
	p->j[0].sal = 40000; // Salary cannot exceed 40000
}

void insert(struct PQ *p, struct job job){
	int i;
	for (i=++p->size; p->j[i/2].sal < job.sal; i=i/2){
		p->j[i]=p->j[i/2];
	}
	p->j[i]=job;
}

void print(struct PQ *p){
	printf("\n\tJobs\n\n");
	for (int i=1; i<p->size+1; i++){
		printf("%d) ID : %c\n   Salary : %d\n",i,p->j[i].ID,p->j[i].sal);
	}
}

struct job deleteMax(struct PQ *p)
{
	int i, child;
	struct job min, last;
	min=p->j[1];
	last=p->j[p->size--];
	
	for (i=1; i*2 <= p->size; i=child){
		child = i*2;
		if (p->j[child+1].sal > p->j[child].sal){
			child++;
		}
		if (last.sal < p->j[child].sal){
			p->j[i] = p->j[child];
		}
		else{
			break;
		}
	}
	p->j[i] = last;
	return min;
}