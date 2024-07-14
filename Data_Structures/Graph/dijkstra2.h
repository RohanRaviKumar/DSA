#include <stdio.h>
#include <stdlib.h>

struct table{
	int k,d,p;
};

struct Graph{
	int adj[10][10];
	int v,e;
	struct table t[10];
};

struct edgePairs{
	int f, t;
	int w;
};

void create(struct Graph *G, int v, int e, struct edgePairs edge[]){
	G->v=v;
	G->e=e;

	for(int i=1;i<=G->e;i++){
		G->adj[edge[i].f][edge[i].t]=edge[i].w;
	}

	for(int i=1;i<=G->v;i++){
		G->t[i].k=0;
		G->t[i].d=99999;
		G->t[i].p=-1;
	}
}

void display(struct Graph *G){
	for(int i=1;i<=G->v;i++){
		for(int j=1;j<=G->v;j++){
			printf("%d  ",G->adj[i][j]);
		}
		printf("\n");
	}
}

int check(struct Graph *G){
	for(int i=1;i<=G->v;i++){
		if(G->t[i].k==0)
			return 1;
	}
	return 0;
}

int smallest(struct Graph *G){
	int j=1;
	while(G->t[j].k==1 && j<G->v){
		j++;
	}
	int min=G->t[j].d;
	int vertex=j;
	for(int i=j;i<=G->v;i++){
		if((min>G->t[i].d)&&(G->t[i].k==0)){
			min=G->t[i].d;
			vertex=i;
		}
	}
	return vertex;
}

void displayTable(struct Graph *G){
	printf("\n\n      \tK\t    D\t    P \n");
	for(int i=1; i<=G->v;i++){
		printf("%d\t%d\t%d\t%d \n",i,G->t[i].k,G->t[i].d,G->t[i].p);
	}
}

void dijkstras(struct Graph *G, int s){
	G->t[s].d=0;
	while(check(G) == 1){
		int v=smallest(G);
		G->t[v].k=1;
		for(int i=1; i<=G->v;i++){
			if((G->adj[v][i] > 0)&&(G->t[i].k != 1)){
				int cost = G->t[v].d + G->adj[v][i]
				if(G->t[i].d > cost){
					G->t[i].d = cost;
					G->t[i].p=v;
				}
			}
		}
	}
	displayTable(G);
}

void printPath(struct Graph *g, int v1, int v2)
{
    if (v2 == v1){
        printf("%d",v2);
    }
    else{
        printPath(g,v1,g->t[v2].p);
        printf("->%d",v2);
    }
}