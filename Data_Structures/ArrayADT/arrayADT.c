#include "arrADT1.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct arr *A;
    A = (struct arr *)malloc(sizeof(struct arr));
    int arr[5] = {2,4,6,8,10};
    create(A, 5, arr);
    printf("\n\nArray elements after creation : ");
    printArray(A);
    printf("\n");
    deleteAt(A,3);
    printf("Array elements after deletion : ");
    printArray(A);
    printf("\n");
    insertAtEvery(A,1);
    printf("Array elements after inserting at every data : ");
    printArray(A);
    printf("\n\n");
    if (search(A,1)==-1){
        printf("1 was not found in the array ADT\n");
    }
    else{
        printf("1 is at the position %d of the array ADT\n",search(A,1));
    }

    if (search(A,2)==-1){
        printf("2 was not found in the array ADT\n");
    }
    else{
        printf("2 is at the position %d of the array ADT\n",search(A,2));
    }

    printf("\nArray elements : ");
    printArray(A);
    int arr1[7]={10,20,15,2,23,90,67};
    create(A,5,arr1);
    printf("\nNew array : ");
    printArray(A);
    printf("\n");
    findPeek(A);
}