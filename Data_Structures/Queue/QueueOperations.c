#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct job{
    char jobID[100];
    int time;
};

struct queue{
    struct job j[100];
    int r,f,size;
};

void create(struct queue *q, int limits){
    q->size=limits;
    q->f=-1;
    q->r=-1;   
}

void enqueue(struct queue *q, struct job j){
    if (q->f==-1 && q->r==-1){
        q->f++;
        q->r++;
        q->j[q->r].time=j.time;
        strcpy(q->j[q->r].jobID, j.jobID);
    }

    else if ((q->r+1)%(q->size) == q->f){
        printf("The queue is full. Cannot push\n");
    }

    else{
        q->r=(q->r+1)%(q->size);
        q->j[q->r].time=j.time;
        strcpy(q->j[q->r].jobID, j.jobID);
    }
}

struct job dequeue(struct queue *q){
    struct job d;
    if (q->f == -1 && q->r==-1){
        struct job temp;
        temp.time=0;
        strcpy(temp.jobID,"\0");
        return temp;
    }

    else if(q->f == q->r){
        d=q->j[q->f];
        q->f=-1;
        q->r=-1;
        return d;
    }

    else{
        d=q->j[q->f];
        q->f = (q->f +1)%(q->size);
        return d;
    }
}

void display(struct queue *q){
    if (q->r < q->f){
        for (int i=q->f; i<q->size; i++){
            printf("(%s,%d)  ",q->j[i].jobID, q->j[i].time);
        }

        for (int i=0; i<q->r; i++){
            printf("(%s,%d)  ",q->j[i].jobID, q->j[i].time);
        }
    }

    else{
        for (int k=q->f; k<q->r; k++){
            printf("(%s,%d)  ",q->j[k].jobID, q->j[k].time);
        }
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    create(q,3);
    struct job job=dequeue(q);
    struct job t;
    strcpy(t.jobID,"J1");
    t.time=2;
    enqueue(q,t);
    printf("\nQueue : ");
    display(q);

    strcpy(t.jobID,"J2");
    t.time=13;
    enqueue(q,t);
    printf("\nQueue : ");
    display(q);

    strcpy(t.jobID,"J3");
    t.time=5;
    enqueue(q,t);
    printf("\nQueue : ");
    display(q);

    struct job j=dequeue(q);
    printf("\nQueue : ");
    display(q);
}
