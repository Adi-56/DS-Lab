//MUHAMMED SAIF V P 42 
//TLY20CS042 
//01-02-2022
// IMPLEMENTATION OF SELECTION SORT

#include <stdio.h> 
int main() 
{ 
    int a[100], n, i, j, position, swap;         
    printf("Enter number of elements : ");     
    scanf("%d", &n); 
    printf("Enter %d Numbers: " ); 
    for (i = 0; i < n; i++) 
          scanf("%d", &a[i]); 
    for(i = 0; i < n - 1; i++)
    { 
         position=i;
         for(j = i + 1; j < n; j++) 
         {
              if(a[position] > a[j])
                 position=j;
         } 
         if(position != i) 
         { 
              swap=a[i];
             a[i]=a[position];
             a[position]=swap;
         } 
   } 
   printf("Sorted Array: ");
   for(i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0; 
}
