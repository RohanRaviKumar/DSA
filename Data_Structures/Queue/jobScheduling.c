#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct job{
    char ID[20];
    int time;
};

struct queue{
    struct job j[100];
    int size,f,r;
};

void create(struct queue *q, int limit){
    q->size=limit;
    q->f=-1;
    q->r=-1;
}

int isEmpty(struct queue *q){
    if (q->f==-1 && q->r==-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, struct job j){
    if (isEmpty(q)){
        q->f=0;
        q->r=0;
        q->j[q->r]=j;
    }
    
    else if (q->r == q->size+1){
        printf("Queue is full. Cannot enqueue\n");
    }
    
    else{
        q->j[++(q->r)]=j;
    }
}

struct job dequeue(struct queue *q){
    if (isEmpty(q)){
        struct job temp;
        strcpy(temp.ID,"\0");
        temp.time=0;
        return temp;
    }
    
    else if (q->f == q->r){
        struct job temp=q->j[q->f];
        q->f++;
        return temp;
    }

    else{
        struct job temp = q->j[q->f];
        q->f++;
        return temp;
    }
}

struct job peek(struct queue *q){
    if (isEmpty(q)){
        struct job temp;
        strcpy(temp.ID,"\0");
        temp.time=0;
        return temp;
    }
    
    else{
        return q->j[q->f];
    }
}

int burstTime(struct queue *q){
    int sum=0;
    if (isEmpty(q)){
        return 0;
    }
    else{
        for (int i=q->f; i<(q->r)+1; i++){
            sum=sum+(q->j[i].time);
        }
        return sum;
    }
}

void display(struct queue *q){
    int j=1;
    for (int i=q->f; i<q->r+1; i++){
 printf("%d)  Job ID : %s\n    Waiting time : %d\n\n",j,q->j[i].ID,q->j[i].time);
        j++;
    }
    printf("Total burst time : %d\n\n",burstTime(q));
}

int main()
{
    struct queue *c1=(struct queue *)malloc(sizeof(struct queue));
    struct queue *c2=(struct queue *)malloc(sizeof(struct queue));
    create(c1,5);
    create(c2,5);
    struct job sample;
    for (int i=0; i<10; i++){
        printf("Enter job ID : ");
        fflush(stdin);
        scanf("%s",sample.ID);
        printf("Enter burst time : ");
        fflush(stdin);
        scanf("%d",&(sample.time));
        if (isEmpty(c1)){
            enqueue(c1,sample);
        }
        
        else if (isEmpty(c2)){
            enqueue(c2,sample);
        }
        
        else{
            if (burstTime(c1) > burstTime(c2)){
                enqueue(c2,sample);
            }
            else if (burstTime(c1) < burstTime(c2)){
                enqueue(c1,sample);
            }
            
            else{
                enqueue(c1,sample);
            }
        }
        printf("\n\n");
    }
    printf("\n\n==========Queue 1===========\n\n");
    display(c1);
    printf("\n\n==========Queue 2===========\n\n");
    display(c2);
}    
