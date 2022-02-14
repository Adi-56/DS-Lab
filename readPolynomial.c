#include<stdio.h>

//structure to store the coefficient & exponent
struct poly
{
    int coeff,expo;
};

struct poly p[10];

int readPoly(struct poly p[]); //to read the polynomial
void displayPoly(); //to display the polynomial

int main()
{
    int t;
    t = readPoly(p);
    displayPoly(p,t);
}

int readPoly(struct poly p[10])
{
    int t,i;
    printf("Enter the no: of terms in the polynomial: ");
    scanf("%d",&t);
    
    for(i = 0;i<t;i++)
    {
        printf("\n Enter the coefficient: ");
        scanf("%d",&p[i].coeff);
        
        printf("\n Enter the exponent: ");
        scanf("%d",&p[i].expo);
        
    }
    
    return t;
}

void displayPoly(struct poly p[10], int t)
{
    int i;
    for(i = 0;i<t-1;i++)
    printf("%dx^%d+ ",p[i].coeff,p[i].expo);
    printf("%dx^%d",p[t-1].coeff,p[t-1].expo);
}
