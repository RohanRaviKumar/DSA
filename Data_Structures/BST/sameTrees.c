#include "sameTrees.h"

int main()
{
	struct tree *tree1 = (struct tree *)malloc(sizeof(struct tree));
	tree1=NULL;
	tree1=insertNode(tree1,4);
	tree1=insertNode(tree1,15);
	tree1=insertNode(tree1,13);
	tree1=insertNode(tree1,9);
	
	struct tree *tree2 = (struct tree *)malloc(sizeof(struct tree));
	tree2=NULL;
	tree2=insertNode(tree2,9);
	tree2=insertNode(tree2,13);
	tree2=insertNode(tree2,15);
	tree2=insertNode(tree2,4);
	//tree2=insertNode(tree2,23);
	
	printf("Inorder tree 1 : ");
	inorder(tree1);
	
	printf("\nInorder tree 2 : ");
	inorder(tree2);
	printf("\n\n");
	
	int arr1[20];
	int c1=inorderReturn(tree1, arr1, 0);
	int arr2[20];
	int c2=inorderReturn(tree2, arr2, 0);
	int check=0;
	
	if (c1 == c2){
		for (int i=0; i<c1; i++){
			if (arr1[i] != arr2[i]){
				check=-1;
				break;
			}
		}
	}
	
	else{
		check=-1;
	}
	
	if (check == -1){
		printf("Trees not same\n");
	}
	
	else{
		printf("Trees same\n");
	}
    printf("\n");
}