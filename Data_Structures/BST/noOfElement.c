#include <stdio.h>
#include <stdlib.h>

struct tree{
	int data;
	struct tree *left, *right;
};

struct tree * insertNode(struct tree *t, int value){
	if (t==NULL){
		t=(struct tree *)malloc(sizeof(struct tree));
		t->data=value;
		t->right=NULL;
		t->left=NULL;
	}
	
	else if (value >= t->data){
		t->right=insertNode(t->right, value);
	}
	
	else if (value < t->data){
		t->left=insertNode(t->left,value);
	}
	
	return t;
}

int inorderReturn (struct tree *t, int *arr[]){
	static int c = 0;
	if (t!=NULL){
		c=inorderReturn(t->left, arr);
		arr[c++]=t->data;
		c=inorderReturn(t->right, arr);
	}
    return c;		
}

int noOfElements(struct tree *t, int low, int high){
    int a[20];
    int size = inorderReturn(t,a), count=0;
    for (int i=0; i<size; i++){
        if (a[i] > low && a[i] < high){
            count++;
        }
    }
    return count;
}

void inorder(struct tree *t){
	if (t!=NULL){
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}

int main()
{
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
	tree=NULL;
	tree=insertNode(tree,13);
	tree=insertNode(tree,18);
	tree=insertNode(tree,100);
	tree=insertNode(tree,7);
	tree=insertNode(tree,9);
    tree=insertNode(tree,89);
    int l,h;
    printf("Enter lower threshold : ");
    scanf("%d",&l);
    printf("Enter upper threshold : ");
    scanf("%d",&h);

	inorder(tree);
    printf("\nNumber of elements in the specified range : %d\n",noOfElements(tree,l,h));
}