#include "maxBinHeapBasic.h"

int main()
{
    struct PQ *heap = (struct PQ *)malloc(sizeof(struct PQ));
	init(heap);
	insert(heap,14);
	insert(heap,16);
	insert(heap,22);
	insert(heap,11);
	insert(heap,9);
	insert(heap,18);
	insert(heap,10);
	insert(heap,7);
	insert(heap,4);
	insert(heap,1);
	print(heap);
	printf("\nDeleted element from heap : %d",deleteMax(heap));
	print(heap);
	printf("\n\n");

	return 0;
}