#include <stdio.h>
#include <stdlib.h>

struct tree {
    int height;
    char data;
    struct tree *left, *right;
};

int height(struct tree *t){
    if (t==NULL){
        return -1;
    }

    else{
        return t->height;
    }
}

int max(int n1, int n2){
    if (n1>n2){
        return n1;
    }
    return n2;
}

struct tree * singleRotateWithLeft(struct tree *k2){
    struct tree *k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height = max(height(k2->left), height(k2->right))+1;
    k1->height = max(height(k1->left), height(k1->right))+1;
    return k1;
}

struct tree * singleRotateWithRight(struct tree *k1){
    struct tree *k2;
    k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    return k2;
}

struct tree *leftSubtreeOfRight (struct tree *k3){
    k3->right = singleRotateWithLeft(k3->right);
    return singleRotateWithRight(k3);
}

struct tree *rightSubtreeOfLeft(struct tree *k3){
    k3->left = singleRotateWithRight(k3->left);
    return singleRotateWithLeft(k3);
}

struct tree *insert(struct tree *t, char x)
{
    if (t==NULL){
        t=(struct tree *)malloc(sizeof(struct tree));
        t->data=x;
        t->height=0;
        t->left = t->right = NULL;
    }

    else if (x<t->data){
        t->left = insert(t->left,x);
        if (height(t->left) - height(t->right) == 2){
            if (x<t->left->data){
                t=singleRotateWithLeft(t);
            }
            else{
                t=rightSubtreeOfLeft(t);
            }
        }
    }

    else if (x > t->data){
        t->right = insert(t->right,x);
        if (height(t->right) - height(t->left) == 2){
            if (x > t->right->data){
                t=singleRotateWithRight(t);
            }
            else{
                t=leftSubtreeOfRight(t);
            }
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
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
	printf("%c\n", t->data);
	levelOrder(t->left, tabs+1);
}

char findParent(struct tree *t){
    
}

