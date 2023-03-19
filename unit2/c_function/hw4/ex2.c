
#include <stdio.h>
int factorial(int n);

void main()
{  int x;
printf("Enter an positive integer:");
fflush(stdin);  fflush(stdout);
scanf("%d",&x);
printf("factorial of %d: %d",x,factorial(x));
}

int factorial(int n)
{
 if (n!=1)
 return  n*factorial(n-1);
}
