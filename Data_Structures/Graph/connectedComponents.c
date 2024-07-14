#include "connectedComponents.h"

int main()
{
	struct AM *AMat;
	AMat = (struct AM *)malloc(sizeof(struct AM));
	int n;
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	create(AMat,n);
	int e;
	printf("Enter number of edges : ");
	scanf("%d",&e);
	int c;
	for (int i=0; i<e; i++){
		printf("Enter the connected vertices : ");
		scanf("%d",&c);
		connect(AMat,c/10,c%10);
	}
	printf("\nConnected Components : ");
	DFS(AMat,0);
	printf("\n");
}