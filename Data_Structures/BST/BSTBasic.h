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
		search(t->right,ele);
	}
	
	else if (ele < t->data){
		search(t->left,ele);
	}
}

void levelOrder(struct tree *t, int tabs) {
	if (t == NULL){
		return;
	}
	tabs+=1;
	levelOrder(t->right, tabs);
	printf("\n");
	for (int i = 0; i < tabs; i++){
		printf("\t");
	}
	printf("%d\n", t->data);
	levelOrder(t->left, tabs);
}

int minElement(struct tree *t){
    if (t==NULL){
        return -1;
    }

    else if (t->left == NULL){
        return t->data;
    }

    else{
		minElement(t->left);
    }
}

struct tree * deleteNode(struct tree *t, int x){
	struct tree *temp;
	
	if (t==NULL){
		return NULL;
	}
	
	if (x < t->data){
		t->left = deleteNode(t->left,x);
	}

	else if (x > t->data){
		t->right = deleteNode(t->right,x);
	}

	else if (t->left && t->right){
		t->data = minElement(t->right);
		t->data=temp->data;
		t->right=deleteNode(t->right,t->data);
	}

	else{
		temp=t;
		if (t->right == NULL){
			t=t->left;
		}

		else if (t->left == NULL){
			t=t->right;
		}

		free(temp);
	}
	
	return t;
}