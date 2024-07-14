#include "linkedList_appl.h"

int main()
{
	struct node *header;
	header=(struct node *)malloc(sizeof(struct node));
	create(header);
	printf("\nLength of the list : %d",length(header));
	insertAtFront(header,2);
	insertAtFront(header,4);
	insertAtFront(header,6);
	insertAtFront(header,8);
	printf("\nLength of the list : %d",length(header));
	insertAtEnd(header,1);
	insertAtEnd(header,3);
	insertAtFront(header,7);
	printf("\nLength of the list : %d\n",length(header));

	printf("\nList elements after inserting at front and end : ");
	display(header);

	int mid=findMiddleElt(header);
	printf("\nThe middle element is : %d\n",mid);

	reverse(header);
	printf("\nLinked list after reversal : ");
	display(header);

	if (searchElt(header,4)!=-1){
		printf("\nElement found was %d\n",searchElt(header,4));
	}
	else{
		printf("\nElement 4 was not found\n");
	}

	if (searchElt(header,5)!=-1){
		printf("\nElement found was %d\n",searchElt(header,5));
	}
	else{
		printf("\nElement 5 was not found\n");
	}

	if (searchElt(header,2)!=-1){
		printf("\nElement found was %d\n",searchElt(header,2));
	}
	else{
		printf("\nElement 2 was not found\n");
	}
	
	delete(header,2);
	printf("\nLinked list elements after deletion : ");
	display(header);

	if (detectLoop(header)){
        printf("\nList is corrupted\n\n");
    }
    else{
        printf("\nList is not corrupted\n\n");
    }
}