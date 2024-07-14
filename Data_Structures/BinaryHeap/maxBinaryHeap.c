#include "maxBinaryHeap.h"

int main()
{
	struct PQ *max = (struct PQ *)malloc(sizeof(struct PQ));
	init(max);
	struct job j1 = {'A',15000};
	insert(max,j1);
	struct job j2 = {'K',12000};
	insert(max,j2);
	struct job j3 = {'R',4000};
	insert(max,j3);
	struct job j4 = {'T',3500};
	insert(max,j4);
	struct job j5 = {'L',4600};
	insert(max,j5);
	struct job j6 = {'P',6000};
	insert(max,j6);
	struct job j7 = {'Y',8600};
	insert(max,j7);
	print(max);
	struct job del1=deleteMax(max);
	printf("\nDeleted job record\nID : %c\nSalary : %d\n",del1.ID,del1.sal);
	struct job del2=deleteMax(max);
	printf("\nDeleted job record\nID : %c\nSalary : %d\n",del2.ID,del2.sal);
	struct job del3=deleteMax(max);
	printf("\nDeleted job record\nID : %c\nSalary : %d\n",del3.ID,del3.sal);
	struct job del4=deleteMax(max);
	printf("\nDeleted job record\nID : %c\nSalary : %d\n",del4.ID,del4.sal);
	struct job del5=deleteMax(max);
	printf("\nDeleted job record\nID : %c\nSalary : %d\n",del5.ID,del5.sal);
	struct job del6=deleteMax(max);
	printf("\nDeleted job record\nID : %c\nSalary : %d\n",del6.ID,del6.sal);
	struct job del7=deleteMax(max);
	printf("\nDeleted job record\nID : %c\nSalary : %d\n",del7.ID,del7.sal);
}