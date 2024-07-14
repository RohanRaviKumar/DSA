#include <stdlib.h>
#include "queueUsingStack.h"

void  main()
{
    struct stack *s1=(struct stack *)malloc(sizeof(struct stack));
    struct stack *s2=(struct stack *)malloc(sizeof(struct stack));
    int size,choice,data;
    printf("Enter size : ");
    scanf("%d",&size);
    create(s1,size);
    create(s2,size);
    while(choice+1)
    {
        printf("\nEnter choice\n1) Enqueue\n2) Dequeue\nEnter any other number to exit : ");
        scanf("%d",&choice);
        if (choice == 1){
            printf("Enter element : ");
            scanf("%d",&data);
            enqueue(s1,s2, data);
        }

        else if (choice == 2){
            if(!queueIsEmpty(s1, s2))
                    printf("Element Removed = %d\n",dequeue(s1, s2));
            else 
                printf("QUEUE IS EMPTY");
        }
            
        else{
            break;
        }
    }
}
