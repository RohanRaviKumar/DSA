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

void inorder(struct tree *t){
	if (t!=NULL){
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}

void preorder(struct tree *t){
	if (t!=NULL){
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void postorder(struct tree *t){
	if (t!=NULL){
		postorder(t->left);
		postorder(t->right);
		printf("%d ",t->data);
	}
}

struct tree* search(struct tree *t, int ele){
	if (t==NULL){
		return NULL;
	}
	
	else if (t->data == ele){
		return t;
	}
	
	else if (ele > t->data){
		t->right=search(t->right,ele);
	}
	
	else if (ele < t->data){
		t->left=search(t->left,ele);
	}
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