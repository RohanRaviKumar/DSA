#include "BSTBasic.h"

int main()
{
	struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
	tree=NULL;
	tree=insertNode(tree,29);
	tree=insertNode(tree,23);
	tree=insertNode(tree,4);
	tree=insertNode(tree,13);
	tree=insertNode(tree,39);
	tree=insertNode(tree,31);
	tree=insertNode(tree,45);
	tree=insertNode(tree,56);
	tree=insertNode(tree,49);
	printf("Inorder : ");
	inorder(tree);
	printf("\n");
	printf("Preorder : ");
	preorder(tree);
	printf("\n");
	printf("Postorder : ");
	postorder(tree);
	printf("\n\n");

	printf("\n\nTree in hierarchical form\n\n");
	levelOrder(tree,-1);
	printf("\n\n");

	printf("\nMinimum element of the tree : %d\n",minElement(tree));

	struct tree *s=search(tree,13);
	if (s!=NULL){
		printf("Element found from BST is : %d\n",s->data);
	}
	else{
		printf("Element 13 not found in BST\n");
	}
	
	struct tree *s1=search(tree,3);
	if (s1!=NULL){
		printf("Element found from BST is : %d\n",s1->data);
	}
	else{
		printf("Element 3 not found in BST\n");
	}
	tree=deleteNode(tree,49);
	printf("\n\nTree after deleting element 49\n\n");
	levelOrder(tree,-1);
	printf("\n\n");
}