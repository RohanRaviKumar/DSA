#include "findPath.h"

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
	printf("\nAdjacency matrix\n\n");
	display(AMat);
	printf("\n\nPath between 4 and 6 : %d\n",path(AMat,4,6));
    printf("Path between 6 and 2 : %d\n",path(AMat,6,2));
}