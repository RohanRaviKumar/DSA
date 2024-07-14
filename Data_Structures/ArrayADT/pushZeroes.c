#include <stdio.h>
#include <stdlib.h>

struct arr {
    int size;
    int a[100];
};

void create(struct arr *p, int s, int arr[])
{
    p->size = s;
    for (int i = 0; i < p->size; i++) {
        p->a[i] = arr[i];
    }
}

void printArray(struct arr *p)
{
    for (int i = 0; i < p->size; i++) {
        printf("%d ", p->a[i]);
    }
}

struct arr * sepZeroes(struct arr *a1){
    struct arr* b=(struct arr *)malloc(sizeof(struct arr));
    int arr[11]={0};
    int j=0, zeroes=0;
    for (int i=0;i<a1->size;i++){
        if (a1->a[i] == 0){
            zeroes++;
        }
        else{
            arr[j]=a1->a[i];
            j++;
        }
    }

    for (int k=j;k<j+zeroes;k++){
        arr[k]=0;
    }
    create(b,a1->size,arr);
    return b;
}

int main()
{
    struct arr* a=(struct arr *)malloc(sizeof(struct arr));
    int sampleArr[11]={1,9,8,4,0,0,2,7,0,6,0};
    create(a,11,sampleArr);
    printf("Original array : ");
    printArray(a);
    a=sepZeroes(a);
    printf("\nArray after splitting zeroes : ");
    printArray(a);
}