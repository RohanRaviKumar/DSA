#include "dijkstra2.h"

int main(){
	int ed,v,w;
	struct edgePairs e[100];
	printf("Enter no.of Edges: ");
	scanf("%d",&ed);
	printf("\nEnter no.of vertices: ");
	scanf("%d",&v);
	for(int i=1;i<=ed;i++){
		printf("Enter start: ");
		scanf("%d",&e[i].f);
		printf("Enter end: ");
		scanf("%d",&e[i].t);
		printf("Enter Distance between the 2 vertex: ");
		scanf("%d",&e[i].w);
		printf("\n");
	}
	struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
	create(G,v,ed,e);
	display(G);
	dijkstras(G,1);
	printf("\n\nPath from 1 to 6 : ");
	printPath(G,1,6);
	return 0;
}