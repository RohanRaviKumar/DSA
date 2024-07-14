#include <stdio.h>
#include <stdlib.h>

int inf = 9999;

struct table{
	int k,d,p;
};

struct connect{
	int v1,v2,w;
};

struct graph{
	int adj[100][100];
	int v,e;
	struct table t[100];
};

void create(struct graph *g, int v, int e, struct connect c[]){
	g->v = v;
	g->e = e;
	for (int i=0; i<=g->e; i++){
		g->adj[c[i].v1][c[i].v2] = c[i].w;
	}
	
	for(int i=1; i<=g->v; i++){
		g->t[i].k = 0;
		g->t[i].d = inf;
		g->t[i].p = -1;
	}
}

void displayAdj(struct graph *g){
	printf("\n\nNum of vertices : %d\n\n",g->v);
	
	for (int i=1; i<=g->v; i++){
		for (int j=1; j<=g->v; j++){
			printf("%d ",g->adj[i][j]);
		}
		printf("\n");
	}
}

int check(struct graph *g){
	for (int i=1; i<=g->v; i++){
		if (g->t[i].k == 0){
			return 1;
		}
	}
	return 0;
}

int smallest(struct graph *g){
	int j=1;
	while (g->t[j].k == 1 && j < g->v){
		j++;
	}
	int min = g->t[j].d, minv = j;
	for (int i=2; i<=g->v; i++){
		if (g->t[i].d < min && g->t[i].k==0){
			min = g->t[i].d;
			minv = i;
		}
	}
	return minv;	
}

void displayTable(struct graph *g, int s){
	printf("\nDijkstra table\n        K   D   P\n");
	for (int i=1; i<=g->v; i++){
		printf("v%d == %3d %3d %3d\n",i,g->t[i].k, g->t[i].d, g->t[i].p);
	}
}

void dijkstra(struct graph *g, int s){
	g->t[s].d = 0;
	while (check(g)){
		int v = smallest(g);
		g->t[v].k = 1;
		for (int i=1; i<=g->v; i++){
			if (g->adj[v][i] > 0 && g->t[i].k != 1){
				int cost = g->t[v].d + g->adj[v][i];
				if (cost < g->t[i].d){
					g->t[i].d = cost;
					g->t[i].p = v;
				}
			}
		}
	}
	displayTable(g,s);
}

void printPath(struct graph *g, int v1, int v2)
{
    if (v2 == 1){
        printf("%d",v2);
    }
    else{
        printPath(g,v1,g->t[v2].p);
        printf("->%d",v2);
    }
}