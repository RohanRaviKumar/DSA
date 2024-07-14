#include "AVLBasic.h"

int main()
{
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
    tree=NULL;
    tree=insert(tree,15);
    tree=insert(tree,20);
    tree=insert(tree,24);
    tree=insert(tree,10);
    tree=insert(tree,13);
    tree=insert(tree,7);
    tree=insert(tree,30);
    tree=insert(tree,36);
    tree=insert(tree,25);

    printf("Level order\n");
    levelOrder(tree,-1);
}