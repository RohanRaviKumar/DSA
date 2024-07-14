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

int inorderReturn (struct tree *t, int *arr[], int c){
	if (t!=NULL){
		c=inorderReturn(t->left, arr, c);
		arr[c]=t->data;
		c++;
		c=inorderReturn(t->right, arr, c);
	}
    return c;		
}

int sum(struct tree *t, int k){
    int a[20];
    int size = inorderReturn(t,a,0), sum=0;
    if (k>size){
        return -1;
    }
    for (int i=0; i<2*k ;i=i+2){
        printf("%d ",a[i]);
        sum+=a[i];
    }
    return sum;
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
    int k;
    printf("Enter number of elements to find the sum for : ");
    scanf("%d",&k);
    printf("\nSum of the first %d elements is : %d\n",k,sum(tree,k));
}