#include <stdio.h>
#include <stdlib.h>

void retArray(int *arr1, int n){
    for (int i=0; i<n; i++){
        arr1[i]=i+1;
    }

    return arr1;
}
int main()
{
    int arr[20];
    retArray(arr,5);
    printf("Array elements : ");
    for (int i=0; i<5; i++){
        printf("%d ",arr[i]);
    }
}