#include<stdio.h>

//structure to store the coefficient & exponent
struct poly
{
  int coeff, expo;
};

struct poly p1[10], p2[10], p3[10];

int readPoly ();		//to read the polynomial
void displayPoly ();		//to display the polynomial
int addPoly ();			// to add the two polynomials

int
main ()
{
  int t1, t2, t3;

  t1 = readPoly (p1);
  printf ("\n First polynomials is: ");
  displayPoly (p1, t1);

  t2 = readPoly (p2);
  printf ("\n Second polynomials is: ");
  displayPoly (p2, t2);

  t3 = addPoly (p1, p2, t1, t2, p3);
  printf ("\n Sum of the polynomials is: ");
  displayPoly (p3, t3);

  return 0;
}

int
readPoly (struct poly p[])
{
  int t, i;
  printf ("Enter the no: of terms in the polynomial: ");
  scanf ("%d", &t);

  for (i = 0; i < t; i++)
    {
      printf ("\n Enter the coefficient: ");
      scanf ("%d", &p[i].coeff);

      printf ("\n Enter the exponent: ");
      scanf ("%d", &p[i].expo);

    }

  return t;
}

void
displayPoly (struct poly p[], int t)
{
  int i;
  for (i = 0; i < t - 1; i++)
    printf ("%dx^%d+ ", p[i].coeff, p[i].expo);
  printf ("%dx^%d", p[t - 1].coeff, p[t - 1].expo);
}

int
addPoly (struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[])
{
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;

  while (i < t1 && j < t2)
    {
      if (p1[i].expo == p2[j].expo)
	{
	  p3[k].expo = p1[i].expo;
	  p3[k].coeff = p1[i].coeff + p2[j].coeff;
	  i++;
	  j++;
	  k++;
	}

      else if (p1[i].expo > p2[j].expo)
	{
	  p3[k].expo = p1[i].expo;
	  p3[k].coeff = p1[i].coeff;
	  i++;
	  k++;
	}
      else
	{
	  p3[k].expo = p2[j].expo;
	  p3[k].coeff = p2[j].coeff;
	  j++;
	  k++;
	}
    }

      while (j < t2)
	{
	  p3[k].coeff = p1[i].coeff;
	  p3[k].expo = p1[i].expo;
	  i++;
	  k++;
	}

      while (j < t1)
	{
	  p3[k].coeff = p2[j].coeff;
	  p3[k].expo = p2[j].expo;
	  j++;
	  k++;
	}
    
  return k;
}
