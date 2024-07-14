#include "AVLBasic_Char.h"

int main()
{
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
    tree=NULL;
    tree=insert(tree,'H');
    tree=insert(tree,'I');
    tree=insert(tree,'J');
    tree=insert(tree,'B');
    tree=insert(tree,'A');
    tree=insert(tree,'E');
    tree=insert(tree,'C');
    tree=insert(tree,'F');
    tree=insert(tree,'D');
    tree=insert(tree,'G');
    tree=insert(tree,'K');
    tree=insert(tree,'L');
    printf("\nLevel order\n");
    levelOrder(tree,-1);

    char p = findParent(tree);
    if (p==' '){
        printf("\nTree is empty\n");
    }
    else{
        printf("\nParent of the tree is : %c\n",p);
    }

}