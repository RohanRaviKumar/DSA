#include <stdio.h>
#include <stdlib.h>

struct poly{
    int coeff;
    int exp;
    struct poly *next;
};

void polyCreate(struct poly *p, int c, int e)
{
    struct poly *p1=(struct poly *)malloc(sizeof(struct poly));
    p1->coeff=c;
    p1->exp=e;
    p1->next=NULL;
    struct poly *last=p;
    while (last->next!=NULL){
        last=last->next;
    }
    last->next=p1;
}

void displayPoly(struct poly *p){
    struct poly *ptr;
    ptr=p->next;
    while (ptr->next!=NULL){
        printf("%dx^%d + ",ptr->coeff,ptr->exp);
        ptr=ptr->next;
    }

    printf("%d",ptr->coeff);
}

struct poly * addPoly(struct poly *p1, struct poly *p2){
    struct poly *ptr1=p1->next;
    struct poly *ptr2=p2->next;
    struct poly *ans = (struct poly *)malloc(sizeof(struct poly));
    ans->next=NULL;
    while (ptr1!=NULL && ptr2!=NULL){
        if (ptr1->exp >  ptr2->exp){
            polyCreate(ans,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }

        else if (ptr1->exp < ptr2->exp){
            polyCreate(ans,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }

        else if (ptr1->exp == ptr2->exp){
            polyCreate(ans,ptr1->coeff + ptr2->coeff,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }

    while (ptr1!=NULL){
        polyCreate(ans,ptr1->coeff,ptr1->exp);
        ptr1=ptr1->next;
    }
    while (ptr2!=NULL){
        polyCreate(ans,ptr2->coeff,ptr2->exp);
        ptr2=ptr2->next;
    }
    return ans;

}

int main()
{
    int n1,n2,coeff=-1,exp=-1;
    struct poly *p1,*p2,*ans;
    p1=(struct poly *)malloc(sizeof(struct poly));
    p1->next=NULL;
    printf("\n\n---------------Polynomial 1-----------------\n\n");
    while (exp!=0){
        printf("\n\nEnter the co-efficient of the term : ");
        scanf("%d",&coeff);
        printf("Enter the exponent of the term : ");
        scanf("%d",&exp);
        polyCreate(p1,coeff,exp);
    }

    p2=(struct poly *)malloc(sizeof(struct poly));
    p2->next=NULL;
    exp=-1;
    printf("\n\n-----------Polynomial 2-------------\n\n");
    while (exp!=0){
        printf("\n\nEnter the co-efficient of the term : ");
        scanf("%d",&coeff);
        printf("Enter the exponent of the term : ");
        scanf("%d",&exp);
        polyCreate(p2,coeff,exp);
    }

    printf("\n\nPolynomial 1 : ");
    displayPoly(p1);
    printf("\n\nPolynomial 2 : ");
    displayPoly(p2);
    printf("\n\n");
    ans=(struct poly *)malloc(sizeof(struct poly));
    ans=addPoly(p1,p2);
    printf("The addition of the polynomials is : ");
    displayPoly(ans);
    printf("\n\n");
}