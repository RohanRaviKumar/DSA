#include "dijkstra.h"

int main()
{
	struct graph *g;
	g=(struct graph *)malloc(sizeof(struct graph));
	
	int v;
	printf("Enter no of vertices : ");
	scanf("%d",&v);
	int e;
	printf("Enter no of edges : ");
	scanf("%d",&e);
	struct connect c[e];
	for (int i=0; i<e; i++){
		printf("Enter start vertex, destination and weight of edge\n");
		scanf("%d%d%d",&c[i].v1,&c[i].v2,&c[i].w);
	}
	create(g,v,e,c);
	displayAdj(g);
	dijkstra(g,1);
    int d;
    printf("\n\nEnter destination to display the path for : ");
    scanf("%d",&d);
    printPath(g,1,d);
    printf("\n");
}